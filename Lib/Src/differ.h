#ifndef LIB_AP_DIFFER_H
#define LIB_AP_DIFFER_H

#include <string>
#include <list>

#include "package.h"

namespace LibAltParser {

    class Differ
    {
    private:
        std::list<Package>* branch1_pkgs;
        std::list<Package>* branch2_pkgs;

    public:
        std::list<Package>* getPackeges(std::string filepath);

        Differ(std::string filepath1, std::string filepath2);

        void diff();

        ~Differ();
    };
}

#endif
