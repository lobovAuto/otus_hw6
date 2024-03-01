#include "main.hpp"

#define COUNT 10

template <typename T> void print_list(List<T> & list){
    for (unsigned int i=0; i<list.size(); i++) {
        std::cout<<list[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(/*int argc, char *argv[]*/){
    List<unsigned int> a;
    for (unsigned int i=0; i<COUNT; ++i){
        unsigned int * j= new unsigned int (i);
        a.push_back(j);
    }

    std::cout<<"list size is "<<a.size()<<std::endl;
    print_list(a);

    a.erase(2);
    a.erase(3);
    a.erase(4);
    std::cout<<"list size is "<<a.size()<<std::endl;
    print_list(a);
 
}