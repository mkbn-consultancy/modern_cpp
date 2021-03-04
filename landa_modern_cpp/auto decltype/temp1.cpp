#include <string>
#include <iostream>

//RULE OF THREE
//1. copy ctor
//2. destructor
//3. assignment operator

class A
{
public:
    A(size_t n, const std::string& s) : _name(s){
       std::cout<<"inside ctor\n";
        _arr = new int[n]{};
        _size = n;
    }

    A(const A& a){
        std::cout<<"inside copy ctor\n";
        _name = a._name;
        _size = a._size;
        _arr = new int[_size];
        std::copy(a._arr,a._arr+_size,_arr);
    }

    A(A&& a) {   //move constructor
        _arr = a._arr;
        _size = a._size;

        _name = std::move(a._name);

        a._arr = nullptr;
    }

    ~A(){
        delete[] _arr;
    }

    A& operator=(const A& a){
        if(this != &a){
            if(_arr){
                delete[] _arr;
            }
            _name = std::move(a._name);
            _size = a._size;
            _arr = new int[_size];
            std::copy(a._arr,a._arr+_size,_arr);
        }
        return *this;
    }

    A& operator=(A&& a){
        if(this != &a){
            _name = std::move(a._name);    //???
            _size = a._size;
            _arr = a._arr;
            a._arr = nullptr;
        }
        return *this;       
    }
private:
    std::string _name;
    int* _arr;
    size_t _size;
};

//--------------------------------

template<class T>
void f(T a){
    std::cout<<"inside f(T)\n";
}

template<class T>
void f(T&& a){
    std::cout<<"inside f(T&&)\n";
}

A get(A a){
    return a;
}

//--------------------------------
template<class T>
void func2(T&& b){

}

template<class T>
void func1(T&& a){
    func2(   a   );
}

//--------------------------------

int main(){
    A a(4, "Joe");

    f(get(a));
}