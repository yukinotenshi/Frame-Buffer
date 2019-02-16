//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_POLYGON_FACTORY_H
#define FRAME_BUFFER_POLYGON_FACTORY_H

#include "base_factory.h"
#include "../drawable/polygon.h"

class PolygonFactory : BaseFactory<Polygon> {
public:
    PolygonFactory(const std::string &filename);

    std::vector<Polygon> generate() override;
};


#endif //FRAME_BUFFER_POLYGON_FACTORY_H
