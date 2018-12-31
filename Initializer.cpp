//
// Created by dvir on 12/23/18.
//

#include "Initializer.h"

Initializer::Initializer() {
    buildXmlMap();
    this->commandDataBase = new CommandDataBase();
    this->parser = new Parser(this->commandDataBase);
    this->client = new Client();
    initializeMap();     // initialize CommandMap

}

/*
 * the order of doing things  - >
 *  need to create a connection to the server - > connect as client - >
 *  creating the other commands
 */
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

    Command *sleepCommand = new SleepCommand();
    this->commandDataBase->addCommand("sleep", sleepCommand);

    Command *printCommand = new PrintCommand();
    this->commandDataBase->addCommand("print", printCommand);
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

void Initializer::buildXmlMap() {
    cout << "inittttttttttt" << endl;
    BindValueTable *bindValueTable = BindValueTable::instance();
    bindValueTable->setValue(
            "/instrumentation/airspeed-indicator/indicated-speed-kt", 0);
    bindValueTable->setValue("/instrumentation/altimeter/indicated-altitude-ft",
                             0);
    bindValueTable->setValue("/instrumentation/altimeter/pressure-alt-ft", 0);
    bindValueTable->setValue(
            "/instrumentation/attitude-indicator/indicated-pitch-deg", 0);
    bindValueTable->setValue(
            "/instrumentation/attitude-indicator/indicated-roll-deg", 0);
    bindValueTable->setValue(
            "/instrumentation/attitude-indicator/internal-pitch-deg", 0);
    bindValueTable->setValue(
            "/instrumentation/attitude-indicator/internal-roll-deg", 0);
    bindValueTable->setValue("/instrumentation/encoder/indicated-altitude-ft",
                             0);
    bindValueTable->setValue("/instrumentation/encoder/pressure-alt-ft", 0);
    bindValueTable->setValue("/instrumentation/gps/indicated-altitude-ft", 0);
    bindValueTable->setValue("/instrumentation/gps/indicated-ground-speed-kt",
                             0);
    bindValueTable->setValue("/instrumentation/gps/indicated-vertical-speed",
                             0);
    bindValueTable->setValue(
            "/instrumentation/heading-indicator/indicated-heading-deg", 0);
    bindValueTable->setValue(
            "/instrumentation/magnetic-compass/indicated-heading-deg", 0);
    bindValueTable->setValue(
            "/instrumentation/slip-skid-ball/indicated-slip-skid", 0);
    bindValueTable->setValue(
            "/instrumentation/turn-indicator/indicated-turn-rate", 0);
    bindValueTable->setValue(
            "/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0);
    bindValueTable->setValue("/controls/flight/aileron", 0);
    bindValueTable->setValue("/controls/flight/elevator", 0);
    bindValueTable->setValue("/controls/flight/rudder", 0);
    bindValueTable->setValue("/controls/flight/flaps", 0);
    bindValueTable->setValue("/controls/engines/current-engine/throttle",0);
//    bindValueTable->setValue("/controls/engines/engine/throttle", 0);
    bindValueTable->setValue("/engines/engine/rpm", 0);
}

Initializer::~Initializer() {
    CommandDataBase *db = this->commandDataBase;
    for (auto it = db->getCommandTable().begin();
         it != db->getCommandTable().end(); it++) {
        if (it->second != nullptr)
            delete it->second;
    }
    delete this->commandDataBase;
    if (this->parser != nullptr)
        delete this->parser;
    delete this->client;
}

