
#ifndef PROJECT_MINUS_H
#define PROJECT_MINUS_H

#include "BinaryExpression.h"

/**
 * this class represent minus expression,define print,evaluate and differentiate rules.
 */
class Minus : public BinaryExpression {
public:

    Minus(Expression* leftValue, Expression* rightValue);
/**
 * calculating the minus expression
 * @return result of the calculation
 */
    double calculate();
};


#endif //PROJECT_MINUS_H