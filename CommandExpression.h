//
// Created by dvir on 12/24/18.
//

#ifndef PROJECT_COMMANDEXPRESSION_H
#define PROJECT_COMMANDEXPRESSION_H


#include "Expression.h"
#include "Command.h"

class CommandExpression : public Expression {
    Command *command;
    list<string>::iterator *it;
public:
    CommandExpression(Command *command,list<string>::iterator *it);
    double calculate();
};


#endif //PROJECT_COMMANDEXPRESSION_H
