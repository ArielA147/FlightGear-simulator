//
// Created by dvir on 12/14/18.
//

#ifndef PROJECT_COMMANDDATABASE_H
#define PROJECT_COMMANDDATABASE_H

#include <map>
#include <string>
#include <vector>
#include "Command.h"

using namespace std;


/*
 * class created in order to store var and their current values.
 */
class CommandDataBase {
    // db of the commands and their names.
    map<string, Command*> commandTable;

public:
    // getCommand
    const map<string, Command*> &getCommandTable() const;
    /**
     * adding new command to the table
     * @param varName name of the command
     * @param command object command
     */
    void addCommand(string varName, Command* command);
    /**
     *
     * @param CommandName the name of the command
     * @return the command object
     */
    Command* getCommand(const string &CommandName);

};

#endif //PROJECT_COMMANDDATABASE_H