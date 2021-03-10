// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>

//the old way:
// template<class T>
// bool is_odd(T i){
//     //T can be anything. even structs that has nothing to do with odd...
//     //how can we prevent this?
// }

//using enable_if - the function will not be available at all if the type
//is not suitable.

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type  //return type is bool
  is_odd (T i) {
      return bool(i%2);
}

// 2. the second template argument is only valid if T is an integral type:
template < typename T, typename std::enable_if<std::is_integral<T>::value,T>::type = 0>
bool is_even (T i) {
      return !bool(i%2);
}

struct MyClass{};

int main() {

  short int i = 1;    // code does not compile if type of i is not integral

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;

//   MyClass m;
//   is_odd(m);
//   is_even(m);

  return 0;
}

