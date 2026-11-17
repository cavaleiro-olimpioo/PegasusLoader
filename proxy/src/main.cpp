#include "net/MainSocket.cpp"
#include "net/ClientSocket.cpp"

int main(){
    MainSocket* mainSocket = new MainSocket;
    
    int server_fd = mainSocket->connect();

    ClientSocket* clientSocket = new ClientSocket(server_fd);

    int client_fd = clientSocket->connect();


    std::cout << "Socket principal criado com fd de " << server_fd << std::endl;
    std:: cout << "Client socket criado com fd de " << client_fd << std::endl;


    close(server_fd);
    close(client_fd);

    delete mainSocket;
    delete clientSocket;
    return 0;
}