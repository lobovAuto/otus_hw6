#pragma once

#define BASE_ALLOC 10
template <class T> class Vector {
    unsigned int fact_syze;
    unsigned int alloc_syze;
    T * start;
    T * end;
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
    Vector(){
        start = new T[BASE_ALLOC];
        if (!start){fail();}
        alloc_syze=BASE_ALLOC;
    }
    unsigned int size(){return fact_syze;}
    void push_back(T t){
        if (alloc_syze==fact_syze){stratch();}
        start[fact_syze]=t;
        fact_syze++;
    }
    void insert(T t, unsigned int pos){
        if (alloc_syze==fact_syze){stratch();}
        for (unsigned int i=fact_syze; i>pos; --i){
            start[i]=start[i-1];
        }
        start[pos]=t;
        fact_syze++;
    }
    void erase(unsigned int pos){
        for (unsigned int i=pos; i<fact_syze; i++){
            start[i]=start[i+1];
        }
        fact_syze--;
    }
    T operator[](unsigned int pos){
        return start[pos];
    }
    ~Vector(){
        delete [] start;
    }
};