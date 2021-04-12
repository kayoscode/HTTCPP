#ifndef INCLUDE_URL_H
#define INCLUDE_URL_H

#include <string>

/**
 * either HTTP or HTTPS
 * @author Bryce Young
 */
enum class URLProtocol {
    HTTP,
    HTTPS
};

/**
 * Holds a loaded and parsed URL
 * @author Bryce Young 4/11/2021
 */
class URL
{
    public:
        URL(const std::string& url);

        URL() {
        }

        ~URL();

        /**
         * Discard the current url data and load a new one
         */
        void parseURL(const std::string& url);

        std::string getPath() const {
            return path;
        }

        std::string getHost() const {
            return host;
        }

    private:
        std::string host;
        std::string path;
        URLProtocol protocol;
};

#endif // URL_H
