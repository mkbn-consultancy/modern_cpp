//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
//compilation line: g++ -std=c++98 cpp03_enum.cpp

#include <iostream>

enum Animals_e{ BEAR, CAT, CHICHEN};
enum Birds_e{EAGLE, DUCK, /*CHICHEN*/}; //error! chicken has already declared!

enum Colors_e{RED='r', BLUE='b', GREEN='g'};

void func(int i){
}
int main()
{
    bool b1 = BEAR && DUCK; //what?!    
    func(BEAR); //too easy to convert
    std::cout<<"size of Colors_e is "<<sizeof(Colors_e)<<std::endl;
}