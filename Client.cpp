//
// Created by ariel on 12/24/18.
//

#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <mutex>
#include "Client.h"

void Client::sentMsg(string msg) {
    char buffer[1000];
    bzero(buffer, 1000);
    strcpy(buffer, msg.c_str());

    /* send message to the server */

    ssize_t n = write(Client::sockfd, buffer, strlen(buffer));

    if (n < 0) {
        throw CLINET_ERROR;
        exit(1);
    }
}

void Client::setSoketfd(int sock) {
    this->sockfd = sock;
}