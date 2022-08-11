#ifndef LIB_VERSION_H
#define LIB_VERSION_H

#include <string>
#include <vector>

namespace LibAltParser {

    class Version
    {
    private:
        std::string version;        

        std::vector<std::string> splitVersion();
        int countPointPart(std::string part);

    public:
        Version();
        Version(std::string version);       

        std::string get();

        bool operator>(Version &other);

        ~Version(){};
    };

}

#endif
