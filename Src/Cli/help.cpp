#include "help.h"

void CliHelp::help(){

    cout << "Usage: altparser [options...] [branches...] \n";
    cout << "-o <file> \t Out results to file \n";
    cout << "-h \t\t Get help for commands \n";
    exit(0);    
}