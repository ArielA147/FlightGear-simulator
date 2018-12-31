//
// Created by ariel on 12/19/18.
//

#ifndef PROJECT_CREATSERVER_H
#define PROJECT_CREATSERVER_H


#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>

#include <string>


#include "Lexer.h"

using namespace std;

class CreateServer {
private:
    int _port;
    int _waitTime;
public:

    CreateServer(int _port, int _waitTime);

    void execute();

    void settingPathMapWithBuffer(const char *buffer);

    void updateDataBase();

    vector<string> getXmlPathKeyByXmlOrder();

    void setXmlPathMap(string key, double value);
};


#endif //PROJECT_CREATSERVER_H
