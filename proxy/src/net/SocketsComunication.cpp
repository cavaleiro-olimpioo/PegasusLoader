#include "../util/SocketAuxiliar.cpp"
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

class SocketsComunication{
    public:
        static void request(int client_fd, int backend_fd){
            char bufferRequest[1024];
            char bufferResponse[1024];

            ssize_t bytes_read_request = read(client_fd, bufferRequest, sizeof(bufferRequest) -1);

            if (bytes_read_request < 0){
                std::cout << "[ERRO] Erro ao ler request" << std::endl;
                return;
            }

            bufferRequest[bytes_read_request] = '\0';

            

            std::cout << "Mensagem recebida do cliente: " << bufferRequest << std::endl;

            ssize_t bytes_written_server = SocketAuxiliar::write_all(backend_fd, bufferRequest, static_cast<size_t>(bytes_read_request));

            std::cout << "Mensagem enviada para o servidor: " << bytes_written_server << std::endl;

            ssize_t bytes_read_response = read(backend_fd, bufferResponse, sizeof(bufferResponse) -1);
            bufferResponse[bytes_read_response] = '\0';

            if (bytes_read_response < 0){
                std::cout << "[ERRO] Erro ao ler response" << std::endl;
                return;
            }


            std::cout << "Mensagem recebida do servidor: " << bufferResponse << std::endl;

            ssize_t bytes_written_client = SocketAuxiliar::write_all(client_fd, bufferResponse, static_cast<size_t>(bytes_read_response));
            std::cout << "Mensagem enviada para o cliente: " << bytes_written_client << std::endl;
        }
};