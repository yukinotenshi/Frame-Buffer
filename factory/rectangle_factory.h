//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_RECTANGLE_FACTORY_H
#define FRAME_BUFFER_RECTANGLE_FACTORY_H

#include "base_factory.h"
#include "../drawable/rectangle.h"

class RectangleFactory : BaseFactory<Rectangle> {
public:
    RectangleFactory(const std::string &filename);

    std::vector<Rectangle> generate() override;
};


#endif //FRAME_BUFFER_RECTANGLE_FACTORY_H
