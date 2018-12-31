//
// Created by dvir on 12/22/18.
//

#ifndef PROJECT_SYMBOLTABLE_H
#define PROJECT_SYMBOLTABLE_H

#include <string>
#include <map>
#include <mutex>
#include <iostream>
#include "MutexClass.h"

using namespace std;

class SymbolTable {
    map<string,double> symbolTable;
    static SymbolTable *map_instance;
public:
    static inline SymbolTable *instance(){
        if(map_instance == nullptr){
            map_instance = new SymbolTable();
        }
        return map_instance;
    }
    inline const map<string, double> &getVarTable() const{
        return this->symbolTable;
    }
    inline void setValue(string key, double value){
        //pthread_mutex_t* mutex = MutexClass::getInstance()->getMutex();
        //pthread_mutex_lock(mutex);
//        cout <<"the value of the symbol table db before updateing " + to_string(this->symbolTable[key]) <<endl;

        this->symbolTable[key] = value;

//        cout <<"the value of the symbol Table db before updateing " +        to_string(this->symbolTable[key]) <<endl;
       // pthread_mutex_unlock(mutex);
    }
    inline double getValue(const string &key){
       // pthread_mutex_t* mutex = MutexClass::getInstance()->getMutex();
       // pthread_mutex_lock(mutex);
        double temp;
        if(this->symbolTable.count(key) ==  1){
            temp = this->symbolTable[key];
            //pthread_mutex_unlock(mutex);
            return temp;
        }

        else{
          // pthread_mutex_unlock(mutex);
            throw runtime_error("var: " + key + "not exists");
        }

    }

    ~SymbolTable(){
        delete  map_instance;
    }
};


#endif //PROJECT_SYMBOLTABLE_H
