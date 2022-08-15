#ifndef LIB_AP_DIFFER_H
#define LIB_AP_DIFFER_H

#include <string>
#include <list>
#include <map>
#include "package.h"



namespace LibAltParser {

    typedef std::map<std::string, Package> mapPkg_t;
    typedef std::list<Package> listPkg_t;

    class Differ
    {
    private:
        mapPkg_t* firstBranchPkgs;
        mapPkg_t* secondBranchPkgs;

        listPkg_t* onlyFirstExistPkgs;
        listPkg_t* onlySecondExistPkgs;
        listPkg_t* freshFirstPkgs;

    public:

        Differ(std::string filepath1, std::string filepath2);
        nlohmann::json getPackages(std::string filepath);
        listPkg_t* getListPackeges(std::string filepath);
        mapPkg_t* getMapPackeges(std::string filepath);

        void diff();
        std::pair<listPkg_t *,listPkg_t*> diff_branch(mapPkg_t * const branch1, mapPkg_t * const branch2);

        std::string getStructJSON(int indent = 0);

        ~Differ();
    };
}

#endif
