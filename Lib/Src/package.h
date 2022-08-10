#ifndef LIB_PACKAGE_H
#define LIB_PACKAGE_H

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
        std::string version;
    
    public:
        Package(){};
        Package(nlohmann::json &obj);

        std::string getName();
        std::string getVersionWithoutDot();

        bool operator== (Package &other);
        bool operator> (Package &other);


        ~Package(){};
    };
}

#endif
