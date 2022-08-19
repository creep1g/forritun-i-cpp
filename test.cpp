#include <iostream>
class RulingClass{
public:
    RulingClass();
    RulingClass(int number);
    RulingClass(int number, char letter);
};

int main(){
    RulingClass rc(4, 'c');
}


RulingClass::RulingClass(int number) : RulingClass(){
    std::cout << "One parameters" << std::endl;
}
RulingClass::RulingClass(){
    std::cout << "No parameters" << std::endl;
}
RulingClass::RulingClass(int number, char letter) : RulingClass(number){
    std::cout << "Two parameters" << std::endl;
}
