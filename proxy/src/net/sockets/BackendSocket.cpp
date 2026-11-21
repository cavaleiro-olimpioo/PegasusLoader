#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cerrno>
#include <cstring>
#include <arpa/inet.h>

class BackendSocket{
    public:
        int connect(const char* node){
            int backend_fd = socket(AF_INET, SOCK_STREAM, 0); 

             if (backend_fd < 0){
                std::cout << "Falha ao criar socket de conexão ao backend: " << std::strerror(errno) << std::endl;
                return 1;
            }

            struct sockaddr_in address{};
            address.sin_family = AF_INET;
            address.sin_port = htons(3000);
            inet_pton(AF_INET, node, &address.sin_addr);

            ::connect(backend_fd, (struct sockaddr*)&address, sizeof(address));

            return backend_fd;
        }
};