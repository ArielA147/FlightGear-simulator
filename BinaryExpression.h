
#ifndef PROJECT_BINARYEXPRESSION_H
#define PROJECT_BINARYEXPRESSION_H


#include "Expression.h"

/**
 * BinaryExpression represent all the expressions  that contain 2 variables.
 */
class BinaryExpression : public Expression {
protected:
    Expression *leftValue;
    Expression *rightValue;
public:
    BinaryExpression(Expression *leftValue, Expression *rightValue);

    //return the left Expression object.
    Expression *getLeftArgument();

    //return the right Expression object.
    Expression *getRightArgument();

    void setLeftValue(Expression *leftValue);

    void setRightValue(Expression *rightValue);

    ~BinaryExpression();
};


#endif //PROJECT_BINARYEXPRESSION_H
