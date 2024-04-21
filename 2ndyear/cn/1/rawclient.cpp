// Client.cpp

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int clientSocket = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (clientSocket == -1) {
        std::cerr << "Socket creation failed\n";
        return -1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(53535);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    std::string message = "Hello from client!";
    sendto(clientSocket, message.c_str(), message.size(), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    char buffer[1024] = {0};
    socklen_t serverAddrSize = sizeof(serverAddr);
    recvfrom(clientSocket, buffer, 1024, 0, (struct sockaddr *)&serverAddr, &serverAddrSize);
    std::cout << "Received message from server: " << buffer << std::endl;

    close(clientSocket);

    return 0;
}
