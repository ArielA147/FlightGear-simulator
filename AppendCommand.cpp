//
// Created by dvir on 12/18/18.
//

#include <iostream>
#include "AppendCommand.h"
#include "BindValueTable.h"
#include "Client.h"
#include "MutexClass.h"
#include <mutex>

#define DEFAULT_VALUE 0

AppendCommand::AppendCommand(Client *client) {
    this->client = client;
    this->expreFactory = new ExpressionFactory();
}

void AppendCommand::execute(list<string>::iterator &it) {
    // update variable value.
    string varName = *it;
    it++;
    if (*it != "=")
        throw runtime_error("syntax error");
    it++;
    if (*it == "bind") {
        it++;
        if (SymbolTable::instance()->getVarTable().count(*it) == 1) {
            string path = BindTable::instance()->getValue(*it);
            BindTable::instance()->setValue(varName, path);
            it++;
        } else {
            string path = it.operator*().substr(1, it.operator*().length() - 2);
            BindTable::instance()->setValue(varName, path);
            SymbolTable::instance()->setValue(varName, DEFAULT_VALUE);
            it++;
        }
    } else {

        ExpressionReader er = ExpressionReader();
        // get variable value.
        list<string> expressionStr = er.getExpression(it);
        // variables names with their values.
        //ExpressionFactory exprFactory = ExpressionFactory(this->dataBase);
        Expression *e = this->expreFactory->create(expressionStr);


        pthread_mutex_t *mutex = MutexClass::getInstance()->getMutex();
        pthread_mutex_lock(mutex);
        double value = e->calculate();
        delete e;

        SymbolTable::instance()->setValue(varName, value);
        if (BindTable::instance()->getBIndTable().count(varName) == 1) {
            string path = BindTable::instance()->getValue(varName);
            if (path != "") {
                string message = "set " + path + " " + to_string(value) +
                                 "\r\n";
                this->client->sentMsg(message);
            }
        }
        pthread_mutex_unlock(mutex);
    }

}

AppendCommand::~AppendCommand() {
    delete this->expreFactory;
}