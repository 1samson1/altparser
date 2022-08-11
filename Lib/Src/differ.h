#ifndef LIB_AP_DIFFER_H
#define LIB_AP_DIFFER_H

#include <string>
#include <list>

#include "package.h"

namespace LibAltParser {

    class Differ
    {
    private:
        std::list<Package>* onlyFirstExistPkgs;
        std::list<Package>* onlySecondExistPkgs;
        std::list<Package>* upperFirstPkgs;

    public:

        Differ(std::string filepath1, std::string filepath2);

        std::list<Package>* getPackeges(std::string filepath);
        std::string getStructJSON();

        void diff();

        ~Differ();
    };
}

#endif
