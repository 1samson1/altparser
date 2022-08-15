#include "differ.h"

#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace LibAltParser;
using json = nlohmann::json;

Differ::Differ(string filepath1, string filepath2){

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

list<Package>* Differ::getListPackeges(string filepath)
{
    auto pkgs = new list<Package>;
    
    auto data = this->getPackages(filepath);

    for (auto &el : data)
    {
        pkgs->push_back(Package (el));
    }    

    return pkgs;
}

map<string, Package>* Differ::getMapPackeges(string filepath)
{
    auto pkgs = new map<string, Package>;

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
    this->onlyFirstExistPkgs = new list<Package>;
    this->onlySecondExistPkgs = new list<Package>;    
    this->freshFirstPkgs = new list<Package>;


    for(auto &it : *this->firstBranchPkgs)
    {

        // Find package in second branch
        auto find_result = this->secondBranchPkgs->find(it.second.getHash());        

        if(find_result != this->secondBranchPkgs->end())
        {
            if(it.second.isFresh(find_result->second)){
                this->freshFirstPkgs->push_back(it.second);
            }
        } 
        else 
        {   
            this->onlyFirstExistPkgs->push_back(it.second);
        }       
    }
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
    delete this->onlyFirstExistPkgs;
    this->onlyFirstExistPkgs = nullptr;

    delete this->onlySecondExistPkgs;
    this->onlySecondExistPkgs = nullptr;
}


