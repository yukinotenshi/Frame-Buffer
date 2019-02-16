//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_CIRCLE_FACTORY_H
#define FRAME_BUFFER_CIRCLE_FACTORY_H

#include "base_factory.h"
#include "../drawable/circle.h"

class CircleFactory : BaseFactory<Circle> {
public:
    CircleFactory(const std::string &filename);

    std::vector<Circle> generate() override;
};


#endif //FRAME_BUFFER_CIRCLE_FACTORY_H
