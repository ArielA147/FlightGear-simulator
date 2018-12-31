//
// Created by dvir on 12/18/18.
//

#ifndef PROJECT_APPENDCOMMAND_H
#define PROJECT_APPENDCOMMAND_H


#include "Command.h"
#include "ExpressionReader.h"
#include "ExpressionFactory.h"
#include "SymbolTable.h"
#include "BindTable.h"
#include "Client.h"

class AppendCommand : public Command{
    // command data base.
    //CommandDataBase dataBase;
    ExpressionFactory* expreFactory;
    Client* client;

public:
    // constructor
    AppendCommand(Client* client);
    // update variable into relevant map.
    void execute(list<string>::iterator &it);
    ~AppendCommand();

};


#endif //PROJECT_APPENDCOMMAND_H
