#include <iostream>
#include <string>
#include <curl/curl.h>

class ServerRequest{
    private:
        size_t static WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s){
            size_t newLenght = size * nmemb;
            try{
                s->append((char*)contents, newLenght);
            } catch (std::bad_alloc& e){
                return 1;
            }

            return 0;
        };
    public:
        std::string request(const std::string& url){
            CURL* curl;
            CURLcode res;
            std::string readBuffer;

            curl_global_init(CURL_GLOBAL_ALL);
            curl = curl_easy_init();

            if (curl){
                // Define a url da request
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

                // Define callback de escrita a string
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

                // Usando user agent válido
                curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

                // Executa a request HTTP GET
                res = curl_easy_perform(curl);

                // Tratamento de erros no request
                if (res != CURLE_OK){
                    std::cerr << "Erro no cURL: " << curl_easy_strerror(res) << std::endl;
                } 

                // Limpa o ponteiro curl
                curl_easy_cleanup(curl);
            }

            curl_global_cleanup();

            return readBuffer;
        };
};