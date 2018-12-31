//
// Created by dvir on 12/14/18.
//

#include <iostream>
#include "CommandDataBase.h"
#include "BindValueTable.h"


const map<string, Command *> &CommandDataBase::getCommandTable() const {
    return commandTable;
}

// update or add command into map
void CommandDataBase::addCommand(string varName, Command *command) {
    this->commandTable[varName] = command;
}

Command *CommandDataBase::getCommand(const string &CommandName) {
    if (this->commandTable.count(CommandName) == 1)
        return this->commandTable[CommandName];
    else
        return nullptr;
}
