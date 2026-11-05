#include <iostream>
#include <string>
#include <curl/curl.h>

class RequestServer{
    private:
        size_t static WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s){
            size_t newLenght = size * nmemb;
            try{
                s->append((char*)contents, newLenght);
            } catch (std::bad_alloc& e){
                return 1;
            }
        };
    public:
        std::string request(const std::string& url){
            CURL* curl;
            CURLcode res;
            std::string readBuffer;

            curl_global_init(CURL_GLOBAL_ALL);
            curl = curl_easy_init();

            if (curl){
                // Define a url
            }
        };
};