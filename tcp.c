//
// Created by kamilus01 on 10.01.2021.
//
#include "tcp.h"

bool tcp_server_init(TCPServer *tcp, unsigned port, unsigned buffer_size){
    tcp->opt = 1;
    if(!(tcp->server_fd = socket(AF_INET, SOCK_STREAM, 0))){
        return false;
    }
    else if(setsockopt(tcp->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &tcp->opt, sizeof(tcp->opt))){
        return false;
    }
    tcp->address.sin_family = AF_INET;
    tcp->address.sin_addr.s_addr = INADDR_ANY;
    tcp->port = port;
    tcp->address.sin_port = htons(port);
    tcp->buffer = calloc(buffer_size, sizeof(char));
    tcp->buffer_size = buffer_size;
    return true;
}

bool tcp_server_start(TCPServer *tcp){
    if(bind(tcp->server_fd, (struct sockaddr *)&tcp->address, sizeof(tcp->address))<0)
        return false;
    return true;
}

bool tcp_server_listen(TCPServer *tcp){

}