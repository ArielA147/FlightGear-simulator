
#include "Div.h"

Div::Div(Expression *leftValue, Expression *rightValue) : BinaryExpression(leftValue, rightValue) {}

double Div::calculate(){
        if (this->getRightArgument()->calculate() == 0.0) {
            throw  runtime_error("error, try to divide by zero!");
        }
        return this->getLeftArgument()->calculate() / this->getRightArgument()->calculate();
}
