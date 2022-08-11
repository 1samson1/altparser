#include "package.h"

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

string Package::getVersion()
{
    return this->version.get();
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
    return this->version > other.version;
}
