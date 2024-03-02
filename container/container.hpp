#pragma once

template <class T> class Iterator;
template <class T> class Container{
private:
friend class Iterator<T>;
public:
    Container(){};
    virtual unsigned int size() const  = 0;
    virtual void push_back(T t) = 0;
    virtual void insert(T t, unsigned int pos) = 0;
    virtual void erase(unsigned int pos) = 0;
    virtual T operator[](unsigned int pos) = 0;
};

template <class T> class Iterator{
public:
    virtual void begin() = 0;
    virtual void end() = 0;
    virtual T operator*() = 0;
    virtual Iterator & operator++()=0;
    virtual Iterator & operator--()=0;
};