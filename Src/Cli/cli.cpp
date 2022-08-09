#include "cli.h"


Cli::Cli(int argc, char **argv){
    
    for (int i = 1; i < argc; i++){        
        string arg(argv[i]);

        if(arg == "-o"){
            string temp_arg(argv[i+1]);

            this->outfilename = temp_arg;
            
            i++;
            continue;
        }

        if(arg == "-h"){
            CliHelp::help();
        }

        this->branches.push_back(arg);
    }

    if (this->branches.size() == 0){
        cout << "No enter branches" << endl;
        exit(1);
    }    
}

Cli::~Cli(){
    
}
