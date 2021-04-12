//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

void test1(int x) noexcept(throw "hello"){   
    throw x;
    //function is implicitly declared as noexcept(false) since it throws
} 

void test2(int x) noexcept(true){   

} 

int someFunction(int x) noexcept(noexcept(test1(x))) {
    //someFunction now has the same noexcept specification as test1

    //the value of the expression noexcept(test(x)) is false -> it can throw -> unwiding code is produced -> no crach

    test1(x);

    //if we change the noexcept to be noexcept(test2(x)), then:
    //the value of the expression noexcept(test(x)) is ture -> it cannot throw -> unwiding code is not produced

    return x;
}

void test3() noexcept(false){
    std::cout<<"hello"<<std::endl;
    //since test3 is calling a library function, it cannot be sure that it will now throw 
    //an exception, thus it must ask the compiler to produce unwiding code --> noexcept(false)
}

int main(){
    try{
        someFunction(4); //will crash if test throws and exception and not otherwise
    }
    catch(int x){
        std::cout<<"caught the exception in the main\n";    
    }
}