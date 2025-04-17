#ifndef ECHO_H
#define ECHO_H

#define DEFAULT_PORT 3000
#define LISTEN_BACKLOG 5
extern int print_val;

void* handle_connection(int* client_socket);

#endif // ECHO_H