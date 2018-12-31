//
// Created by ariel on 12/24/18.
//

#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <mutex>
#include "Client.h"
//Client::Client(string ip, int port) {
////    int n;
////    struct sockaddr_in serv_addr;
////    struct hostent *server;
////
////    char buffer[256];
////
////
////    /* Create a socket point*/
////    sockfd = socket(AF_INET,SOCK_STREAM,0);
////
////    if(sockfd < 0){
////        throw "client error";
////    }
////
////    server = gethostbyname(ip.c_str());
////
////    if(server== NULL){
////        throw CLINET_ERROR;
////    }
////
////    bzero((char*)&serv_addr , sizeof(serv_addr));
////    serv_addr.sin_family = AF_INET;
////    bcopy((char*)server->h_addr,(char*)&serv_addr.sin_addr,server->h_length);
////    serv_addr.sin_port= htons(port);
////
////    /*now connect to the server */
////    if (connect(sockfd,(struct sockaddr*)&serv_addr, sizeof(serv_addr))<0){
////        throw CLINET_ERROR;
////    }
//}


void Client::sentMsg(string msg) {
//    mutex mtx;
//    mtx.lock();

    char buffer[1000];
    bzero(buffer, 1000);
    strcpy(buffer, msg.c_str());

    cout << "now will do the wrintng" << endl;
    cout << "the msg is =====> " + msg<<endl;

    /* send message to the server */

    ssize_t n = write(Client::sockfd, buffer, strlen(buffer));
//    mtx.unlock();

    if (n < 0) {
        throw CLINET_ERROR;
        exit(1);
    }
}

void Client::setSoketfd(int sock) {
    this->sockfd = sock;
}