#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>


class SocketController{
    int main(){
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);

        if (server_fd < 0){
            std::cout << "Falha ao criar socket: " << std::strerror(errno) << std::endl;
            return 1;
        }

        struct sockaddr_in address{};
        address.sin_family = AF_INET;
        address.sin_port = htons(8080);
        address.sin_addr.s_addr = INADDR_ANY;

        bind(server_fd, (struct sockaddr*)&address, sizeof(address));


        std::cout << "Socket criado com sucesso!" << std::endl;
        std::cout << "File descriptor retornado pelo linux: " << server_fd << std::endl;

        close(server_fd);
        std::cout << "Socket fechado com sucesso. \n";

        return 0;
    }
};