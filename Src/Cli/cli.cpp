#include "cli.h"

#include "help.h"
#include "differ.h"
#include "download.h"

#include <fstream>

using namespace std;

Cli::Cli(int argc, char **argv)
{
    this->parsArgs(argc, argv);

    auto paths = this->getPaths();

    if(!this->usecache)
    {
        this->downloadCache(paths);    
    }

    if(this->outfile)
    {
        this->tofile(
            this->outfilename,
            this->diff(paths)
        );
    }
    else 
    {
        cout << this->diff(paths);
    }
}

void Cli::parsArgs(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {        
        string arg(argv[i]);

        if(arg == "-o")
        {
            this->outfile = true;
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

    if (this->branches.size() <= 1)
    {
        cerr << "No enter branches" << endl;
        exit(1);
    } 
}

vector<string> Cli::getPaths()
{
    vector<string> paths;

    for(auto &el : this->branches){

        paths.push_back("/tmp/" + el + ".json");

    }

    return paths;
}

void Cli::downloadCache(vector<string> paths)
{    
    for(int i = 0; i < paths.size(); i++){

        cout << "Downloading branch " << this->branches[i] << "..." << endl;

        LibAltParser::Download download(this->branches[i]);
        download.save(paths[i]);        
    }    
}

string Cli::diff(vector<string> paths)
{
    cout << "Loading files..." << endl;    

    LibAltParser::Differ differ(
        paths[0],
        paths[1]
    );

    cout << "Diff files..." << endl;

    differ.diff();

    return differ.getStructJSON();    
}

void Cli::tofile(string filename, string data){
    ofstream fout(filename);

    if(fout.is_open())
    {      
        cout << "Out to file " + filename + " ...";
        fout << data;
    }    

    fout.close();
}
