#include <iostream>

struct Foo
{
    int _x;
};

struct Foo func(){  //function returning a Foo by value
    struct Foo f = {3};
    return f;
}

int main(){
    struct Foo f;
    const struct Foo g = {0};
    
    decltype(g._x) var1;    //var1 is int
    decltype(func()._x) var2; //var2 is int

    //var1, var2 are not const:
    var1 = 3;
    var2 = 4;
}