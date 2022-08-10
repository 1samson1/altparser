#include "cli.h"

#include "help.h"
#include "download.h"

using namespace std;

Cli::Cli(int argc, char **argv)
{
    this->parsArgs(argc, argv);

    if(!this->usecache)
    {
        this->downloadCache();    
    }
}

void Cli::parsArgs(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {        
        string arg(argv[i]);

        if(arg == "-o")
        {
            this->outfilename = argv[i+1];
            
            i++;
            continue;
        }

        if(arg == "-h")
        {
            CliHelp::help();
        }

        if(arg == "--cache")
        {
            this->usecache = true;
            continue;
        }

        this->branches.push_back(arg);
    }

    if (this->branches.size() == 0)
    {
        cerr << "No enter branches" << endl;
        exit(1);
    } 
}
void Cli::downloadCache()
{    
    for(int i = 0; i < this->branches.size(); i++){
        cout << "Downloading branch " << this->branches[i] << "..." << endl;

        LibAltParser::Download download(this->branches[0]);
        download.save("/tmp/" + this->branches[i] + ".json");

    }
}

Cli::~Cli()
{
    
}
