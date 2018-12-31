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
    void run(list<string> laxerCommands);
};


#endif //PROJECT_PHARSER_H
