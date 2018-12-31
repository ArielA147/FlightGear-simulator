#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *leftValue, Expression *rightValue) {
    this->leftValue = leftValue;
    this->rightValue = rightValue;
}

//return the left Expression object.
Expression *BinaryExpression::getLeftArgument() {
    return this->leftValue;
}

Expression *BinaryExpression::getRightArgument() {
    return this->rightValue;
}

void BinaryExpression::setLeftValue(Expression *leftValue) {
    this->leftValue = leftValue;
}

void BinaryExpression::setRightValue(Expression *rightValue) {
    this->rightValue = rightValue;
}

BinaryExpression::~BinaryExpression() {
    delete  leftValue;
    delete rightValue;
}
