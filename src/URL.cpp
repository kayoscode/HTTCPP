#include "URL.h"

inline void parseURL(const std::string& url, URLProtocol& protocol, std::string& host, std::string& path) {
    //url format
    host = "";
    path = "";
    int i = 0;

    std::string urlTmp(url);

    if(urlTmp.substr(0, 7) == "http://") {
        urlTmp = urlTmp.substr(7, urlTmp.size());
        protocol = URLProtocol::HTTP;
    }
    else if(urlTmp.substr(0, 8) == "https://") {
        urlTmp = urlTmp.substr(8, urlTmp.size());
        protocol = URLProtocol::HTTPS;
    }
    else {
        protocol = URLProtocol::HTTP;
    }

    //the hostname is everything up until the forward slash if it exists
    for(i = 0; i < urlTmp.size(); ++i) {
        if(urlTmp[i] == '/' || urlTmp[i] == '\\') {
            break;
        }

        host += urlTmp[i];
    }

    if(i < urlTmp.size()) {
        //set the path from the rest of the string
        //if we get hit with a '?', we've gotta bail because we don't handle
        //get request variables here!
        for(int j = i; j < urlTmp.size(); j++) {
            if(urlTmp[j] == '?') {
                break;
            }

            path += urlTmp[j];
        }
    }
    else {
        path = "/";
    }
}

void URL::parseURL(const std::string& url) {
    ::parseURL(url, protocol, host, path);
}

URL::URL(const std::string& url) {
    parseURL(url);
}

URL::~URL(){
}
