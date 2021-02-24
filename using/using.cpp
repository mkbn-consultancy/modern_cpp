#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <map>

//C++03: declare a different typedef for each type, which is hard-coded
using ListsPool_Strings = std::vector<std::list<std::string>>;
using ListsPool_ints = std::vector<std::list<int>>;

//------------------------------------------------
//C++03 partial solution:
template <class T>
struct ListsPool{
    typedef std::vector<std::list<T>> type_t;
};

void test(){
    ListsPool<int>::type_t poolOfInts;
}

//------------------------------------------------
//C++11: parameterized typedef
template<class T>
using ListsPool_t = std::vector<std::list<T>>;

//another example:

template<class T>
using Pool_t = std::map<T, std::vector<T>>; // type-id is std::map<int,std::vector<int>>

Pool_t<int> v; // Pool_t<int> is the same as std::map<int,std::vector<int>>

//------------------------------------------------
class SomeClass{};

int main()
{
    ListsPool_t<SomeClass> poolOfMyClass;
}