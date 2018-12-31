//
// Created by ariel on 12/24/18.
//

#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
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
    char buffer[1000];
    cout << "writing" << endl;
    printf(ENTER_MSG);
    bzero(buffer, 1000);
    strcpy(buffer, msg.c_str());

//
//        BindValueTable *bindValueTable = BindValueTable::instance();
//        for (auto it = bindValueTable->getBIndTable().begin(); it !=
//        bindValueTable->getBIndTable().end(); it++) {
//            string path = it->first;
//            double value = it->second;
//            string tmp = "set" + path +" " + to_string(value);
//            strcpy(buffer, tmp);
//
//            BindTable* bindTable = BindTable::instance();
//            std::find_if

    /* send message to the server */
    ssize_t n = write(Client::sockfd, buffer, strlen(buffer));

    if (n < 0) {
        throw CLINET_ERROR;
        exit(1);
    }

}

//Client::Client(int sockfd) : sockfd(sockfd) {}

void Client::setSoketfd(int sock) {
    this->sockfd = sock;
}