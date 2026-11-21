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
            address.sin_port = htons(3001);
            address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

            bind(backend_fd, (struct sockaddr*)&address, sizeof(address));

            listen(backend_fd, 10);

            std::cout << "Backend socket criado com sucesso!" << std::endl;
            std::cout << "File descriptor: " << backend_fd << std::endl;

            return backend_fd;
        }
};