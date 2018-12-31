

#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(Expression *argument){
    this->argument = argument;
}

Expression* UnaryExpression::getArgument() {
    return this->argument;
}

void UnaryExpression::setValue(Expression *argument) {
    this->argument = argument;
}