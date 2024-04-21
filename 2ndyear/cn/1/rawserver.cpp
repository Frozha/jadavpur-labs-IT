// Server.cpp

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int serverSocket = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (serverSocket == -1) {
        
        std::cerr << "Socket creation failed\n";
        return -1;
    }

    char buffer[1024] = {0};
    sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    recvfrom(serverSocket, buffer, 1024, 0, (struct sockaddr *)&clientAddr, &clientAddrSize);
    std::cout << "Received message from client: " << buffer << std::endl;

    // Sending a message back to the client
    std::string response = "Hello from server!";
    sendto(serverSocket, response.c_str(), response.size(), 0, (struct sockaddr *)&clientAddr, clientAddrSize);

    close(serverSocket);

    return 0;
}
