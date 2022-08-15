#include "differ.h"

#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace LibAltParser;
using json = nlohmann::json;

Differ::Differ(string filepath1, string filepath2)
{
    
    this->firstBranchPkgs = this->getMapPackeges(filepath1);
    this->secondBranchPkgs = this->getMapPackeges(filepath2);

}

json Differ::getPackages(string filepath)
{
    json data;

    ifstream fin(filepath);    
    if(fin.is_open())
    {
        data = (json::parse(fin))["packages"];
    }
    fin.close();

    return data;
}

listPkg_t* Differ::getListPackeges(string filepath)
{
    auto pkgs = new listPkg_t;
    
    auto data = this->getPackages(filepath);

    for (auto &el : data)
    {
        pkgs->push_back(Package (el));
    }    

    return pkgs;
}

mapPkg_t* Differ::getMapPackeges(string filepath)
{
    auto pkgs = new mapPkg_t;

    auto data = this->getPackages(filepath);
    
    for (auto &el : data)
    {
        Package temp(el);

        pkgs->emplace(temp.getHash(), temp);
    }    

    return pkgs;
}

void Differ::diff()
{
    auto firstBranchResult = this->diff_branch(
        this->firstBranchPkgs,
        this->secondBranchPkgs
    );

    auto secondBranchResult = this->diff_branch(
        this->secondBranchPkgs,
        this->firstBranchPkgs
    );

    // First branch
    this->onlyFirstExistPkgs = firstBranchResult.first;
    this->freshFirstPkgs = firstBranchResult.second;

    // Second branch
    this->onlySecondExistPkgs = secondBranchResult.first;

}

pair<listPkg_t *,listPkg_t*> Differ::diff_branch(mapPkg_t * const branch1, mapPkg_t * const branch2)
{        
    listPkg_t * onlyFirstExistPkgs = new listPkg_t;
    listPkg_t * freshFirstPkgs = new listPkg_t;

    for(auto &it : *branch1)
    {

        // Find package in second branch
        auto find_result = branch2->find(it.second.getHash());        

        if(find_result != branch2->end())
        {
            if(it.second.isFresh(find_result->second)){
                freshFirstPkgs->push_back(it.second);
            }
        } 
        else 
        {   
            onlyFirstExistPkgs->push_back(it.second);
        }       
    }

    return make_pair(onlyFirstExistPkgs, freshFirstPkgs);
}

string Differ::getStructJSON(int indent){
    json data;

    for (auto &pkg : *this->onlyFirstExistPkgs)
    {
        data["onlyFirstExistPkgs"].push_back(pkg.toJSON());
    }

    for (auto &pkg : *this->onlySecondExistPkgs)
    {
        data["onlySecondExistPkgs"].push_back(pkg.toJSON());
    }

    for (auto &pkg : *this->freshFirstPkgs)
    {
        data["freshFirstPkgs"].push_back(pkg.toJSON());
    }    

    if( indent != 0)
    {
        return data.dump(indent);
    }

    return data.dump();
}

Differ::~Differ()
{
    delete this->firstBranchPkgs;
    this->firstBranchPkgs = nullptr;

    delete this->secondBranchPkgs;
    this->secondBranchPkgs = nullptr;
}


