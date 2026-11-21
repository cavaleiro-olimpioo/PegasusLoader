#include "net/sockets/MainSocket.cpp"
#include "net/sockets/ClientSocket.cpp"
#include "net/sockets/BackendSocket.cpp"
#include "net/SocketsComunication.cpp"

int main(){
    MainSocket* mainSocket = new MainSocket;
    int server_fd = mainSocket->connect();

    ClientSocket* clientSocket = new ClientSocket(server_fd);
    int client_fd = clientSocket->connect();

    BackendSocket* backendSocket = new BackendSocket();
    int node = 3001;
    int backend_fd = backendSocket->connect(node);

    SocketsComunication::request(server_fd, client_fd, backend_fd);

    close(backend_fd);
    close(server_fd);
    close(client_fd);

    delete backendSocket;
    delete mainSocket;
    delete clientSocket;
    return 0;
}