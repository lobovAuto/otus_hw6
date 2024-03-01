#pragma once

template <class T> class List;

template <class T> class Elem{
    friend class List<T>;
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
    //Вставка после n
    Elem<T>(T * t, Elem *n){
        elem = t;
        prev = n;
        n->set_next(this);
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
    //Вероятно, еще парочку надо
};

template <class T> class List{
private:
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
    void insert(T *t, unsigned int pos){
        list_size ++;
        Elem<T> * target = start; //менять на Elem
        for (unsigned int i = 0; i<pos; ++i){
            target = target->get_next();
        }
        Elem<T> * pe = new Elem<T>(t, target);
        (target->get_prev())->set_next(pe);
        target->set_prev(pe);
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
    unsigned int size(){return list_size;}
    
    T operator[](unsigned int in){
        if (in>=list_size){return 0;}
        Elem<T> * target = start;
        for (unsigned int i=0; i<in; ++i){
            // if (target->get_next()==NULL){continue;}
            target = target->get_next();
        }
        if (target==NULL){return 0;}
        return *(target->get_value());
    }
};