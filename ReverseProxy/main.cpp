#include <Controller/SocketController.cpp>

int main(){

    SocketController* socketController = new SocketController;

    socketController->connect();

    delete socketController;
}