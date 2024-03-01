#include "main.hpp"

#define COUNT 10

template <typename T> void print_list(List<T> & list){
    std::cout<<"list size is "<<list.size()<<std::endl;
    for (unsigned int i=0; i<list.size(); i++) {
        std::cout<<list[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(/*int argc, char *argv[]*/){
    List<unsigned int> a;
    for (unsigned int i=0; i<COUNT; ++i){
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

}