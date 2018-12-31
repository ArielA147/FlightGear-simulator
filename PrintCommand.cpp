//
// Created by dvir on 12/25/18.
//


#include "PrintCommand.h"

void PrintCommand::execute(list<string>::iterator &it) {
    // skip print command
    it++;
    if(it.operator*().substr(0,1) == "\""){
        cout << it.operator*().substr(1,it.operator*().length() - 2) << endl;
        it++;
    }
    else{
        ExpressionReader er =  ExpressionReader();
        ExpressionFactory factory = ExpressionFactory();
        list<string> expressionStr = er.getExpression(it);
        Expression* exp = factory.create(expressionStr);
        cout<<"print command print without \\ :" ;
        cout << exp->calculate() << endl;

    }

}