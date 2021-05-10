//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//

//compile with g++ -std=c++98 .\4_exception_specifications.cpp

#include <string>
#include <iostream>

struct ExceptionType{};

void processData( int, int ) throw(std::string , ExceptionType){
    std::cout<<"[processData:] throw ExceptionType\n";
    // throw ExceptionType();
    //no compilation error if we marked up the 
    //ExceptionType from the exception specification list
    throw 5;
}

void doAction (int op1, int op2 ) throw(std::string, ExceptionType) {
   processData( op1, op2 ); // no compile-time error - but get runtime error if we remark ExceptionType!
   // ...
}

void problem() throw(){
    throw 5;    //runtime error
}

int main()
{
    try{
        doAction(1,2);
        // problem();
    }
    catch(...){
        std::cout<<"[main:] Unknown Exception in main\n";
    }
}

//explanation to the runtime error:
//https://compiler-explorer.com/z/xPoc79Mq5