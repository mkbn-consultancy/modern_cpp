#include <iostream>

//------------------------------------------------
//c++03 ways to declare constant values:
const int val = 3;
enum {FIRST = 0, SECOND = 1, THIRD=val};

int arr[val];

int getNumber_nc() { return 5; }

//int arr2[getNumber_nc()]; //won't compile even if function always returns 5
const int i = getNumber_nc();  //i will be initialized at run time and not compile time!

//------------------------------------------------
//C++11: constexpr

constexpr int getNumber() { return 5; }
int arr2[getNumber()];

// constexpr int j = getNumber_nc(); //ERROR!

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

    const int a = getNumber_nc();
    // constexpr int b = getNumber_nc(); //error!
    constexpr int b = function3();
    //b++;  //error!

    int a;
    const int b = a;
    // constexpr int c = a; //error!
}

