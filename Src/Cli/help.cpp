#include "help.h"

void CliHelp::help(){

    cout << "Usage: altparser [options...] <branch1> <branch2> \n";
    cout << "-h \t\t Get help for commands \n";
    cout << "-o <file> \t Out results to file \n";
    cout << "--cache \t Not download branches, use cache \n";
    exit(0);    
}