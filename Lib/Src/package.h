#ifndef LIB_PACKAGE_H
#define LIB_PACKAGE_H

#include "version.h"

#include <string>
#include <nlohmann/json.hpp>

namespace LibAltParser
{
    class Package
    {
    private:
        std::string arch;
        int buildtime;
        std::string disttag;
        int epoch;
        std::string name;
        std::string release;
        std::string source;
        Version version;

    public:
        Package(){};
        Package(nlohmann::json &obj);

        std::string getName();  
        std::string getVersion();
        nlohmann::json toJSON();

        bool operator== (Package &other);
        bool operator> (Package &other);


        ~Package(){};
    };
}

#endif
