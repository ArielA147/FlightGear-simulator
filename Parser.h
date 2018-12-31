//
// Created by dvir on 12/18/18.
//

#ifndef PROJECT_PHARSER_H
#define PROJECT_PHARSER_H


#include "CommandDataBase.h"
#include "SymbolTable.h"
#include "BindTable.h"

class Parser {
CommandDataBase* db;
list<string> laxerCommands;

public:
    Parser(CommandDataBase *db);
    /**
     * running and executing the commands of the lexer commands
     * @param laxerCommands list of commands
     */
    void run(list<string> laxerCommands);
};


#endif //PROJECT_PHARSER_H
