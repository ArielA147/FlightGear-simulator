//
// Created by dvir on 12/19/18.
//

#include "OpenDataServerCommand.h"

void* thread_func(void* args){
    struct ServerArguments* params = (struct ServerArguments*)args;

    CreateServer server(params->portNum, params->waitTime);
    server.execute();
    delete params;
    return nullptr;
}


void OpenDataServerCommand::execute(list<string>::iterator &it) {
    ExpressionReader er = ExpressionReader();
    ExpressionFactory factory = ExpressionFactory();
    // skip commend Name;
    it++;
    list<string> portExpression = er.getExpression(it);
    // in case there is a separator between 2 expressions, skip separator.
    if(*it == ","){
        it++;
    }
    list<string> waitTimeExpression = er.getExpression(it);

    Expression *e1 = factory.create(portExpression);
    int portNum = (int) e1->calculate();
    Expression *e2 = factory.create(waitTimeExpression);
    int waitTime = (int) e2->calculate();

    delete  e1;
    delete  e2;
//    cout << "the waiting time is : "+ to_string(waitTime)<<endl;

    struct ServerArguments *serverParam = new ServerArguments();
    serverParam->portNum = portNum;
    serverParam->waitTime = waitTime;

    pthread_t  trid;
    pthread_create(&trid, nullptr, thread_func,serverParam);
//    pthread_join(trid, nullptr); // too : to delete this - cause we work in
// the main thread and not needed to join in here

    return ;
}