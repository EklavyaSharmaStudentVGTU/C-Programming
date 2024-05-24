#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

// Function to set up a TCP server socket
int setupTCPServerSocket(int port) {
int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
if (serverSocket < 0) {
perror("Error creating server socket");
exit(EXIT_FAILURE);
}
struct sockaddr_in serverAddr;
serverAddr.sin_family = AF_INET;
serverAddr.sin_addr.s_addr = INADDR_ANY;
serverAddr.sin_port = htons(port);
if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
perror("Error binding server socket");
exit(EXIT_FAILURE);
}
if (listen(serverSocket, 5) < 0) {
perror("Error listening on server socket");
exit(EXIT_FAILURE);
}
return serverSocket;
}