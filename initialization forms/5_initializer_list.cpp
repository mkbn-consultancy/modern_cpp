//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <vector>
#include <initializer_list>
#include <iostream>
#include <cassert>

std::vector<int> vi {1,2,3,4,5,6};
std::vector<double> vd {0.5, 1.33, 2.66};

//using auto matters which initialization form we choose:
auto z1 {99}; // z1 is an initializer_list<int>
auto z2 = 99; // z2 is an int

template <class T, int Size_t>
class Pool
{
public:
    Pool() = default;
    Pool(std::initializer_list<T> values){
        if(values.size()<Size_t){
            for(auto it : values){
                add(it);
            }
        }
    }
    void add(T val){
        if(_size<Size_t){
            _data[_size++] = val;
        }
    }
    void remove(){
        if(_size>0){
            --_size;
        }
    }

    T operator[] (int index){
        assert(index>=0 && index<Size_t);
        return _data[index];
    }

    int getSize() const {
        return _size;
    }
private:
    T _data[Size_t]; //static array of T elements
    int _size{};    //initialized to zero
};

template<class T>
void print(std::initializer_list<T> values){
   for(auto it : values){
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;   
}
void testPool()
{
    //without initialization list we can initialize Pool only using add
    Pool<int,10> thePool; 
    thePool.add(1);
    thePool.add(2);
    thePool.add(3);
    //printing thePool:
    for(int i=0; i<thePool.getSize(); ++i){
        std::cout<<thePool[i]<<" ";
    }
    std::cout<<std::endl;

    //with initialization list constructor
    Pool<int,10> anotherPool{1,2,3};
    //printing thePool:
    for(int i=0; i<thePool.getSize(); ++i){
        std::cout<<thePool[i]<<" ";
    }
    std::cout<<std::endl;

    //we could also use:
    auto values = {1,2,3,4};
    Pool<int,10> anotherPool2(values);

    //a print function that gets initialized_list
    print(values);
}

int  main()
{
    testPool();
}

