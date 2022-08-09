#ifndef LIB_AP_DOWNLOAD_H
#define LIB_AP_DOWNLOAD_H

#include <string>
#include <curl/curl.h>

namespace LibAltParser {

    class Download
    {
    private:
        std::string baseurl;
        std::string branch;

    public:
        Download();
        Download(std::string branch);

        void save(std::string filename);

        ~Download();
    };

}

#endif
