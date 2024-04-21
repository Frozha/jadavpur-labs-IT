#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Socket creation failed\n";
        return -1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(53535); // Port number
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); // IP address

    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Connection failed\n";
        return -1;
    }

    std::string message = "Hello from client!";
    send(clientSocket, message.c_str(), message.size(), 0);
    char buffer[1024] = {0};
    recv(clientSocket, buffer, 1024, 0);
    std::cout << "Received message from server: " << buffer << std::endl;
    close(clientSocket);

    return 0;
}
