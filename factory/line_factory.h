//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_LINE_FACTORY_H
#define FRAME_BUFFER_LINE_FACTORY_H

#include "base_factory.h"
#include "../drawable/line.h"
#include <string>
#include <vector>

class LineFactory : BaseFactory<Line> {
public:
    LineFactory(std::string filename);

    ~LineFactory() {};

    std::vector<Line> generate() override;
};


#endif //FRAME_BUFFER_LINE_FACTORY_H
