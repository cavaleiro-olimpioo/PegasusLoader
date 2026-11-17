#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cerrno>
#include <cstring>

class BackendSocket{
    public:
        int connect(){
            int backend_fd = socket(AF_INET, SOCK_STREAM, 0); 

             if (backend_fd < 0){
                std::cout << "Falha ao criar socket de conexão ao backend: " << std::strerror(errno) << std::endl;
                return 1;
            }

            struct sockaddr_in address{};
            address.sin_family = AF_INET;
            address.sin_port(3001);
            address.sin
        }
};