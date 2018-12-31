//
// Created by dvir on 12/23/18.
//

#ifndef PROJECT_BINDVALUETABLE_H
#define PROJECT_BINDVALUETABLE_H

#include <string>
#include <map>
#include <mutex>
#include <iostream>
#include "MutexClass.h"

using namespace std;


class BindValueTable{
    map<string,double> bindValueTable;
    static BindValueTable *map_instance;
public:

    static inline BindValueTable *instance(){
        if(map_instance == nullptr){
            map_instance = new BindValueTable();
        }
        return map_instance;
    }

    inline const map<string, double > &getBIndTable() const{
        return this->bindValueTable;
    }

    inline void setValue(string key, double value){
        this->bindValueTable[key] = value;
    }

    inline double getValue(const string &key){
        if(this->bindValueTable.count(key) ==  1){
            double res = this->bindValueTable[key];
            return res;
        }
        else{
            throw runtime_error("var: " + key + "not exists");
        }
    }

    ~BindValueTable(){
        delete  map_instance;
    }
};
#endif //PROJECT_BINDVALUETABLE_H
