//Metaprogramming building blocks:
//1. variables
//2. functions
//3. branching
//4. recursion (loop)

//1. variables

struct ValueHolder
{
   enum { value = 2 };
};

struct TypeHolder
{
    typedef int type;
};

void testVar()
{
    TypeHolder::type v = 3;
}

//2. functions

template<int X, int Y>
struct Adder
{
   enum { result = X + Y };
};

//3. branching

template<typename X, typename Y>
struct SameType
{
   enum { result = 0 };
};

template<typename T>
struct SameType<T, T>
{
   enum { result = 1 };
};

//4. recursion (loop)

template <unsigned n>
struct factorial
{
  enum { value = n * factorial<n-1>::value };
};

template <>
struct factorial<0>
{
  enum { value = 1 };
};

void testRecursion() {
  // Because calculations are done at compile-time, they can be
  // used for things such as array sizes.
  int array[ factorial<7>::value ];
}

int main(){

}

