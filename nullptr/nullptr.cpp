//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <stdlib.h>
#include <iostream>
#include <memory>

void func(int n){ std::cout<<"inside func(int)\n"; }
void func(char* s){ std::cout<<"inside func(char*)\n"; }
void func(std::nullptr_t) { std::cout<<"inside func(nullptr)\n";}

//C++03:
void testNULL()
{
 //   func(NULL); //error: call of overloaded 'func(long long int)' is ambiguous
}

//C++11:
void foo(int* p){ std::cout<<"inside foo(int*)\n"; }
void bar(std::shared_ptr<int> p){ std::cout<<"inside bar(shared_ptr<int>)"; }

void testNullptr()
{
    // func(NULL);
    func(nullptr);
    int x = NULL;
    // int y = nullptr; //error!

    int* p1 = NULL;
    int* p2 = nullptr;
    if(p1==p2){
        std::cout<<"p1 and p2 can be compared\n";
    }
    foo(nullptr);
    bar(nullptr);
}

int main()
{
    std::cout<<"---- test NULL ----\n";
    testNULL();
    std::cout<<"---- test nullptr ----\n";
    testNullptr();
}