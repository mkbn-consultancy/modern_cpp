//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
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

void testA_B(){
    // A a{5};
    B b{5};

    int x = 5;

    new(&x) A(); // Call for empty constructor, which does nothing
    std::cout << x << std::endl;
    
    new(&x) B; // Call for default constructor
    std::cout << x << std::endl;
    
    new(&x) B(); // Call for default constructor + Value initialization
    std::cout << x << std::endl;

}
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
    F1(const F1& f){ std::cout<<"inside F1 copy ctor\n"; } //F is not aggregate class anymore!
    int x;
};

void testCCtor()
{
    Q q{5};
    // F f1{3}; //F is not aggregated thus this initialization is not allowed

    //---------------------------------------------
    std::cout<<"F1 f1{3}: \n";
    F1 f1{3};   //call the default ctor we declared. brace initializatio, 
                //not aggregate initialization
    std::cout<<"F1 f2(f1): \n";
    F1 f2{f1};   //no copy is made!
    F1 f3(f1);   //no copy is made!
    std::cout<<"f1.x="<<f1.x<<std::endl;    
    std::cout<<"f2.x="<<f2.x<<std::endl;    //not initialized
    std::cout<<"f3.x="<<f3.x<<std::endl;    //not initialized
}

//---------------------------------------------

int main() 
{
    //-----------------------------------
    // test calling an empty default constructor {}
   testA_B();
    //-----------------------------------
    // test calling an empty copy constructor {}
    testCCtor();

    return 0; 
} 