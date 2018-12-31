//
// Created by ariel on 12/28/18.
//

#ifndef PROJECT_MUTEXCLASS_H
#define PROJECT_MUTEXCLASS_H

#include <sys/types.h>
#include <pthread.h>

class MutexClass {

    pthread_mutex_t mutex1;
    static MutexClass* instance;

    MutexClass() {
        mutex1 = PTHREAD_MUTEX_INITIALIZER;
    }

public:
/**
 *
 * @return
 */
    static MutexClass* getInstance();
   /**
    *
    * @return pthread mutex
    */
    pthread_mutex_t* getMutex();

};


#endif //PROJECT_MUTEXCLASS_H
