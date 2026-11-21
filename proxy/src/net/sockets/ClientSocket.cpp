#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

class ClientSocket{
    public:
        ClientSocket(int a) : server_fd(a){}


        int connect(){
            struct sockaddr_in client_addr;

            socklen_t addr_len = sizeof(client_addr);

            int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);

            return client_fd;
        }
    private:
        int server_fd;
};