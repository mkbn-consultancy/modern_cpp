#include <iostream>

class A
{
private:
    int _x;
};

class B
{
private:
    A a{0};
};