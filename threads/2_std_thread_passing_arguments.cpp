#include <iostream>
#include <thread>

struct MyClass
{
    MyClass() {std::cout<<"inside default constructor\n";}
    MyClass(const MyClass&) {std::cout<<"inside copy constructor\n";}
    MyClass(MyClass&&) {std::cout<<"inside move constructor\n";}
    MyClass& operator=(const MyClass&) { std::cout<<"inside operator=(const MyClass&)\n"; return *this;}
    ~MyClass() {std::cout<<"insdie ~MyClass()\n";}
};

void func(MyClass m)
{
        std::cout<<"--inside func...\n";
        std::cout<<"--end of func...\n";
}

int main()
{
    MyClass m;  //call default constructor
    std::cout<<"--create a thread with func...\n";
    std::thread theThread(func,m);  //parameters are passed by value to the constructor
                                    //thus call copy constructor

    if(theThread.joinable()){
        theThread.join();
    }
    std::cout<<"--end of main...\n";
}