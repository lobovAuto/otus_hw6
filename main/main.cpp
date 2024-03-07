#include "main.hpp"

const unsigned int COUNT=10;

template <typename T> void print_info(Container<T> & con, std::string name){
    std::cout<<name<<" size is "<<con.size()<<std::endl;
    for (unsigned int i=0; i<con.size(); i++) {
        std::cout<<con[i]<<" ";
    }
    std::cout<<std::endl;
}

template <typename T> void code_demonstration(Container<T> & con, std::string name){
    std::cout<<"Демонстрация пользовательского кода с";
    if (name=="vector"){std::cout<<" последовательным";}
    else {std::cout<<"о списковым";}
    std::cout<<" контейнером"<<std::endl;

    for (unsigned int i=0; i<COUNT; ++i){
        con.push_back(i);
    }

    print_info(con, name);
    std::cout<<"Удаление 3, 5 и 7 элементов"<<std::endl;
    con.erase(2);
    con.erase(3);
    con.erase(4);
    
    print_info(con, name);

    std::cout<<"Вставака 10 на нулевую позицию"<<std::endl;
    con.insert(10, 0);
    print_info(con, name);

    std::cout<<"Вставка 20 в середину контейнера"<<std::endl;
    con.insert(20, 4);
    print_info(con, name);

    std::cout<<"Вставка 30 в конец контейнера"<<std::endl;
    con.insert(30, 9);
    print_info(con, name);

    std::cout<<"Конец примера с "<<name<<std::endl;
}

template <typename T> void plus_minus(Iterator<T> & alloc){
    std::cout<<*alloc<<std::endl;
    std::cout<<"Пробуем уменьшить"<<std::endl;
    --alloc;
    std::cout<<*alloc<<std::endl;
    std::cout<<"Пробуем увеличить"<<std::endl;
    ++alloc;
    std::cout<<*alloc<<std::endl;
}

template <typename T> void code_alloc_demonstration(Iterator<T> & alloc, std::string name){
    std::cout<<"Демонстрация пользовательского кода с итератором для";
    if (name=="vector"){std::cout<<" последовательного";}
    else {std::cout<<" спискового";}
    std::cout<<" контейнера"<<std::endl;

    std::cout<<"Перемещаем итератор на начало"<<std::endl;
    alloc.begin();
    plus_minus(alloc);

    std::cout<<"Перемещаем итератор в конец"<<std::endl;
    alloc.end();
    plus_minus(alloc);
    std::cout<<"Конец примера с итератором"<<std::endl;
}

int main(/*int argc, char *argv[]*/){

    List<unsigned int> a;
    code_demonstration(a, "list");

    ListIter<unsigned int> list_it(a);
    code_alloc_demonstration(list_it, "list");

    Vector<unsigned int> b;
    code_demonstration(b, "vector");

    VectorIter<unsigned int> it(b);
    code_alloc_demonstration(it, "vector");

}