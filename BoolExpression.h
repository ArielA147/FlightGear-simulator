//
// Created by dvir on 12/15/18.
//

#ifndef PROJECT_BOOLEXPRESSION_H
#define PROJECT_BOOLEXPRESSION_H


#include "BinaryExpression.h"

class BoolExpression : public BinaryExpression {
    string condition_op;
public:
    BoolExpression(Expression *leftValue,string condition_op ,Expression *rightValue);
/**
 * calculating the value of the expression
 * @return
 */
    double calculate();

};



#endif //PROJECT_BOOLEXPRESSION_H
