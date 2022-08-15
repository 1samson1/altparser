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

// Methods

string Package::getName()
{
    return this->name;
}

string Package::getVersion()
{
    return this->version.get();
}

json Package::toJSON()
{
    json data;

    data["arch"] = this->arch;
    data["buildtime"] = this->buildtime;
    data["disttag"] = this->disttag;
    data["epoch"] = this->epoch;
    data["name"] = this->name;
    data["release"] = this->release;
    data["source"] = this->source;
    data["version"] = this->version.get();

    return data;
}

bool Package::isFresh (Package &other)
{
    return this->version > other.version &&
        this->epoch >= other.epoch;
}

string Package::getHash()
{
    return this->name + "_" + this->arch;
}

// Operators

bool Package::operator== (Package &other)
{
    return 
        this->arch == other.arch &&        
        this->name == other.name
    ;
}
