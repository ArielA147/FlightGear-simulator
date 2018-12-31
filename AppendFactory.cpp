//
// Created by dvir on 12/20/18.
//

#include "AppendFactory.h"
/*
AppendFactory::AppendFactory(CommandDataBase &db) {
    this->db = db;
}

list<string> getVariablesValue(list<string> tokens,CommandDataBase &dataBase){
    list<string> res;
    // for each token in tokens, search for var's value and replace.
    for(list<string>::iterator it = tokens.begin(); it!= tokens.end();it++){
        // in cas variable is in data base.
        if(dataBase.getVarTable().count(*it) == 1){
            // get variable value.
            double argumentValue = dataBase.getValueFromTable(*it);
            res.push_back(to_string(argumentValue));
        }
        res.push_back(*it);
    }
    return res;
}

Command* AppendFactory::update(list<string>::iterator &it) {
    string varName = *it;
    it++;
    if(*it != "=")
        throw runtime_error("syntax error");
    it++;
    if(*it == "bind"){
        it++;
        if(this->db.getPathTable().count(*it) == 1){
            string path = this->db.getPathFromTable(*it);
            this->db.updatePath(varName,path);
        }
        else{
            this->db.updatePath(varName,*it);
        }
    }
    ExpressionReader er = ExpressionReader();
    // get variable value.
    list<string> expressionStr = er.getExpression(it);
    // variables names with their values.
    list<string> finalExpression = getVariablesValue(expressionStr,this->db);
    //ExpressionFactory exprFactory = ExpressionFactory(finalExpression);
    //Expression* e = exprFactory.create();
    //double value = e->calculate();
    // delete allocate memory.
   // delete e;
}

 */