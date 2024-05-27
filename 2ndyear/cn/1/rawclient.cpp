#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Pseudo header needed for UDP checksum calculation
struct pseudo_header {
    u_int32_t source_address;
    u_int32_t dest_address;
    u_int8_t placeholder;
    u_int8_t protocol;
    u_int16_t udp_length;
};

// Function to calculate the checksum of a packet
unsigned short checksum(void *b, int len) {    
    unsigned short *buf = (unsigned short *)b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct pseudo_header psh;

    // Create raw socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Destination address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // Change to server IP

    // Buffer to hold the packet
    char packet[BUFFER_SIZE];

    // IP header
    struct iphdr *iph = (struct iphdr *)packet;
    struct udphdr *udph = (struct udphdr *)(packet + sizeof(struct iphdr));

    // Fill the IP header
    iph->ihl = 5;
    iph->version = 4;
    iph->tos = 0;
    iph->tot_len = sizeof(struct iphdr) + sizeof(struct udphdr) + strlen(buffer);
    iph->id = htonl(54321); // Id of this packet
    iph->frag_off = 0;
    iph->ttl = 255;
    iph->protocol = IPPROTO_UDP;
    iph->check = 0; // Set to 0 before calculating checksum
    iph->saddr = inet_addr("127.0.0.1"); // Change to client IP
    iph->daddr = server_addr.sin_addr.s_addr;

    // IP checksum
    iph->check = checksum((unsigned short *)packet, iph->tot_len);

    // UDP header
    udph->source = htons(12345); // Arbitrary source port
    udph->dest = htons(PORT);
    udph->len = htons(sizeof(struct udphdr) + strlen(buffer));
    udph->check = 0; // Leave checksum 0 now, filled later by pseudo header

    // Data
    strcpy(packet + sizeof(struct iphdr) + sizeof(struct udphdr), "Hello, Server!");

    // Now the UDP checksum using the pseudo header
    psh.source_address = inet_addr("127.0.0.1");
    psh.dest_address = server_addr.sin_addr.s_addr;
    psh.placeholder = 0;
    psh.protocol = IPPROTO_UDP;
    psh.udp_length = htons(sizeof(struct udphdr) + strlen(buffer));

    int psize = sizeof(struct pseudo_header) + sizeof(struct udphdr) + strlen(buffer);
    char *pseudogram = new char[psize];

    memcpy(pseudogram, (char *)&psh, sizeof(struct pseudo_header));
    memcpy(pseudogram + sizeof(struct pseudo_header), udph, sizeof(struct udphdr) + strlen(buffer));

    udph->check = checksum((unsigned short *)pseudogram, psize);

    // Send the packet
    if (sendto(sockfd, packet, iph->tot_len, 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("sendto failed");
        return 1;
    }

    std::cout << "Packet sent!" << std::endl;

    close(sockfd);
    return 0;
}

