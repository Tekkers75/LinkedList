#pragma once
#include <iostream>


template <typename T>
class AbstractIterator {
public:
    virtual T& operator*() = 0;
    virtual AbstractIterator<T>& operator++() = 0;
    virtual AbstractIterator<T>& operator++(int) = 0;
    virtual bool operator==(const AbstractIterator<T>& other) = 0;
    virtual bool operator!=(const AbstractIterator<T>& other) = 0;
    virtual ~AbstractIterator() {}

    //virtual AbstractIterator<T>& begin() = 0;
    //virtual AbstractIterator<T>& end() = 0;
};

template<typename T>
class AbstractIterated {
public:
    virtual AbstractIterator<T>& begin() const = 0;
    virtual AbstractIterator<T>& end() const = 0;
};