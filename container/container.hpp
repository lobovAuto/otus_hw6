#pragma once

template <class T> class Container{
private:
public:
    Container(){};
    virtual unsigned int size() const  = 0;
    virtual void push_back(T t) = 0;
    virtual void insert(T t, unsigned int pos) = 0;
    virtual void erase(unsigned int pos) = 0;
    virtual T operator[](unsigned int pos) = 0;
};