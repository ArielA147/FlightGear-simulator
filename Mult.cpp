//
// Created by dvir on 12/13/18.
//

#include "Mult.h"

Mult::Mult(Expression *leftValue, Expression *rightValue) : BinaryExpression(leftValue, rightValue) {}

double Mult::calculate(){
        return this->getLeftArgument()->calculate() * this->getRightArgument()->calculate();
}