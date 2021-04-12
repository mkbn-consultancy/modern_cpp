//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

enum class Animals_e{ BEAR, CAT, CHICHEN};
enum class Birds_e{EAGLE, DUCK, /*CHICHEN*/}; 

enum class Colors_e : char {RED='r', BLUE='b', GREEN='g'};

void func(int i){
}

int main()
{
//    bool b1 = Animals_e::BEAR && Birds_e::DUCK; 
            //error: no match for 'operator&&' (operand types are 'Animals_e' and 'Birds_e')
//    func(Animals_e::BEAR); 
            //error: cannot convert 'Animals_e' to 'int'
    std::cout<<"size of Colors_e is "<<sizeof(Colors_e)<<std::endl;
}