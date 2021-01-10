//
// Created by kamilus01 on 10.01.2021.
//

#ifndef SOCKET_PONG_TCP_H
#define SOCKET_PONG_TCP_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct tcp_server{
    unsigned port, buffer_size;
    struct sockaddr_in address;
    int server_fd, opt, new_socket;
    char *buffer;
}TCPServer;

bool tcp_server_init(TCPServer *tcp, unsigned port, unsigned buffer_size);
bool tcp_server_start(TCPServer *tcp);
bool tcp_server_listen(TCPServer *tcp);
#endif //SOCKET_PONG_TCP_H
