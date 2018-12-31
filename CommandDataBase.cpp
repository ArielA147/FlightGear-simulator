//
// Created by dvir on 12/14/18.
//

#include "CommandDataBase.h"

// return map.
const map<string, double> &CommandDataBase::getVarTable() const {
    return symbolTable;
}

// update or add var into map
void CommandDataBase::updateVar(string varName, double value) {
    this->symbolTable[varName] = value;
}

// return value of specific var.
double CommandDataBase::getValueFromTable(const string &varName) {
    if(this->symbolTable.count(varName) ==  1)
        return this->symbolTable[varName];
    else
        throw runtime_error("var: " + varName + "not exists");
}

// return map.
const map<string, string> &CommandDataBase::getPathTable() const {
    return pathTable;
}

// update or add var into map
void CommandDataBase::updatePath(string varName, string path) {
    this->pathTable[varName] = path;
}

// return value of specific var.
string CommandDataBase::getPathFromTable(const string &varName) {
    if(this->pathTable.count(varName) ==  1)
        return this->pathTable[varName];
    else
        throw runtime_error("var: " + varName + "not exists");
}

const map<string, Command*>& CommandDataBase::getCommandTable() const {
    return commandTable;
}

// update or add command into map
void CommandDataBase::addCommand(string varName, Command *command){
    this->commandTable[varName] = command;
}

Command* CommandDataBase::getCommand(const string &CommandName) {
    if(this->commandTable.count(CommandName) ==  1)
        return this->commandTable[CommandName];
    else
        return nullptr;
}








CommandDataBase::CommandDataBase() {
    buildXmlMap();
}

vector<string> CommandDataBase::getXmlPathKeyByXmlOrder() {
    vector<string> xmlPathInOrder;
    xmlPathInOrder.push_back("/instrumentation/airspeed-indicator/indicated-speed-kt");
    xmlPathInOrder.push_back("/instrumentation/altimeter/indicated-altitude-ft");
    xmlPathInOrder.push_back("/instrumentation/altimeter/pressure-alt-ft");
    xmlPathInOrder.push_back("/instrumentation/attitude-indicator/indicated-pitch-deg");
    xmlPathInOrder.push_back("/instrumentation/attitude-indicator/indicated-roll-deg");
    xmlPathInOrder.push_back("/instrumentation/attitude-indicator/internal-pitch-deg");
    xmlPathInOrder.push_back("/instrumentation/attitude-indicator/internal-roll-deg");
    xmlPathInOrder.push_back("/instrumentation/encoder/indicated-altitude-ft");
    xmlPathInOrder.push_back("/instrumentation/encoder/pressure-alt-ft");
    xmlPathInOrder.push_back("/instrumentation/gps/indicated-altitude-ft");
    xmlPathInOrder.push_back("/instrumentation/gps/indicated-ground-speed-kt");
    xmlPathInOrder.push_back("/instrumentation/gps/indicated-vertical-speed");
    xmlPathInOrder.push_back("/instrumentation/heading-indicator/indicated-heading-deg");
    xmlPathInOrder.push_back("/instrumentation/magnetic-compass/indicated-heading-deg");
    xmlPathInOrder.push_back("/instrumentation/slip-skid-ball/indicated-slip-skid");
    xmlPathInOrder.push_back("/instrumentation/turn-indicator/indicated-turn-rate");
    xmlPathInOrder.push_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
    xmlPathInOrder.push_back("/controls/flight/aileron");
    xmlPathInOrder.push_back("/controls/flight/elevator");
    xmlPathInOrder.push_back("/controls/flight/rudder");
    xmlPathInOrder.push_back("/controls/flight/flaps");
    xmlPathInOrder.push_back("/controls/engines/engine/throttle");
    xmlPathInOrder.push_back("/engines/engine/rpm");
    return xmlPathInOrder;
}

void CommandDataBase::buildXmlMap() {
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/airspeed-indicator/indicated-speed-kt",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/altimeter/indicated-altitude-ft",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/altimeter/pressure-alt-ft",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-pitch-deg",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-roll-deg",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-pitch-deg",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-roll-deg",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/encoder/indicated-altitude-ft",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/encoder/pressure-alt-ft",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/gps/indicated-altitude-ft",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/gps/indicated-ground-speed-kt",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/gps/indicated-vertical-speed",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/heading-indicator/indicated-heading-deg",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/magnetic-compass/indicated-heading-deg",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/slip-skid-ball/indicated-slip-skid",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/turn-indicator/indicated-turn-rate",0));
    this->xmlPathTable.insert(pair<string,double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm",0));
    this->xmlPathTable.insert(pair<string,double>("/controls/flight/aileron",0));
    this->xmlPathTable.insert(pair<string,double>("/controls/flight/elevator",0));
    this->xmlPathTable.insert(pair<string,double>("/controls/flight/rudder",0));
    this->xmlPathTable.insert(pair<string,double>("/controls/flight/flaps",0));
    this->xmlPathTable.insert(pair<string,double>("/controls/engines/engine/throttle",0));
    this->xmlPathTable.insert(pair<string,double>("/engines/engine/rpm",0));
}

void CommandDataBase::setXmlPathMap(string key, double value) {
    if(this->xmlPathTable.count(key)==1){
        this->xmlPathTable.at(key) = value;
    }
}