#include "net/SocketConnection.cpp"


int main(){

    SocketConnection* socketConnection = new SocketConnection;

    int connectSocket = socketConnection->connect();

    if (connectSocket != 0){
        std::cerr << "Erro ao conectar o socket." << std::endl;
        delete socketConnection;
        return 1;
    }


    delete socketConnection;
    return 0;
}