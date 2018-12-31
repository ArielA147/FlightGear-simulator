//
// Created by dvir on 12/18/18.
//

#include "Parser.h"
#include "CommandExpression.h"
#define UPDATE_VAR_COMMAND_KEY "updateVar"
#define END_OF_FILE "\\n"

Parser::Parser(CommandDataBase *db) {
    this->db = db;
}

void Parser::run(list<string> laxerCommands) {
    for(list<string>::iterator it = laxerCommands.begin(); it != laxerCommands.end();){
        Command* command = this->db->getCommand(*it);
        if(command != nullptr){
            CommandExpression* commandExpression = new CommandExpression(command,&it);
            commandExpression->calculate();
            //command->execute(it);
        }
        // if iterator pointing on variable.
        else if (SymbolTable::instance()->getVarTable().count(*it) == 1 ||
        BindTable::instance()->getBIndTable().count(*it) == 1){

            // call update var command in order to update variable.
            command = this->db->getCommand(UPDATE_VAR_COMMAND_KEY);
            if(command != nullptr){
                CommandExpression* commandExpression = new CommandExpression(command,&it);
                commandExpression->calculate();
                //command->execute(it);
            }
        }
        else{
            if(*it == END_OF_FILE)
                return;
            throw runtime_error("invalid command");
        }
    }
}
