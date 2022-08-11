#include "version.h"

#include <algorithm>
#include <sstream>

using namespace std;
using namespace LibAltParser;

Version::Version()
{
    this->version = "0.0.0";
}

Version::Version(string version)
{
    this->version = version;
}

string Version::get()
{
    return this->version;
}

vector<string> Version::splitVersion()
{
    // Count parts
    int size = count(this->version.begin(), this->version.end(), '.') + 1;

    vector<string> parts(size);
    stringstream ss(this->version);
    string item;
    int it = 0;

    while(getline(ss, item, '.'))
    {
        parts[it] = item;
        it++;
    }

    return parts;
}

int Version::countPointPart(string part)
{
    int points = 0;

    for(int i = 0, mul = part.size(); i < part.size(); i++, mul--){
        points += (int) part[i] * mul;
    }

    return points;
}

bool Version::operator> (Version &other)
{
    int size;
    auto sversion1 = this->splitVersion();
    auto sversion2 = other.splitVersion();

    if(sversion1.size() > sversion2.size())
    {
        size = sversion2.size();
    }
    else
    {
        size = sversion1.size();
    }

    for (int i = 0; i < size; i++)
    {
        int points1 = this->countPointPart(sversion1[i]);
        int points2 = this->countPointPart(sversion2[i]);

        if(points1 > points2)
        {
            return true;
        }

        if (points1 < points2)
        {
            return false;
        }
        
    }

    return false;
}
