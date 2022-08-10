#ifndef CLI_H
#define CLI_H

#include <string>
#include <iostream>
#include <vector>

class Cli {

private:
    std::vector<std::string> branches;
    std::string outfilename;
    bool outfile = false;
    bool usecache = false;

    void parsArgs(int argc, char **argv);
    void downloadCache();

public:
    Cli(int argc, char ** argv);
    ~Cli();
};

#endif
