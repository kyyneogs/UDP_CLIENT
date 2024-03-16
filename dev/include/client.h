#include <iostream>
#include <string>

#ifdef _WIN32
#include <WS2tcpip.h>

#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

class UdpClient {
 private:
  int port;
  int clientSock;
  char buff[1024];
  std::string serverIP;
  struct sockaddr_in serverAddr;
#ifdef _WIN32
  int sendSucc;
#else
  ssize_t sendSucc;
#endif

 public:
  UdpClient();
  ~UdpClient();
  int sockInit();
  void setIP(std::string);
  void setPort(int);
  void sendMessage(std::string);
};