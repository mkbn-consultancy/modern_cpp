//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//

#include <iostream>
#include <thread>

struct MyClass
{
    MyClass() {std::cout<<"[MyClass] inside default constructor\n";}
    MyClass(const MyClass&) {std::cout<<"[MyClass] inside copy constructor\n";}
    MyClass(MyClass&&) {std::cout<<"[MyClass] inside move constructor\n";}
    MyClass& operator=(const MyClass&) { std::cout<<"[MyClass] inside operator=(const MyClass&)\n"; return *this;}
    ~MyClass() {std::cout<<"[MyClass] insdie ~MyClass()\n";}
};

//try to make it by value with no &...
void func(const MyClass& m, const int& result)
{
        std::cout<<"[func] inside func...\n";
        std::cout<<"[func] end of func...\n";
}

void func1(int i)
{
    std::cout<<"[func1] inside func1...\n";
}

int main()
{
    int x = 3;
 
    std::cout<<std::endl;
    std::cout<<"------------------------------\n";
    std::cout<<"[main] creating a thread with func1\n";
    std::thread t1(func1,x);
    t1.join();

    std::cout<<"------------------------------\n";
    std::cout<<"[main] creating a MyClass object\n";
    MyClass m;  //call default constructor

    std::cout<<std::endl;
    std::cout<<"[main] create a thread with func, sending by value\n";
    std::thread theThread(func, m, x);  //parameters are passed by value to the constructor

    // std::cout<<"[main] create a thread with func, sending by ref\n";
    // std::thread theThread(func, std::ref(m), std::ref(x));  //parameters are passed by value to the constructor
                                    //thus call copy constructor

    std::cout<<std::endl;
    std::cout<<"[main] joining the thread...\n";
    if(theThread.joinable()){
        theThread.join();
    }
    
    std::cout<<std::endl;
    std::cout<<"[main] end of main...\n";
    std::cout<<"------------------------------\n";
}