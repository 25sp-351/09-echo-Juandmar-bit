#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <pthread.h>
#include "echo.h"

#define BUFFER_SIZE 1024
int print_val = 0;

void* handle_connection(int* client_socket) {
    int accepted_socket = *client_socket;
    free(client_socket);
    printf("Accepted socket %p\n", pthread_self());

    if (accepted_socket < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }
    printf("Client connected.\n");
    char *welcome_message = "Welcome to the echo server!(Enter \"quit\" to close)\n";
    write(accepted_socket, welcome_message, strlen(welcome_message));
    // Receive data from the client
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = read(accepted_socket, buffer, sizeof(buffer))) > 0) {
        printf("Received %d bytes\n", bytes_received);

        if (print_val) {
            printf("Data: %s\n", buffer);
        }
        if (strncmp(buffer, "quit", 4) == 0) {
            printf("Client on thread %p requested to quit.\n", pthread_self());
            break;
        }
        close(accepted_socket);
        pthread_exit(NULL);
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
    }
    if (bytes_received < 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
    printf("Client disconnected.\n");
    close(accepted_socket);
    return NULL;
}