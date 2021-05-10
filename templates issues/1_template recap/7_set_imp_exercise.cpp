#include <iostream>
#include <algorithm>

template <typename T, int Size, class CompFunctor = std::less<T>>
class Set
{
public:
    Set() {std::cout<<"inside Set<T>\n";}
    Set(std::initializer_list<T> list){ 
        std::cout<<"inside Set(initializer_list)\n";
        
    }
    Set(std::initializer_list<T> entries){
        
    }
    ~Set(){}
    void insert(T entry){
        if(_used==Size){
            return;
        }
        if(contains(entry)){
            return;
        }
        _data[_used++] = entry;
        std::sort(_data,_data+Size,ComFunctor());
    }
private:
    T _data[Size]{};
    size_t _used{0};
};

template<typename T, int Size, class CompFunctor>
class Set<T*,Size,CompFunctor>
{
public:
    Set() {std::cout<<"inside Set<T*>\n";}
    Set(std::initializer_list<T*> entries){
        if(entries.size()>=Size){
            return;
        }
        for(auto p : entries){
            _data[_used++] = std::make_shared<T>(p);
        }
        std::sort(_data,_data+Size,CompFunctor());
    }
    void insert(T* pEntry) {
        if(_used==Size){
            return;
        }
        if(contains(*pEntry)){
            return;
        }
        _data[_used++] = std::make_shared<T>(pEntry);
        std::sort(_data,_data+Size,CompFunctor());
    }
protected:
    bool contains(const T& entry){
        
    }
private:
    std::shared_ptr<T>  _data[Size]{};
    size_t _used{0};
};

