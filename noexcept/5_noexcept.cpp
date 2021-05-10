//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

void test(int x){   
    std::cout<<"[test:] throwing an exception\n";
    throw x;
    //function is implicitly declared as noexcept(false)
} 

int someFunction() noexcept(true) {
    //same as writing just noexcept. it is automatically noexcept(true)
    //this means that no unwinding code is produced by the compiler!
    int x = 4;
    test(x);
    return x;
}

int someFunction_2(int x) noexcept(noexcept(test(x))) {
    //since test is noexcept(false), so does this function
    std::cout<<"[someFunction_2:] call test(x)\n";
    test(x);
    return x;
}

int main(){
    try{
        // someFunction(); //will crash with noexcept(true) and will work with noexcept(false)
        std::cout<<"[main:] call someFunction_2 in try block\n";
        someFunction_2(5);
    }
    catch(int x){
        std::cout<<"[main:] caught the exception in the main\n";    
    }
}