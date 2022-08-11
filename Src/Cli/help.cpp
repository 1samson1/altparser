#include "help.h"

void CliHelp::help(){

    cout << "Usage: altparser [options...] <branch1> <branch2> \n";
    cout << "-h  Get help for commands \n";
    cout << "-o <file>  Out results to file \n";
    cout << "--cache  Not download branches, use cache \n";
    cout << "--indent <count>  Add space indent to out \n";
    exit(0);    
}