//
// Created by dvir on 12/14/18.
//

#ifndef PROJECT_DEFINEVARCOMAND_H
#define PROJECT_DEFINEVARCOMAND_H

#include "Command.h"
#include "CommandDataBase.h"

class DefineVarCommand : public Command {
    Command* appendCommand;

public:
    DefineVarCommand(Command* appendCommand);
    void execute(list<string>::iterator &it);

};


#endif //PROJECT_DEFINEVARCOMAND_H
