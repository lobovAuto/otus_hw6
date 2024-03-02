#include "main.hpp"

#define COUNT 10

template <typename T> void print_info(Container<T> & con, std::string name){
    std::cout<<name<<" size is "<<con.size()<<std::endl;
    for (unsigned int i=0; i<con.size(); i++) {
        std::cout<<con[i]<<" ";
    }
    std::cout<<std::endl;
}

template <typename T> void code_demonstration(Container<T> & con, std::string name){
    std::cout<<"Демонтсрация пользовательского кода с";
    if (name=="vector"){std::cout<<" последовательным";}
    else {std::cout<<"о списковым";}
    std::cout<<" контейнером"<<std::endl;
    for (unsigned int i=0; i<COUNT; ++i){
        con.push_back(i);
    }

    print_info(con, name);
    con.erase(2);
    con.erase(3);
    con.erase(4);
    
    print_info(con, name);

    con.insert(10, 0);
    print_info(con, name);

    con.insert(20, 4);
    print_info(con, name);

    con.insert(30, 9);
    print_info(con, name);
}

int main(/*int argc, char *argv[]*/){

    List<unsigned int> a;
    code_demonstration(a, "list");

    Vector<unsigned int> b;
    code_demonstration(b, "vector");

    std::cout<<"Демонстрация пользовательского кода с итератором"<<std::endl;

    VectorAlloc<unsigned int> it(b);
    it.end();
    std::cout<<*it<<std::endl;
    ++it;
    std::cout<<*it<<std::endl;
    --it;
    std::cout<<*it<<std::endl;
}