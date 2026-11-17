#include "net/MainSocket.cpp"


int main(){

    MainSocket* mainSocket = new MainSocket;

    int connectSocket = mainSocket->connect();

    std::cout << connectSocket << std::endl;


    delete mainSocket;
    return 0;
}