//
// Created by yukinotenshi on 3/13/2019.
//

#ifndef FRAME_BUFFER_DOT_FACTORY_H
#define FRAME_BUFFER_DOT_FACTORY_H

#include "base_factory.h"
#include "../drawable/dot.h"

class DotFactory :  BaseFactory<Dot> {
public:
    DotFactory(std::string filename);

    ~DotFactory() {};

    std::vector<Dot> generate() override;
};


#endif //FRAME_BUFFER_DOT_FACTORY_H
