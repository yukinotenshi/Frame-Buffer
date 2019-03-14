//
// Created by yukinotenshi on 3/14/2019.
//

#ifndef FRAME_BUFFER_BASE_EVENT_H
#define FRAME_BUFFER_BASE_EVENT_H


class BaseEvent {
public:
    char type;
    int value;
    int opt;

    BaseEvent(char type, int value, int opt) : type(type), value(value), opt(opt) {};
};


#endif //FRAME_BUFFER_BASE_EVENT_H
