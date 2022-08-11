#include "differ.h"

#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace LibAltParser;
using json = nlohmann::json;

Differ::Differ(string filepath1, string filepath2){

    this->onlyFirstExistPkgs = this->getPackeges(filepath1);
    this->onlySecondExistPkgs = this->getPackeges(filepath2);

}

list<Package>* Differ::getPackeges(string filepath)
{
    auto pkgs = new list<Package>;
    json data;

    ifstream fin(filepath);    
    if(fin.is_open())
    {
        data = (json::parse(fin))["packages"];
    }
    fin.close();

    for (auto &el : data)
    {
        pkgs->push_back(Package (el));
    }    

    return pkgs;
}

void Differ::diff()
{        
    this->upperFirstPkgs = new list<Package>;

    for(auto pkg1 = this->onlyFirstExistPkgs->begin(); pkg1 != this->onlyFirstExistPkgs->end() ; ++pkg1)
    {
        // Find package in second branch
        auto find_result = find_if(
            this->onlySecondExistPkgs->begin(),
            this->onlySecondExistPkgs->end(),
            [&pkg1](Package pkg2) -> bool
            {
                return pkg2 == *pkg1;
            }
        );

        if(find_result != this->onlySecondExistPkgs->end())
        {
            if(*pkg1 > *find_result){
                this->upperFirstPkgs->push_back(*pkg1);
            } 

            pkg1 = (this->onlyFirstExistPkgs->erase(pkg1));
            pkg1--;

            this->onlySecondExistPkgs->erase(find_result);
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

    for (auto &pkg : *this->upperFirstPkgs)
    {
        data["upperFirstPkgs"].push_back(pkg.toJSON());
    }    

    return data.dump(indent);
}

Differ::~Differ()
{
    delete this->onlyFirstExistPkgs;
    this->onlyFirstExistPkgs = nullptr;

    delete this->onlySecondExistPkgs;
    this->onlySecondExistPkgs = nullptr;
}


