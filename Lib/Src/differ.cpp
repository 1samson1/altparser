#include "differ.h"

#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace LibAltParser;
using json = nlohmann::json;

Differ::Differ(string filepath1, string filepath2){

    this->branch1_pkgs = this->getPackeges(filepath1);
    this->branch2_pkgs = this->getPackeges(filepath2);

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

    for (auto it = data.begin(); it != data.end(); it++)
    {
        pkgs->push_back(Package (*it));
    }    

    return pkgs;
}

void Differ::diff()
{
 
    
}

Differ::~Differ()
{
    delete this->branch1_pkgs;
    this->branch1_pkgs = nullptr;

    delete this->branch2_pkgs;
    this->branch2_pkgs = nullptr;
}


