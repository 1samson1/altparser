#include "download.h"

using namespace std;
using namespace LibAltParser;

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

Download::Download()
{
    this->baseurl = "https://rdb.altlinux.org/api/export/branch_binary_packages/";
}

Download::Download(string branch):Download::Download()
{
    this->branch = branch;
}

void Download::save(string filename)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    string url = this->baseurl + this->branch;
    
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename.c_str(),"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }    
}

Download::~Download()
{
}
