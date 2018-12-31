//
// Created by dvir on 12/24/18.
//

#include "CommandExpression.h"

CommandExpression::CommandExpression(Command *command,list<string>::iterator *it){
    this->command = command;
    this->it = it;
}

double CommandExpression::calculate() {
    this->command->execute(*(this->it));
}