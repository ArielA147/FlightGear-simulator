//
// Created by ariel on 12/19/18.
//

#include <iostream>
#include "CreateServer.h"
#include "CommandDataBase.h"

CreateServer::CreateServer(int _port, int _waitTime) : _port(_port),
                                                       _waitTime(_waitTime) {}

void CreateServer::execute() {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        throw 0; // cant open socket
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = this->_port;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        throw 0; // cant bind socket
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);


    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        throw 0; // error in accepting socket
    }

//    cout<<"now in while"<<endl;

    while (true) { ///todo : to lock
        /* If connection is established then start communicating */
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            throw 0; // cant read socket
        }
//        serverIsConnected = true;
        cout << buffer << endl;

        settingPathMapWithBuffer(buffer);

//        /* Write a response to the client */
//        n = write(newsockfd, "I got your message", 18);

        if (n < 0) {
            perror("ERROR writing to socket");
            throw 0; // cant write ti socket
        }

        //todo :: unlock
        sleep (1/this->_waitTime);

    }
}

void CreateServer::settingPathMapWithBuffer(const char *buffer) const {
    Lexer r;
    string cur_buffer_str(buffer);

    vector<string> cur_buffer_v=r.baseSplit(cur_buffer_str, ',');
    CommandDataBase cdm;
    vector<string> pathListByOrder = cdm.getXmlPathKeyByXmlOrder();

    for (int i = 0; i < cur_buffer_v.size(); ++i) {

            string s1 = pathListByOrder[i];
            double d1 = stod(cur_buffer_v[i]);
            cdm.setXmlPathMap(s1, d1);
        }
}