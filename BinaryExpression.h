
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
    /**
     * constractor
     * @param leftValue the left side of the expression
     * @param rightValue the right left side of the expression
     */
    BinaryExpression(Expression *leftValue, Expression *rightValue);

    /**
     *
     * @return the left Expression object.
     */
    Expression *getLeftArgument();

/**
 *
 * @return    the right Expression object.
 */
    Expression *getRightArgument();
/**
 * sets the left side of the expression
 * @param leftValue expression
 */
    void setLeftValue(Expression *leftValue);
/**
 * sets the right side of the expression
 * @param rightValue expression
 */
    void setRightValue(Expression *rightValue);

    ~BinaryExpression();
};


#endif //PROJECT_BINARYEXPRESSION_H
