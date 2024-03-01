#include "main.hpp"

#define COUNT 10

int main(/*int argc, char *argv[]*/){
    List<unsigned int> a;
    for (unsigned int i=0; i<COUNT; ++i){
        unsigned int * j= new unsigned int (i);
        a.push_back(j);
    }
    std::cout<<"list size is "<<a.size()<<std::endl;
    for (unsigned int i=0; i<COUNT; ++i){
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}