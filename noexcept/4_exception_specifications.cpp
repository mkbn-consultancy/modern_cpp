#include <string>
#include <iostream>

struct ExceptionType{};

void processData( int, int ) throw(std::string, ExceptionType){
    throw ExceptionType();
}

void doAction (int op1, int op2 ) throw(std::string) {
   processData( op1, op2 ); // no compile-time error - but get runtime error!
   // ...
}

int main()
{
    try{
        doAction(1,2);
    }
    catch(...){
        std::cout<<"Unknown Exception in main\n";
    }
}