//
// Created by dvir on 12/18/18.
//

#include <iostream>
#include "AppendCommand.h"
#include "BindValueTable.h"
#include "Client.h"
#include <mutex>

#define DEFAULT_VALUE 0

AppendCommand::AppendCommand(Client* client) {
    //this->dataBase = dataBase;
    this->client = client;
    this->expreFactory = new ExpressionFactory();
}

void AppendCommand::execute(list<string>::iterator &it) {
    // update variable value.
    string varName = *it;
    it++;
    if(*it != "=")
        throw runtime_error("syntax error");
    it++;
    if(*it == "bind") {
        it++;
        if (SymbolTable::instance()->getVarTable().count(*it) == 1) {
            string path = BindTable::instance()->getValue(*it);
            BindTable::instance()->setValue(varName, path);
            it++;
        } else {
            string path = it.operator*().substr(1, it.operator*().length() -2);
            BindTable::instance()->setValue(varName,path);
            SymbolTable::instance()->setValue(varName,DEFAULT_VALUE);
            it++;
        }
    }
    else{
        ExpressionReader er = ExpressionReader();
        // get variable value.
        list<string> expressionStr = er.getExpression(it);
        // variables names with their values.
        //ExpressionFactory exprFactory = ExpressionFactory(this->dataBase);
        Expression* e =  this->expreFactory->create(expressionStr);
        double value = e->calculate();

        //delete alloc
        // ate memory.
        //delete e;

//        mutex mtx;
//        mtx.lock();
        SymbolTable::instance()->setValue(varName,value);

        cout<< "i finished to update the symbol table" << endl;
        cout << "now the value in the symbole table after updating is  : " +
        to_string(SymbolTable::instance()->getValue(varName))<< endl;


        if(BindTable::instance()->getBIndTable().count(varName) == 1){
            string path = BindTable::instance()->getValue(varName);
            if(path != ""){
                string message = "set " + path + " " + to_string(value) +
                        "\r\n";
                //Client::sentMsg(message);
                this->client->sentMsg(message);
                cout << "this " + varName + " with path " + path + " "
                +to_string(value)<<endl;
            }
        }
//        mtx.unlock();

    }

}
