#pragma once
#include <iostream>


template <typename T>
class AbstractIterator {
public:
    virtual T& operator*() = 0;
    virtual AbstractIterator& operator++() = 0;
    virtual bool operator==(const AbstractIterator<T>& other) = 0;
    virtual bool operator!=(const AbstractIterator<T>& other) = 0;
    virtual ~AbstractIterator() {}
};

template<typename T>
class AbstractIterated {
    virtual AbstractIterated<T>& begin() = 0;
    virtual AbstractIterated<T>& end() = 0;
};