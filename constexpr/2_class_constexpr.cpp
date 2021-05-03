struct S
{
    void changeX() {_xVal++;}
    void justNonConstFunc(){}
    void constFunc() const {}

    //data members:
    int _xVal{0};
    int _yVal{0};
};

template <int x>
void foo(){}

int main()
{
    constexpr S s1;
    s1.changeX();
    s1.justNonConstFunc();
    s1.constFunc();

    foo<s1._xVal>();
}
