//
// Created by dvir on 12/14/18.
//

#include "DefineVarCommand.h"
#include "SymbolTable.h"

#define DEFAULT_VALUE 0
#define END_OF_FILE "\\n"


DefineVarCommand::DefineVarCommand(Command *appendCommand) {
    this->appendCommand = appendCommand;
}

void DefineVarCommand::execute(list<string>::iterator &it) {
    it++;
    string varName = *it;
    if(*it == END_OF_FILE){
        SymbolTable::instance()->setValue(varName,DEFAULT_VALUE);
        return;
    }
    it++;
    if(*it == "="){
        it--;
        appendCommand->execute(it);
    }
    else{
        SymbolTable::instance()->setValue(varName,DEFAULT_VALUE);
    }
}
