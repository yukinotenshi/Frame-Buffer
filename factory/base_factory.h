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
    BaseFactory(std::string filename) : filename(filename), file(filename.c_str()) {}

    virtual ~BaseFactory() {file.close();};
    virtual  std::vector<T> generate() = 0;
};


#endif //FRAME_BUFFER_BASE_FACTORY_H
