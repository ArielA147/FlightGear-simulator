//
// Created by dvir on 12/20/18.
//

#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include "CommandDataBase.h"
#include "ExpressionReader.h"
#include "ExpressionFactory.h"
#include "Client.h"

//struct ServerArguments{
//    int sockfd;
//    int port;
//};

//bool serverIsConnected;
//static int sockfd;

class ConnectCommand : public Command {
    Client *c;
public:
    ConnectCommand(Client &c){this->c = &c;};
    // get string variable as ip, portNum as int.
    void execute(list<string>::iterator &it);

    void waitToConnectingInput() const;
};


#endif //PROJECT_CONNECTCOMMAND_H
