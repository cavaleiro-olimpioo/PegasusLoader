#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

class ServerRequest{
    public: 
        std::string request(std::string server){
            int server_fd = socket(AF_INET, SOCK_STREAM, 0);

            if(server_fd < 0){
                std::cout << "Falha ao estabelecer conexão com o servidor" << std::endl;
                return "Error";
            }

            struct sockaddr_in address{};
            address.sin_family = AF_INET;
            address.sin_port = htons(3000);
            address.sin_addr.s_addr = INADDR_ANY;


        }
};