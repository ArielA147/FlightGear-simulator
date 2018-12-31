#include  "Minus.h"

Minus::Minus(Expression *leftValue, Expression *rightValue) : BinaryExpression(leftValue, rightValue) {}
double Minus::calculate(){
            return this->getLeftArgument()->calculate() - this->getRightArgument()->calculate();
    }