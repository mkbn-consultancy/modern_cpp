//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
struct X;
struct Y { 
  operator X(); 
};

struct X { 
  X() { }
  X(const Y&) { std::cout << "[X(Y)] Direct initialization" << '\n'; }

  X(const X&) { std::cout << "Copy ctor" << '\n'; }
};

Y::operator X() { std::cout << "[Y::()] Copy initialization" << '\n'; return X(); }


void f(int&){std::cout<<"f(int&)\n";}

void f(const int&){std::cout<<"f(const int&)\n";}


int main() { 

    int i = 1;

    // f(i);    // calls f(int&) 


  Y y;
  X x1 = y;
  // X x2(y);
}
