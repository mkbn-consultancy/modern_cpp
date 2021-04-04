#include <iostream>

void test(int x){   
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
    //same as writing just noexcept. it is automatically noexcept(true)
    //this means that no unwinding code is produced by the compiler!

    test(x);
    return x;
}

int main(){
    try{
        // someFunction(); //will crash with noexcept(true) and will work with noexcept(false)

        someFunction_2(5);
    }
    catch(int x){
        std::cout<<"caught the exception in the main\n";    
    }
}