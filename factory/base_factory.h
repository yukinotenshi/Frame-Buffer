//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_BASE_FACTORY_H
#define FRAME_BUFFER_BASE_FACTORY_H

#include <string>
#include <vector>
#include <fstream>

template <class T>
class BaseFactory {
protected:
    std::string filename;
    std::ifstream file;

public:
    BaseFactory(const std::string &filename);

    virtual ~BaseFactory();
    virtual  std::vector<T> generate() = 0;
};


#endif //FRAME_BUFFER_BASE_FACTORY_H
