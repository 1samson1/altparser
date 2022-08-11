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
    std::vector<std::string> getPaths();
    void downloadCache(std::vector<std::string> paths);
    std::string diff(std::vector<std::string>);

public:
    Cli(int argc, char ** argv);

    void tofile(std::string filename, std::string data);

    ~Cli(){};
};

#endif
