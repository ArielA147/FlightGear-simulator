#ifndef PROJECT_EXPRESSION_H
#define PROJECT_EXPRESSION_H


#include <map>
#include <list>
#include <string>

using namespace std;

// Expression interface
class Expression {
public:
    // Evaluate the expression and return the result.
    virtual double calculate() = 0;
    virtual ~Expression(){}
};

#endif //PROJECT EXPRESSION_H