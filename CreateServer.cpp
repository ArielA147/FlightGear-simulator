//
// Created by ariel on 12/19/18.
//

#include <iostream>
#include <mutex>
#include <thread>
#include "CreateServer.h"
#include "CommandDataBase.h"
#include "BindValueTable.h"
#include "BindTable.h"
#include "SymbolTable.h"
#include "MutexClass.h"

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
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
                       (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        throw 0; // error in accepting socket
    }

    while (true) { ///todo : to lock
        /* If connection is established then start communicating */
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            throw 0; // cant read socket
        }

        settingPathMapWithBuffer(buffer);

        if (n < 0) {
            perror("ERROR writing to socket");
            throw 0; // cant write ti socket
        }

        CreateServer::updateDataBase();
        usleep((1 / this->_waitTime) * 1000);
    }
}

void CreateServer::settingPathMapWithBuffer(const char *buffer)  {
    Lexer r;
    string cur_buffer_str(buffer);

    vector<string> cur_buffer_v = r.baseSplit(cur_buffer_str, ',');
    vector<string> pathListByOrder = getXmlPathKeyByXmlOrder();


    for (int i = 0; i < cur_buffer_v.size(); ++i) {
        string s1 = pathListByOrder[i];
        double d1 = stod(cur_buffer_v[i]);
        setXmlPathMap(s1, d1);
    }
}

void CreateServer::updateDataBase() {
    pthread_mutex_t *mutex = MutexClass::getInstance()->getMutex();
    pthread_mutex_lock(mutex);
    SymbolTable *symbolTable = SymbolTable::instance();
    BindTable *bindTable = BindTable::instance();
    BindValueTable *bindValueTable = BindValueTable::instance();

    for (auto key : symbolTable->getVarTable()) {
        string path = "";
        if (bindTable->getBIndTable().count(key.first) == 1) {
            path = bindTable->getValue(key.first);
        }
        if (bindValueTable->getBIndTable().count(path)) {
            double value = bindValueTable->getValue(path);
            symbolTable->setValue(key.first, value);
        }
    }
    pthread_mutex_unlock(mutex);
}


vector<string> CreateServer::getXmlPathKeyByXmlOrder() {
    vector<string> xmlPathInOrder;
    xmlPathInOrder.push_back(
            "/instrumentation/airspeed-indicator/indicated-speed-kt");
    xmlPathInOrder.push_back(
            "/instrumentation/altimeter/indicated-altitude-ft");
    xmlPathInOrder.push_back("/instrumentation/altimeter/pressure-alt-ft");
    xmlPathInOrder.push_back(
            "/instrumentation/attitude-indicator/indicated-pitch-deg");
    xmlPathInOrder.push_back(
            "/instrumentation/attitude-indicator/indicated-roll-deg");
    xmlPathInOrder.push_back(
            "/instrumentation/attitude-indicator/internal-pitch-deg");
    xmlPathInOrder.push_back(
            "/instrumentation/attitude-indicator/internal-roll-deg");
    xmlPathInOrder.push_back("/instrumentation/encoder/indicated-altitude-ft");
    xmlPathInOrder.push_back("/instrumentation/encoder/pressure-alt-ft");
    xmlPathInOrder.push_back("/instrumentation/gps/indicated-altitude-ft");
    xmlPathInOrder.push_back("/instrumentation/gps/indicated-ground-speed-kt");
    xmlPathInOrder.push_back("/instrumentation/gps/indicated-vertical-speed");
    xmlPathInOrder.push_back(
            "/instrumentation/heading-indicator/indicated-heading-deg");
    xmlPathInOrder.push_back(
            "/instrumentation/magnetic-compass/indicated-heading-deg");
    xmlPathInOrder.push_back(
            "/instrumentation/slip-skid-ball/indicated-slip-skid");
    xmlPathInOrder.push_back(
            "/instrumentation/turn-indicator/indicated-turn-rate");
    xmlPathInOrder.push_back(
            "/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
    xmlPathInOrder.push_back("/controls/flight/aileron");
    xmlPathInOrder.push_back("/controls/flight/elevator");
    xmlPathInOrder.push_back("/controls/flight/rudder");
    xmlPathInOrder.push_back("/controls/flight/flaps");
//    xmlPathInOrder.push_back("/controls/engines/engine/throttle");
xmlPathInOrder.push_back("/controls/engines/current-engine/throttle");
    xmlPathInOrder.push_back("/engines/engine/rpm");
    return xmlPathInOrder;
}

void CreateServer::setXmlPathMap(string key, double value) {
    if (BindValueTable::instance()->getBIndTable().count(key) == 1) {
        BindValueTable::instance()->setValue(key, value);
    }
}