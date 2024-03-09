#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class UdpClient {
private:
    int port;
    int clientSock;
    char buff[1024];
    std::string serverIP;
    struct sockaddr_in serverAddr;

public:
    UdpClient();
    ~UdpClient();
    int sockInit();
    void setIP(std::string);
    void setPort(int);
    void sendMessage(std::string);
};