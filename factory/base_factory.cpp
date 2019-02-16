//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "base_factory.h"

template <class T>
BaseFactory<T>::BaseFactory(const std::string &filename) : filename(filename) {
    file(filename.c_str());
}

template <class T>
BaseFactory<T>::~BaseFactory() {
    file.close();
}
