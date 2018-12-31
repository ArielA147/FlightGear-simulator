//
// Created by dvir on 12/20/18.
//

#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include "ConnectCommand.h"
#include "Client.h"

void ConnectCommand::execute(list<string>::iterator &it) {
    // set expressionReader and ExpressionFactory
    ExpressionReader er = ExpressionReader();
    ExpressionFactory factory = ExpressionFactory();
    it++;    // skip connect token
    string ip = *it;    // save string ip.

    it++;
    // get port
    list<string> portExpression = er.getExpression(it);
    Expression *e = factory.create(portExpression);

    int port = (int) e->calculate();
    delete e;

    // checking if there is a connection to the server / if there is not -
    // not to conintue in the code and wait till we connected to the server

//       while(serverIsConnected==false){}F

    waitToConnectingInput();


    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    struct hostent *server;
    struct sockaddr_in serv_addr;

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(port);

    /*now connect to the server*/
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <
        0) {
        perror("ERROR connecting");
        exit(1);
    }
    cout << "i created a client's socket . you can continue" << endl;

//    Client c;
    cout << "now go the the client setting sockfd" << endl;
    c->setSoketfd(sockfd);
    return;

}

void ConnectCommand::waitToConnectingInput() const {
    cout << "waiting to the user input in order to continue" << endl;
    cin.ignore();
    cout << "now continue" << endl;
}