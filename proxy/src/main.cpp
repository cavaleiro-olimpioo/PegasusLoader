#include "net/MainSocket.cpp"
#include "net/ClientSocket.cpp"
#include "net/BackendSocket.cpp"

int main(){
    MainSocket* mainSocket = new MainSocket;
    
    int server_fd = mainSocket->connect();

    ClientSocket* clientSocket = new ClientSocket(server_fd);

    int client_fd = clientSocket->connect();

    BackendSocket* backendSocket = new BackendSocket();

    int node = 3001;

    int backend_fd = backendSocket->connect(node);




    std::cout << "Socket principal criado com fd de " << server_fd << std::endl;
    std:: cout << "Client socket criado com fd de " << client_fd << std::endl;
    std::cout << "Backend criado com fd de " << backend_fd << std::endl;

    close(backend_fd);
    close(server_fd);
    close(client_fd);

    delete backendSocket;
    delete mainSocket;
    delete clientSocket;
    return 0;
}