#include "../include/client.hpp"

int main(){
    UdpClient client;

    std::string ip;
    std::cout << "set IP : ";
    std::cin >> ip;
    client.setIP(ip);

    int port;
    std::cout << "set Server Port : ";
    std::cin >> port;
    client.setPort(port);
    client.sockInit();

    while(1){
        std::string message;
        std::cout << "Enter Message : ";
        getline(std::cin, message);
        if (message=="q")
            break;
        
        client.sendMessage(message);
    }
}