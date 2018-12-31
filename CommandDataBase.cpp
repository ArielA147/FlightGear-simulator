//
// Created by dvir on 12/14/18.
//

#include <iostream>
#include "CommandDataBase.h"
#include "BindValueTable.h"

// return map.
const map<string, double> &CommandDataBase::getVarTable() const {
    return symbolTable;
}

// update or add var into map
void CommandDataBase::updateVar(string varName, double value) {
//    cout << "the value of the command db before updateing " +to_string(this->symbolTable[varName]) << endl;
    this->symbolTable[varName] = value;
//    cout << "the value of the command db after updateing " +            to_string(this->symbolTable[varName]) << endl;
}

// return value of specific var.
double CommandDataBase::getValueFromTable(const string &varName) {
    if (this->symbolTable.count(varName) == 1)
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
    cout << "the value of the path db before updateing " +
            (this->pathTable[varName]) << endl;
    this->pathTable[varName] = path;
    cout << "the value of the path db before updateing " +
            (this->pathTable[varName]) << endl;
}

// return value of specific var.
string CommandDataBase::getPathFromTable(const string &varName) {
    if (this->pathTable.count(varName) == 1)
        return this->pathTable[varName];
    else
        throw runtime_error("var: " + varName + "not exists");
}

const map<string, Command *> &CommandDataBase::getCommandTable() const {
    return commandTable;
}

// update or add command into map
void CommandDataBase::addCommand(string varName, Command *command) {
    this->commandTable[varName] = command;
}

Command *CommandDataBase::getCommand(const string &CommandName) {
    if (this->commandTable.count(CommandName) == 1)
        return this->commandTable[CommandName];
    else
        return nullptr;
}


CommandDataBase::CommandDataBase() {
    cout <<"hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"<<endl;
    //buildXmlMap();
}
/*
vector<string> CommandDataBase::getXmlPathKeyByXmlOrder() {
    vector<string> xmlPathInOrder;
    xmlPathInOrder.push_back(
            "/instrumentation/airspeed-indicator/indicated-speed-kt");
    xmlPathInOrder.push_back(
            "/instrumentation/altimeter/indicated-altitude-ft");
    xmlPathInOrder.push_back("/instrumentation/altimeter/pressure-alt-ft");
    xmlPathInOrder.push_back(
            "/instrumentation/attitude-indicator/indicated-pitch-deg");
    xmlPathInOrder.push_back(
            "/instrumentation/attitude-indicator/indicated-roll-deg");
    xmlPathInOrder.push_back(
            "/instrumentation/attitude-indicator/internal-pitch-deg");
    xmlPathInOrder.push_back(
            "/instrumentation/attitude-indicator/internal-roll-deg");
    xmlPathInOrder.push_back("/instrumentation/encoder/indicated-altitude-ft");
    xmlPathInOrder.push_back("/instrumentation/encoder/pressure-alt-ft");
    xmlPathInOrder.push_back("/instrumentation/gps/indicated-altitude-ft");
    xmlPathInOrder.push_back("/instrumentation/gps/indicated-ground-speed-kt");
    xmlPathInOrder.push_back("/instrumentation/gps/indicated-vertical-speed");
    xmlPathInOrder.push_back(
            "/instrumentation/heading-indicator/indicated-heading-deg");
    xmlPathInOrder.push_back(
            "/instrumentation/magnetic-compass/indicated-heading-deg");
    xmlPathInOrder.push_back(
            "/instrumentation/slip-skid-ball/indicated-slip-skid");
    xmlPathInOrder.push_back(
            "/instrumentation/turn-indicator/indicated-turn-rate");
    xmlPathInOrder.push_back(
            "/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
    xmlPathInOrder.push_back("/controls/flight/aileron");
    xmlPathInOrder.push_back("/controls/flight/elevator");
    xmlPathInOrder.push_back("/controls/flight/rudder");
    xmlPathInOrder.push_back("/controls/flight/flaps");
    xmlPathInOrder.push_back("/controls/engines/engine/throttle");
    xmlPathInOrder.push_back("/engines/engine/rpm");
    return xmlPathInOrder;
}
*/
/*
void CommandDataBase::setXmlPathMap(string key, double value) {
    cout << "----------------------------checking the xmp ptha map updating"
         << endl;
//    pthread_mutex_t *mutex = MutexClass::getInstance()->getMutex();
//    pthread_mutex_lock(mutex);

    cout << "the mutex is on ! " << endl;
    cout << "the key : " + key << endl;
    cout <<"does the key exsist in the bind table : " +to_string
    (BindValueTable::instance()->getBIndTable().count(key) )<<endl;
    if (BindValueTable::instance()->getBIndTable().count(key) == 1) {
        BindValueTable::instance()->setValue(key, value);
        cout << "done setting" << to_string(BindValueTable::instance()->getValue
        (key))
        << endl;
    }
    cout<<"done seeting the xml path map" << endl;
//    pthread_mutex_unlock(mutex);

}*/