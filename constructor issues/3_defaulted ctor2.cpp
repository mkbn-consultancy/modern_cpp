#include <type_traits>
#include <iostream>

struct X {
    X() = default;
};

struct Y {
    Y() { };
};

void test1() {
    static_assert(std::is_trivial<X>::value, "X should be trivial");
    static_assert(std::is_pod<X>::value, "X should be POD");
    
    static_assert(!std::is_trivial<Y>::value, "Y should not be trivial");
    static_assert(!std::is_pod<Y>::value, "Y should not be POD");
}

//-------------------------------------------------------------------

class A 
{
public:
    int x;
    A(){}   //not aggregated anymore: cannot write A a{5}; without this line we can.
};

class B 
{
public:
    int x;
    B() = default;  //still aggregate class. can write B b{5};
};

//---------------------------------------------
// test difference between default and empty copy constructor

struct Q{
    Q(const Q&) = default;  //Q is still aggregate class
 
    int x;
};

struct F{
    F(const F& f){} //F is not aggregate class anymore!

    int x;
};

//-------------
struct Q1
{
    Q1(const Q1&) = default;  //Q is still aggregate class
 
    int x;
};

struct F1
{
    F1(int i) : x(i){}
    F1(const F1& f){} //F is not aggregate class anymore!
    int x;
};

void testCCtor()
{
    Q q{5};
    // F f1{3}; //F is not aggregated thus this initialization is not allowed

    //---------------------------------------------
    F1 f1{3};
    F1 f2(f1);   //no copy is made!
    std::cout<<"f2.x="<<f2.x<<std::endl;    //not initialized

    //--------------------------------

}

//---------------------------------------------

int main() 
{
    // A a{5};
    B b{5};

    //-----------------------------------
    // test calling an empty copy constructor {}
    testCCtor();

    //-----------------------------------

    int x = 5;

    new(&x) A(); // Call for empty constructor, which does nothing
    std::cout << x << std::endl;
    
    new(&x) B; // Call for default constructor
    std::cout << x << std::endl;
    
    new(&x) B(); // Call for default constructor + Value initialization
    std::cout << x << std::endl;
    
    return 0; 
} 