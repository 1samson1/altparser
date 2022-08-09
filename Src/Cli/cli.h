#ifndef CLI_H
#define CLI_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "download.h"
#include "help.h"

using namespace std;

class Cli {

private:
    vector<string> branches;
    bool outfile = false;
    string outfilename;

    void parsArgs(int argc, char **argv);
    void downloadCache();

public:
    Cli(int argc, char ** argv);
    ~Cli();
};

#endif
