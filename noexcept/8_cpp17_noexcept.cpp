//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
void func1() noexcept{}

void func2(){
    throw ("hello");
}

int main(){
    //until C++17: the noexcept is not part of the function's signature
    void(*p)() noexcept;

    p = func2;
    p();    //can throw

    //compiling this code with -std=c++17 will cause a compilation error
}

void func3() throw(int){    //exception specifications is deprecated untill C++17 and removed in C++17
    throw 5;
    //compiling with -std=c++17 will cause an error instead of warning
}