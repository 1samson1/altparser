#ifndef CLI_H
#define CLI_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "help.h"

using namespace std;

class Cli {

private:
    vector<string> branches;
    bool outfile = false;
    string outfilename;

public:
    Cli(int argc, char ** argv);
    ~Cli();
};

#endif
