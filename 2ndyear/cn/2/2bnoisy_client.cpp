#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#define PORT 8080
#define BUFFER_SIZE 1024
#define LOSS_PROBABILITY 0.2 // Probability of losing a frame
#define TIMEOUT 5 // Timeout in seconds

bool frameLost() {
    return (rand() / (double)RAND_MAX) < LOSS_PROBABILITY;
}

int main() {
    srand(time(0));
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(server_addr);
    struct timeval tv;
    fd_set readfds;

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // Change to receiver IP

    while (true) {
        std::cout << "Enter data to send: ";
        std::cin.getline(buffer, BUFFER_SIZE);

        // Send data
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, addr_len);

        // Wait for ACK with timeout
        while (true) {
            FD_ZERO(&readfds);
            FD_SET(sockfd, &readfds);

            tv.tv_sec = TIMEOUT;
            tv.tv_usec = 0;

            int retval = select(sockfd + 1, &readfds, NULL, NULL, &tv);

            if (retval == -1) {
                perror("select()");
                close(sockfd);
                return 1;
            } else if (retval) {
                // Data is available
                int len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
                buffer[len] = '\0';

                if (strcmp(buffer, "ACK") == 0) {
                    std::cout << "Received ACK" << std::endl;
                    break;
                }
            } else {
                // Timeout occurred, resend the frame
                std::cout << "Timeout, resending..." << std::endl;
                sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, addr_len);
            }
        }

        // Exit loop if needed
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}

