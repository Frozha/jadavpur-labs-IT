#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#define PORT 8080
#define BUFFER_SIZE 1024
#define DAMAGE_PROBABILITY 0.2 // Probability of damaging a frame

bool frameDamaged() {
    return (rand() / (double)RAND_MAX) < DAMAGE_PROBABILITY;
}

int main() {
    srand(time(0));
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Bind the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return 1;
    }

    while (true) {
        // Receive data
        int len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
        buffer[len] = '\0';
        std::cout << "Received: " << buffer << std::endl;

        // Simulate frame damage
        if (frameDamaged()) {
            std::cout << "Frame damaged, not sending ACK" << std::endl;
            continue;
        }

        // Send ACK
        sendto(sockfd, "ACK", strlen("ACK"), 0, (struct sockaddr *)&client_addr, addr_len);

        // Exit loop if needed
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}

