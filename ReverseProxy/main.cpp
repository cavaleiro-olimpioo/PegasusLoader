#include "Controller/SocketController.cpp"

int main(){

    SocketController* socketController = new SocketController;

    int connectSocket = socketController->connect();

    if (connectSocket != 0){
        std::cerr << "Erro ao conectar o socket." << std::endl;
        delete socketController;
        return 1;
    }


    delete socketController;
    return 0;
}