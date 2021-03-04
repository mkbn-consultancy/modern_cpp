#include <iostream>

int x;
int& getRef()
{
    return x;
}
int getVal(){
    return x;
}

int main()
{
    //L-Values and R-Values:
    int i;

    int& r1 = i;    //OK. reference to l-value
    //int& r2 = 20;   //error: cannot declare a reference to rvalue
    const int& r3 = 20; //OK. const reference to rvalue

    int a;
    a = 1; //a is an lvalue

    getRef() = 4;   //lvalue is not a necessarily a variable
    std::cout<<"x = "<<x<<std::endl;

    getVal(); //the return value is rvalue

    //--------------------------------------------------------------------

    std::string s1 = "Test";
    //  std::string&& rvar1 = s1;           // error: can't bind to lvalue
 
    const std::string& rvar2 = s1 + s1; // okay: lvalue reference to const extends lifetime
    //  rvar2 += "Test";                    // error: can't modify through reference to const
 
    std::string&& rvar3 = s1 + s1;      // okay: rvalue reference extends lifetime
    rvar3 += "Test";                    // okay: can modify through reference to non-const
    std::cout << rvar3 << '\n';
 
    //--------------------------------------------------------------------

    //R-Value references:
    int&& rref1 = 10;
    int&& rref2 = getVal(); //getVal returns by value
    int&& rref3 = 7+2;

    //int&& rref4 = a;    //error: r-value reference cannot bind to a l-value
}

