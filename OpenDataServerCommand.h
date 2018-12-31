//
// Created by dvir on 12/19/18.
//

#ifndef PROJECT_OPENDATASERVERCOMMAND_H
#define PROJECT_OPENDATASERVERCOMMAND_H

#include "Command.h"
#include "CommandDataBase.h"
#include "ExpressionReader.h"
#include "CreateServer.h"
#include "ExpressionFactory.h"

#include <pthread.h>
#include <thread>
#include <iostream>

struct ServerArguments{
    int portNum;
    int waitTime;
};

class OpenDataServerCommand : public Command {

public:
    void execute(list<string>::iterator &it);

};


#endif //PROJECT_OPENDATASERVERCOMMAND_H
