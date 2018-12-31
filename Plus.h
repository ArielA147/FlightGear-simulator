//
// Created by dvir on 12/13/18.
//

#ifndef PROJECT_PLUS_H
#define PROJECT_PLUS_H


#include "BinaryExpression.h"

/**
 * this class represent minus expression,define print,evaluate and differentiate rules.
 */
class Plus : public BinaryExpression {
public:

    Plus(Expression *leftValue, Expression *rightValue);

    double calculate();
};
#endif //PROJECT_PLUS_H
