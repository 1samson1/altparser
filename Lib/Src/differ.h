#ifndef LIB_AP_DIFFER_H
#define LIB_AP_DIFFER_H

#include <string>
#include <list>
#include <map>

#include "package.h"

namespace LibAltParser {

    class Differ
    {
    private:
        std::map<std::string, Package>* firstBranchPkgs;
        std::map<std::string, Package>* secondBranchPkgs;

        std::list<Package>* onlyFirstExistPkgs;
        std::list<Package>* onlySecondExistPkgs;
        std::list<Package>* freshFirstPkgs;

    public:

        Differ(std::string filepath1, std::string filepath2);
        nlohmann::json getPackages(std::string filepath);
        std::list<Package>* getListPackeges(std::string filepath);
        std::map<std::string, Package>* getMapPackeges(std::string filepath);

        std::string getStructJSON(int indent = 0);

        void diff();

        ~Differ();
    };
}

#endif
