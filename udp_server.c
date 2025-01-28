#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

//Hard codes port and buffer to the program. User can change either of these.
#define SERVERPORT 2132
#define BUFFERSIZE 2000


//Driver code
int main() { 
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFERSIZE];
    char clientresponse[] = "Welcome to CSE5462."; // Response sent to the client
    socklen_t addr_len = sizeof(client_addr);

    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Allow reuse of the address to avoid "Address already in use" error
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from all IP addresses
    server_addr.sin_port = htons(SERVERPORT);

    // Bind the socket to the specified port
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    //Prints the server's port
    printf("The server is running on port %d...\n", SERVERPORT);

    // Run the server indefinitely
    while (1) {
        printf("Waiting to receive messages from the client...\n");

        // Receive a message from the client
        int message_received = recvfrom(sockfd, buffer, BUFFERSIZE - 1, 0, (struct sockaddr *)&client_addr, &addr_len);
        if (message_received < 0) {
            perror("Failed to receive message");
            continue;
        }

        buffer[message_received] = '\0'; // Null-terminate the received message

        // Log the client's details
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
        printf("Received message from %s:%d\n", client_ip, ntohs(client_addr.sin_port));
        printf("Message: %s\n", buffer);

        // Send a response to the client
        if (sendto(sockfd, clientresponse, strlen(clientresponse), 0, (struct sockaddr *)&client_addr, addr_len) < 0) {
            perror("Failed to send response");
            continue;
        }

        printf("Response sent to %s:%d\n", client_ip, ntohs(client_addr.sin_port));
    }

    // Close the socket (unreachable in this code, but added for good practice)
    close(sockfd);
    return 0;
}
