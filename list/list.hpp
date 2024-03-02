#pragma once

#include "container.hpp"

template <class T> class List;
template <class T> class ListAlloc;
template <class T> class Elem{
    friend class List<T>;
    friend class ListAlloc<T>;
    T * elem;
    Elem<T> * prev;
    Elem<T> * next;
public:
    Elem<T>(){
        elem = NULL;
        next = NULL;
        prev = NULL;
    }
    Elem<T>(T * t){
        elem = t;
        next = NULL;
        prev = NULL;
    }
    ~Elem<T>(){
        delete elem;
    }
    void set_next(Elem *n){
        next = n;
    }
    void set_prev(Elem *n){
        prev = n;
    }
    Elem * get_next (){return next;}
    Elem * get_prev (){return prev;}
    T * get_value(){return elem;}
};

template <class T> class List : public Container<T>{
private:
    friend class ListAlloc<T>;
    Elem<T> * start;
    Elem<T> * end;
    unsigned int list_size=0;
public:
    List(){}
    List(T *t){
        list_size++;
        Elem<T> * pe = new Elem<T>(t);
        start=end=pe;
    }
    List(T t){
        list_size++;
        T * temp = new T(t);
        Elem<T> * pe = new Elem<T>(temp);
        start=end=pe;
    }
    void push_back(T * t){
        if (!list_size){
            list_size ++;
            Elem<T> * pe = new Elem<T>(t);
            start=end=pe;
            start->set_next(end);
            end->set_prev(start);
            return;
        }
        list_size ++;
        Elem<T> * pe = new Elem<T>(t);
        end->set_next(pe);
        pe->set_prev(end);
        end = pe;
    }
    void push_back(T t){
        T * temp = new T (t);
        push_back(temp);
    }
    void insert(T *t, unsigned int pos){
        if (!pos){
            Elem<T> * pe = new Elem<T>(t);
            start->set_prev(pe);
            pe->set_next(start);
            start=pe;
        } else if (pos==list_size) {
            push_back(t);
            return;
        } else {
            Elem<T> * target = start; 
            for (unsigned int i = 0; i<pos; ++i){
                target = target->get_next();
            }
            Elem<T> * pe = new Elem<T>(t);
            (target->get_prev())->set_next(pe);
            pe->set_prev(target->get_prev());
            target->set_prev(pe);
            pe->set_next(target);
            
        }
        list_size ++;
    }
    void insert(T t, unsigned int pos){
        T * temp = new T (t);
        insert(temp, pos);
    }
    void erase(unsigned int in){
        if (!list_size){return;}
        if (!in){
            (start->get_next())->set_prev(NULL);
            Elem<T> * temp = start;
            start=start->get_next();
            delete temp;
        } else if (in==list_size){
            Elem<T> * temp = end;
            (end->get_prev())->set_next(NULL);
            end = end->get_prev();
            delete temp;
        } else {
            Elem<T> * target = start;
            for (unsigned int i=0; i<=in; ++i){
                if (i==0) continue;
                target=target->get_next();
            }
            (target->get_prev())->set_next(target->get_next());
            if (target->get_next()==NULL){
                (target->get_prev())->set_next(NULL);
            } else {
                (target->get_next())->set_prev(target->get_prev());
            }
            delete target;
        }
        list_size--;
        
    }
    unsigned int size() const {return list_size;}
    T operator[](unsigned int in){
        if (in>=list_size){return 0;}
        Elem<T> * target = start;
        for (unsigned int i=0; i<in; ++i){
            target = target->get_next();
        }
        if (target==NULL){return 0;}
        return *(target->get_value());
    }
    void pop_back(){
        if (!list_size){return;}
        Elem<T> * pe = end;
        if (end==start){
            delete end;
            start=end=NULL;
        } else {
        (end->get_prev())->set_next(NULL);
        end=end->get_prev();
        delete pe;
        }
        list_size--;
    }
    void back_step(){
        Elem<T> * pe = end;
        unsigned int count =0;
        std::cout<<"start debug"<<std::endl;
        while ((pe->get_prev())!=NULL){
            std::cout<< *(pe->get_value()) << " ";
            pe = pe->get_prev();
            count ++;
            if (count>list_size) {break;}
        }
        std::cout<<std::endl<<"stop debug"<<std::endl;
    }
    ~List(){
        while (list_size){
            pop_back();
        }
    }
};

template<class T> class ListAlloc : public Allocator<T>{
    List<T> & list;
    Elem<T> * pnt; //должна быть нода
public:
    ListAlloc(List<T> & t):list(t){}
    void begin(){pnt = list.start;}
    void end(){pnt = list.end;}
    T operator*(){return *pnt->get_value();}
    ListAlloc & operator++(){
        if (pnt->next==NULL){return *this;}
        pnt = pnt->get_next();
        return *this;    
    }
    ListAlloc & operator--(){
        if (pnt->prev==NULL){return *this;}
        pnt = pnt->get_prev();
        return *this;  
    }
};