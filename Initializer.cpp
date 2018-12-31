//
// Created by dvir on 12/23/18.
//

#include "Initializer.h"

Initializer::Initializer() {

    this->commandDataBase = new CommandDataBase();
    this->parser = new Parser(this->commandDataBase);
    this->client = new Client();
    // initialize CommandMap
    initializeMap();
}

void Initializer::initializeMap() {

    // creating the open data server
    Command *openDataBase = new OpenDataServerCommand();
    this->commandDataBase->addCommand("openDataServer", openDataBase);
    // doing the connect - > after that we need to send the sockfd to client
    Command *connectCommand = new ConnectCommand(*this->client);
    this->commandDataBase->addCommand("connect", connectCommand);
// sending to the appending the client in order to know how to update client
    Command *appendCommand = new AppendCommand(this->client);
    this->commandDataBase->addCommand("updateVar", appendCommand);

    Command *ifCommand = new IfCommand(this->parser);
    this->commandDataBase->addCommand("if", ifCommand);

    Command *loopCommand = new LoopCommand(this->parser);
    this->commandDataBase->addCommand("while", loopCommand);

    Command *varCommand = new DefineVarCommand(appendCommand);
    this->commandDataBase->addCommand("var", varCommand);
}

void Initializer::start(string file_Path, char seperator) {
    ReadFromFile read(file_Path);
    list<string> input = read.readFile(); // list of all lines of the file
    Lexer l;
    list<string> tokens; // all the tokens of the file in one list
    for (string &line:input) {
        list<string> token = l.lexer(line, seperator);
        for (string &s : token) {
            tokens.push_back(s);
        }
    }

    this->parser->run(tokens);

}