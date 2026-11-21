#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

class SocketsComunication{
    public:
        static void request(int server_fd, int client_fd, int backend_fd){
            char bufferRequest[1024];
            char bufferResponse[1024];

            ssize_t bytes_read_request = read(client_fd, bufferRequest, sizeof(bufferRequest) -1);
            bufferRequest[bytes_read_request] = '\0';

            std::cout << "Mensagem recebida do cliente: " << bufferRequest << std::endl;

            write(backend_fd, bufferRequest, strlen(bufferRequest));

            ssize_t bytes_read_response = read(backend_fd, bufferResponse, sizeof(bufferResponse) -1);
            bufferResponse[bytes_read_response] = '\0';

            std::cout << "Mensagem recebida do servidor: " << bufferResponse << std::endl;

            
            if (strlen(bufferResponse) == 0){
                const char* errorResponse = "[ERRO] O servidor não respondeu";
                write(client_fd, errorResponse, strlen(errorResponse));
            } else {
                write(client_fd, bufferResponse, strlen(bufferResponse));
            }
        }
};