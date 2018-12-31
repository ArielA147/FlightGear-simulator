//
// Created by ariel on 12/24/18.
//

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

#include <string>
#include <strings.h>
#include <unistd.h>
#include <cstring>
#include "BindValueTable.h"
#include "BindTable.h"

#define ENTER_MSG "please enter the message: "
#define  CLINET_ERROR "client error"


using namespace std;

class Client {
    int sockfd = 0;

public:
    void setSoketfd(int sock);

    void sentMsg(string msg);
};


#endif //PROJECT_CLIENT_H
