// Server.cpp

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
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

    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Listening failed\n";
        return -1;
    }

    socklen_t clientAddrSize = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
    if (clientSocket == -1) {
        std::cerr << "Acceptance failed\n";
        return -1;
    }

    char buffer[1024] = {0};
    recv(clientSocket, buffer, 1024, 0);
    std::cout << "Received message: " << buffer << std::endl;

    // Sending response back to the client
    std::string response = "Message received by server";
    send(clientSocket, response.c_str(), response.size(), 0);

    close(clientSocket);
    close(serverSocket);

    return 0;
}
