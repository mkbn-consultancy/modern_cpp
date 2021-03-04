#include <map>
#include <string>

//C++03 typdef of template objects:
typedef std::map<std::string, size_t> WordsCount_t;

//we cannot declare a generic counter which can count other objects than strings:
//template<class T>
//typedef std::map<T,size_t> ObjCounter_t;

//C++11 solution:
template <class T>
using ObjCounter_t = std::map<T,size_t>;

int main()
{
    ObjCounter_t<std::string> wordsCounter;
    wordsCounter["hello"]++;

    return 0;
}

