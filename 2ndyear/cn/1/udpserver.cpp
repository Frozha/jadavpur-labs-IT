// Server.cpp

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Socket creation failed\n";
        return -1;
    }

    sockaddr_in serverAddr, clientAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(53535); // Port number
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Binding failed\n";
        return -1;
    }

    char buffer[1024] = {0};
    socklen_t clientAddrSize = sizeof(clientAddr);
    recvfrom(serverSocket, buffer, 1024, 0, (struct sockaddr *)&clientAddr, &clientAddrSize);
    std::cout << "Received message: " << buffer << std::endl;

    std::string response = "Message received by server";
    sendto(serverSocket, response.c_str(), response.size(), 0, (struct sockaddr *)&clientAddr, clientAddrSize);

    close(serverSocket);

    return 0;
}
