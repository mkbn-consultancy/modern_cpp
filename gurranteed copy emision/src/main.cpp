#include <iostream>

template <typename T> struct Base {
   void f() {
       std::cerr << "Base<T>::f\n";
   }
};

template <typename T> struct Derived : Base<T> {
   void g() {
       std::cerr << "Derived<T>::g\n  ";
       this->f();
   }
};

int main()
{
    Derived<float> df;
    df.g();

    Derived<int> di;
    di.g();
    return 0;
}
