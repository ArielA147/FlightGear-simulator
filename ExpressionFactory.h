//
// Created by dvir on 12/13/18.
//

#ifndef PROJECT_EXPRESSIONFACTORY_H
#define PROJECT_EXPRESSIONFACTORY_H


#include "Expression.h"
#include "CommandDataBase.h"
#include "SymbolTable.h"
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class ExpressionFactory {
    //CommandDataBase db;
public:
    //ExpressionFactory(CommandDataBase &db);

    Expression *create(list<string> tokens);

};
#endif //PROJECT_EXPRESSIONFACTORY_H
