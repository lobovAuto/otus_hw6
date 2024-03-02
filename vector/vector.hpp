#pragma once

#include "container.hpp"

#define BASE_ALLOC 10

template <class T> class VectorAlloc;
template <class T> class Vector : public Container<T> {
    friend class VectorAlloc<T>;

    unsigned int fact_syze;
    unsigned int alloc_syze;
    T * start;
    T * end;
    T * get_start(){return start;}
    T * get_end(){return end;}
    void update_end(){end=start+fact_syze-1;}
    void fail(){
        std::cerr<<"Нехватка памяти!"<<std::endl;
        exit(-1);
    }
    void stratch(){
        unsigned int new_size = alloc_syze*2;
        T * new_start = new T[new_size];
        if (!new_start){fail();}
        for (unsigned int i=0; i<fact_syze; i++){
            new_start[i]=start[i];
        }
        delete [] start;
        start = new_start;
        alloc_syze=new_size;
    }
public:
    Vector():fact_syze(0){
        start = new T[BASE_ALLOC];
        if (!start){fail();}
        end = start+fact_syze;
        alloc_syze=BASE_ALLOC;
    }
    unsigned int size() const {return fact_syze;}
    void push_back(T t){
        if (alloc_syze==fact_syze){stratch();}
        start[fact_syze]=t;
        fact_syze++;
        update_end();
    }
    void insert(T t, unsigned int pos){
        if (alloc_syze==fact_syze){stratch();}
        for (unsigned int i=fact_syze; i>pos; --i){
            start[i]=start[i-1];
        }
        start[pos]=t;
        fact_syze++;
        update_end();
    }
    void erase(unsigned int pos){
        for (unsigned int i=pos; i<fact_syze; i++){
            start[i]=start[i+1];
        }
        fact_syze--;
        update_end();
    }
    T operator[](unsigned int pos){
        return start[pos];
    }
    ~Vector(){
        delete [] start;
    }
};

template <class T> class VectorAlloc{
    Vector<T> & vector;
    T * pnt;
public:
    VectorAlloc(Vector<T> & t):vector(t){}
    void begin(){pnt = vector.get_start();}
    void end(){pnt = vector.get_end();}
    T operator*(){return *pnt;}
    VectorAlloc & operator++(){
        if (pnt==vector.get_end()){return *this;}
        pnt = pnt + 1;
        return *this;    
    }
    VectorAlloc & operator--(){
        if (pnt==vector.get_start()){return *this;}
        pnt = pnt - 1;
        return *this;  
    }
};