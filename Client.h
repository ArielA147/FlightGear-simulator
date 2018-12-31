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
    /**
     * setting the client socket by sockt number
     * @param sock socket number
     */
    void setSoketfd(int sock);
/**
 * senting msg to the server and update the simulator
 * @param msg the msg we want to update the simulator with
 */
    void sentMsg(string msg);
};


#endif //PROJECT_CLIENT_H
