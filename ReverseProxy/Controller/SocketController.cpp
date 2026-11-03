#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>


class SocketController{
    public: 
        int connect(){
            int server_fd = socket(AF_INET, SOCK_STREAM, 0);

            if (server_fd < 0){
                std::cout << "Falha ao criar socket: " << std::strerror(errno) << std::endl;
                return 1;
            }

            std::cout << "Socket criado com sucesso!" << std::endl;
            std::cout << "File descriptor retornado pelo linux: " << server_fd << std::endl;

            struct sockaddr_in address{};
            address.sin_family = AF_INET;
            address.sin_port = htons(3000);
            address.sin_addr.s_addr = INADDR_ANY;

            bind(server_fd, (struct sockaddr*)&address, sizeof(address));



            if (listen(server_fd, 10) < 0) {
                std::cerr << "Falha no listen: " << std::strerror(errno) << std::endl;
                close(server_fd);
                return 1;
            }

            int client_fd = accept(server_fd, nullptr, nullptr);

            char buffer_header[100];

            ssize_t bytes_read = read(client_fd, buffer_header, sizeof(buffer_header) -1);

            if (bytes_read > 0){
                buffer_header[bytes_read] = '\0';
                std::cout << "Cliente conectado! " << buffer_header << std::endl;
            }
            

            

            close(server_fd);
            std::cout << "Socket fechado com sucesso. \n";

            return 0;
        }
};