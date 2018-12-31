//
// Created by dvir on 12/13/18.
//

#ifndef PROJECT_MULT_H
#define PROJECT_MULT_H


#include "BinaryExpression.h"

class Mult : public BinaryExpression {
public:
    Mult(Expression *leftValue, Expression *rightValue);
/**
 * calculating the multiple expression
 * @return result of the calculation
 */
    double calculate();
};

#endif //PROJECT_MULT_H
