#include "../include/client.hpp"

UdpClient::UdpClient(){
    memset(&serverAddr, 0, sizeof(serverAddr));
}

UdpClient::~UdpClient(){
    close(clientSock);
}

int UdpClient::sockInit(){
    clientSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (clientSock == -1)
        return 1;
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIP.c_str());
    serverAddr.sin_port = htons(port);

    return 0;
}

void UdpClient::setIP(std::string ip){
    this->serverIP = ip;
}

void UdpClient::setPort(int port){
    this->port = port;
}

void UdpClient::sendMessage(std::string msg){
    ssize_t sendSucc = sendto(clientSock, msg.c_str(), msg.length(), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (sendSucc == -1){
        std::cout << "send failed.";
    }
}