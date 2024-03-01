#include "main.hpp"

#define COUNT 10

template <typename T> void print_list(List<T> & list){
    std::cout<<"list size is "<<list.size()<<std::endl;
    for (unsigned int i=0; i<list.size(); i++) {
        std::cout<<list[i]<<" ";
    }
    std::cout<<std::endl;
}

template <typename T> void print_vec(Vector<T> & vec){
    std::cout<<"vector size is "<<vec.size()<<std::endl;
    for (unsigned int i=0; i<vec.size(); i++) {
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(/*int argc, char *argv[]*/){

    std::cout<<"Демонстрация пользовательского кода со списковым контейнером"<<std::endl;

    List<unsigned int> a((unsigned int)0);
    for (unsigned int i=1; i<COUNT; ++i){
        a.push_back(i);
    }

    print_list(a);

    a.erase(2);
    a.erase(3);
    a.erase(4);
    
    print_list(a);

    a.insert(10, 0);
    print_list(a);

    a.insert(20, 4);
    print_list(a);

    a.insert(30, 9);
    print_list(a);

    std::cout<<"Демонстрация пользовательского кода с последовательным контейнером"<<std::endl;

    Vector<unsigned int> b;
    for (unsigned int i=0; i<COUNT; ++i){
        b.push_back(i);
    }
    print_vec(b);
    b.erase(2);
    b.erase(3);
    b.erase(4);
    print_vec(b);

    b.insert(10,0);
    print_vec(b);

    b.insert(20,4);
    print_vec(b);
 
    b.insert(30,9);
    print_vec(b);

    std::cout<<"Демонстрация пользовательского кода с итератором"<<std::endl;

    VectorAlloc<unsigned int> it(b);
    it.end();
    std::cout<<*it<<std::endl;
    ++it;
    std::cout<<*it<<std::endl;
    --it;
    std::cout<<*it<<std::endl;
}