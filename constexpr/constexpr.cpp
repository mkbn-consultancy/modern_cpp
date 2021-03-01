#include <iostream>

const int val = 3;
enum {FIRST = 0, SECOND = 1, THIRD=val};

int arr[val];

int function1() { return 5; }

//int arr2[function1()]; //won't compile even if function always returns 5

constexpr int function2() { return 5; }
int arr2[function2()];

constexpr int function3(){
    int x = 3;
    return 3;
}

//only since C++14 since it has more than 1 return statement
constexpr size_t factorial(int n){
    if(n==1){
        return 1;
    }
    return factorial(n-1)*n;
}


int main()
{
    //constexpr int v; //error! must be initialized.
    constexpr int v = 3; //OK
    
    size_t result = factorial(20);
    std::cout<<"factorial(20) = "<<result<<std::endl; 

    int x; 
    std::cin>>x;
    result = factorial(x);

    const int a = function1();
    //constexpr int b = funcion1(); //error!
    constexpr int b = function2();
    //b++;  //error!

}
