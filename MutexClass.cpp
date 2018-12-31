//
// Created by ariel on 12/28/18.
//

#include "MutexClass.h"

MutexClass* MutexClass :: instance = NULL;

MutexClass* MutexClass ::getInstance() {

    if(instance == 0) {

        instance = new MutexClass();
    }

    return instance;
}

pthread_mutex_t* MutexClass :: getMutex() {

    return &mutex1;
}