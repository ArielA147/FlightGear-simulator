//
// Created by dvir on 12/23/18.
//

#ifndef PROJECT_INITIALIZER_H
#define PROJECT_INITIALIZER_H

#include "Parser.h"
#include "AppendCommand.h"
#include "OpenDataServerCommand.h"
#include "ConnectCommand.h"
#include "IfCommand.h"
#include "LoopCommand.h"
#include "DefineVarCommand.h"
#include "ReadFromFIle.h"
#include "Lexer.h"
#include "Client.h"
#include "SleepCommand.h"
#include "PrintCommand.h"

class Initializer {
    Parser* parser;
    Client* client;
    CommandDataBase* commandDataBase;
public:
    Initializer();
    void start(string Path, char seperator);
    void initializeMap();
    void buildXmlMap();
    ~Initializer();
};


#endif //PROJECT_INITIALIZER_H
