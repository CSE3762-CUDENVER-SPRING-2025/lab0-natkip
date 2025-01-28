#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

//Client program: Sends "Hello, World!" message to the server.
//Exists after receiving the server's response
//Do so in UDP
//Make sure that they run in multiple gnodes

//Hard codes IP, port, and buffer to the program, easily modifiable by user.
#define SERVERIP "10.128.32.55"
#define SERVERPORT 2132
#define BUFFERSIZE 2000

//Driver code
int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char hello[]= "Hello, World!"; //Message the client sends server
    char buffer[BUFFERSIZE];
    socklen_t addr_len = sizeof(server_addr);

    //Creates a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) <0) {
        perror("The socket was not created, please try again.");
        exit(EXIT_FAILURE);
    }

    //Configures server addy (used chat gpt for assistance with this part)
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVERPORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVERIP);


    //Sends helloworld message
    if (sendto(sockfd, hello, strlen(hello), 0, (struct sockaddr *)&server_addr, addr_len) < 0) {
        perror("Failed to send Hello World Message");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("The message: Hello, World! has been sent to the server. ");

    //Server's response
    int message_bytes = recvfrom(sockfd, buffer, BUFFERSIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
    if  (message_bytes < 0) {
        perror("No response received; Failed.");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    //Prints the servers response
    buffer[message_bytes] = '\0';
    printf("The server responded with: %s\n", buffer);

    close(sockfd);
    return 0;
}