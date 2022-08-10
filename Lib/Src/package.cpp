#include "package.h"

#include <iostream>

using namespace std;
using namespace LibAltParser;
using json = nlohmann::json;

Package::Package(json &obj)
{
    this->arch = obj["arch"].get<string>();
    this->buildtime = obj["buildtime"].get<int>();
    this->disttag = obj["disttag"].get<string>();
    this->epoch = obj["epoch"].get<int>();
    this->name = obj["name"].get<string>();
    this->release = obj["release"].get<string>();
    this->source = obj["source"].get<string>();
    this->version = obj["version"].get<string>();
}

string Package::getName()
{
    return this->name;
}

string Package::getVersionWithoutDot()
{
    string temp_version = this->version;

    temp_version.erase(
        remove(temp_version.begin(), temp_version.end(), '.'),
        temp_version.end()
    );

    return temp_version;
}

bool Package::operator== (Package &other)
{
    return 
        this->arch == other.arch &&        
        this->name == other.name
    ;
}

bool Package::operator> (Package &other)
{
    int size;
    string v1 = this->getVersionWithoutDot();
    string v2 = other.getVersionWithoutDot();

    if(v1.size() < v2.size())
    {
        size = v1.size();
    }
    else 
    {
        size = v2.size();
    }

    for (int i = 0; i < size; i++)
    {
        if(v1[i] > v2[i]){
            return true;
        }
        if(v1[i] < v2[i]){
            return false;
        }
    }    

    return false;
}
