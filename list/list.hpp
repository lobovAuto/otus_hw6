#pragma once

template <class T> class List;

template <class T> class Elem{
    friend class List<T>;
    T * elem;
    T * prev;
    T * next;
public:
    Elem<T>(){

    }
    Elem<T>(T * t){

    }
    Elem<T>(T * t, Elem *n){

    }
    //Вероятно, еще парочку надо
};

template <class T> class List{
private:
    T * start;
    T * end;
    unsigned int list_size=0;
public:
    void push_back(T obj){

    }
    void insert(T obj){

    }
    void erase(unsigned int){

    }
    unsigned int size(){return list_size;}
    
    T operator[](unsigned int){
        return NULL;
    }
};