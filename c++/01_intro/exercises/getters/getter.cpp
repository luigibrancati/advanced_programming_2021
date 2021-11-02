#include <iostream>
#include <iomanip>

int get_int(){
    int input;
    while(!(std::cin>>input)){
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"The input value is not an integer"<<std::endl;
    }
    return input;
}

double get_double(){
    double input;
    while(!(std::cin>>input)){
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"The input value is not a decimal number"<<std::endl;
    }
    return input;
}

int main(){
    std::cout<<get_int()<<std::endl;
    std::cout<<get_double()<<std::endl;
    return 0;
}