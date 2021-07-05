//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

struct S
{
    int i;
};

class A_NotAggregate
{
public:
    virtual void f() {} //remember? no virtual functions
//private:
    int x;
};

class B_NotAggregate
{
  int x; //x is private by default and non-static 
};

class C_NotAggregate
{
public:
  C_NotAggregate() : i(42){} //oops, user-defined constructor
  int i;
};

class D_Aggregate
{
public:
  D_Aggregate& operator=(D_Aggregate const & rhs) {/* */ return *this;} //ok, copy-assignment  

public:
  int i;
  A_NotAggregate member1;   //ok, public member
private:
  void f() {} // ok, just a private function
};

struct E
{
public:
  int _x;
  int _y;
};

class NonCopyable
{
public:
  NonCopyable() = default;

  int _x;
private:
  NonCopyable(const NonCopyable&) = default;
};

int main()
{
    NonCopyable nc{3};
    // NonCopyable nc(3);

    S s{1};

    D_Aggregate d{5};   //OK!
  
    A_NotAggregate a{1};     //ERROR!
    B_NotAggregate b{1};     //ERROR!
    C_NotAggregate c{5};     //ERROR!
    E e{1,2};
}
