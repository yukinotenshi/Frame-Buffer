//
// Created by yukinotenshi on 3/14/2019.
//

#ifndef FRAME_BUFFER_BASE_DISPATCHER_H
#define FRAME_BUFFER_BASE_DISPATCHER_H


#include "../controller/main_controller.h"

class BaseDispatcher {
protected:
    MainController * controller;
    bool isStopped;
public:
    BaseDispatcher(MainController * controller) {this->controller = controller; isStopped = false;}

    virtual void run() = 0;

    void stop() {
        isStopped = true;
    }
};


#endif //FRAME_BUFFER_BASE_DISPATCHER_H
