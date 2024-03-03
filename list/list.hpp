#pragma once

#include "container.hpp"

template <class T> class List;
template <class T> class ListIter;
template <class T> class Elem{
    friend class List<T>;
    friend class ListIter<T>;
    T elem;
    Elem<T> * prev;
    Elem<T> * next;
public:
    Elem<T>(const T element):elem(element), prev(nullptr), next(nullptr){}
    void set_next(Elem<T> *n){ next = n;}
    void set_prev(Elem<T> *n){ prev = n;}
    Elem * get_next (){return next;}
    Elem * get_prev (){return prev;}
    T get_value(){return elem;}
};

template <class T> class List : public Container<T>{
private:
    friend class ListIter<T>;
    Elem<T> * start;
    Elem<T> * end;
    unsigned int list_size;
public:
    List():start(nullptr), end(nullptr), list_size(0){}
    List(T t):start(nullptr), end(nullptr), list_size(0){
        list_size++;
        auto temp = new T(t);
        auto pe = new Elem<T>(temp);
        start=end=pe;
    }
    void push_back(const T elem){
        if (list_size == 0){
            list_size ++;
            auto pe = new Elem<T>(elem);
            start=end=pe;
            start->set_next(end);
            end->set_prev(start);
            return;
        }
        list_size ++;
        auto pe = new Elem<T>(elem);
        end->set_next(pe);
        pe->set_prev(end);
        end = pe;
    }

    void insert(const T t, unsigned int pos){
        if (pos>list_size){throw "error with list size";}
        if (!pos){
            auto pe = new Elem<T>(t);
            start->set_prev(pe);
            pe->set_next(start);
            start=pe;
        } else if (pos==(list_size)) {
            push_back(t);
            return;
        } else {
            auto target = start; 
            for (unsigned int i = 0; i<pos; ++i){
                target = target->get_next();
            }
            auto pe = new Elem<T>(t);
            (target->get_prev())->set_next(pe);
            pe->set_prev(target->get_prev());
            target->set_prev(pe);
            pe->set_next(target);
            
        }
        list_size ++;
    }

    void erase(unsigned int in){
        if (list_size == 0){throw "list is empty";}
        if ((in==0)&&(list_size==1)){
            delete start;
            start=end=nullptr;
        }else if (in == 0){
            (start->get_next())->set_prev(nullptr);
            auto temp = start;
            start=start->get_next();
            delete temp;
        } else if ((in+1)==list_size){
            auto temp = end;
            (end->get_prev())->set_next(nullptr);
            end = end->get_prev();
            delete temp;
        } else {
            auto target = start;
            for (unsigned int i=0; i<=in; ++i){
                if (i==0) continue;
                target=target->get_next();
            }
            (target->get_prev())->set_next(target->get_next());
            if (target->get_next()==nullptr){
                (target->get_prev())->set_next(nullptr);
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
        auto target = start;
        for (unsigned int i=0; i<in; ++i){
            target = target->get_next();
        }
        if (target==nullptr){return 0;}
        return (target->get_value());
    }
    void pop_back(){
        if (!list_size){throw "list is eq zero. you cant pop it!";}
        auto pe = end;
        if (end==start){
            delete end;
            start=end=nullptr;
        } else {
        (end->get_prev())->set_next(nullptr);
        end=end->get_prev();
        delete pe;
        }
        list_size--;
    }

    ~List(){
        while (list_size){
            pop_back();
        }
    }
};

template<class T> class ListIter : public Iterator<T>{
    List<T> & list;
    Elem<T> * pnt; 
public:
    ListIter(List<T> & t):list(t){}
    void begin(){pnt = list.start;}
    void end(){pnt = list.end;}
    T operator*(){return pnt->get_value();}
    ListIter & operator++(){
        if (pnt->next==nullptr){return *this;}
        pnt = pnt->get_next();
        return *this;    
    }
    ListIter & operator--(){
        if (pnt->prev==nullptr){return *this;}
        pnt = pnt->get_prev();
        return *this;  
    }
};