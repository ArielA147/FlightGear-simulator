//
// Created by dvir on 12/15/18.
//

#include "BoolExpression.h"


BoolExpression::BoolExpression(Expression *leftValue, string condition_op, Expression *rightValue) :
        BinaryExpression(leftValue, rightValue) {
    this->condition_op = condition_op;
}

double BoolExpression::calculate() {
    if (this->condition_op == ">")
        return leftValue->calculate() > rightValue->calculate();

    else if (this->condition_op == "<")
        return leftValue->calculate() < rightValue->calculate();

    else if (this->condition_op == "==")
        return leftValue->calculate() == rightValue->calculate();
    else

        throw runtime_error("invalid operator: " + this->condition_op);
}