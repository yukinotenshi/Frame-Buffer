//
// Created by yukinotenshi on 3/14/2019.
//

#ifndef FRAME_BUFFER_KEYBOARD_EVENT_H
#define FRAME_BUFFER_KEYBOARD_EVENT_H


#include "base_event.h"

class KeyboardEvent : public BaseEvent {
public:
    KeyboardEvent(int value, int opt) : BaseEvent('k', value, opt) {};
};


#endif //FRAME_BUFFER_KEYBOARD_EVENT_H
