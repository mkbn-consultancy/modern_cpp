#include <iostream>

struct A
{
 //   A() = default;
 //   A() : _x(0),_y(0){}
    explicit A(int x, double y) : _x(x), _y(y) {}
private:
    int _x;
    double _y;
};

int main(){
    //A a1 = {2,3.5};
    A a2{2,3.5};
}
