//
// Created by dvir on 12/13/18.
//

#include "Plus.h"


Plus::Plus(Expression *leftValue, Expression *rightValue) : BinaryExpression(leftValue, rightValue) {}

double Plus::calculate(){
    return this->getLeftArgument()->calculate() + this->getRightArgument()->calculate();
}