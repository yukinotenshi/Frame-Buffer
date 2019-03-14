//
// Created by yukinotenshi on 3/14/2019.
//

#ifndef FRAME_BUFFER_KEYBOARD_DISPATCHER_H
#define FRAME_BUFFER_KEYBOARD_DISPATCHER_H

#include <ncurses.h>
#include <curses.h>
#include "base_dispatcher.h"
#include "../event/keyboard_event.h"

class KeyboardDispatcher : BaseDispatcher {
public:
    KeyboardDispatcher(MainController * controller) : BaseDispatcher(controller) {}

    void run() override {
        initscr();
        noecho();
        timeout(-1);
        while (!isStopped) {
            int c = getch();
            KeyboardEvent event(c, 0);
            if (controller != nullptr) {
                controller->dispatchEvent(event);
            }
        }
        endwin();
    }
};


#endif //FRAME_BUFFER_KEYBOARD_DISPATCHER_H
