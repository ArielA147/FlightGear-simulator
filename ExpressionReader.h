//
// Created by dvir on 12/17/18.
//

#ifndef PROJECT_EXPRESSIONREADER_H
#define PROJECT_EXPRESSIONREADER_H

#include <list>
#include <string>

using namespace std;

class ExpressionReader {

public:
    // returning liss of the expressions
    list<string> getExpression(list<string>::iterator &it);
};


#endif //PROJECT_EXPRESSIONREADER_H
