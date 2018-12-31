//
// Created by dvir on 12/25/18.
//

#ifndef PROJECT_PRINTCOMMAND_H
#define PROJECT_PRINTCOMMAND_H

#include "Command.h"
#include "SymbolTable.h"
#include "ExpressionReader.h"
#include "ExpressionFactory.h"
#include <iostream>

class PrintCommand : public Command {

public:
    void execute(list<string>::iterator &it);

};


#endif //PROJECT_PRINTCOMMAND_H
