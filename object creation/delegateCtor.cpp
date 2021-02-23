class MyClass1
{
public:
    MyClass1() : _val1(0), _val2(0){}    //ctor #1
    MyClass1(int v1, int v2) : _val1(v1), _val2(v2) {}   //ctor #2

private:
    int _val1;
    int _val2;
};

// C++03 solution: declare a helper function and call it from both constructors
class MyClass2
{
public:
    MyClass2() { initDataMembers(0,0); }    //ctor #1
    MyClass2(int v1, int v2) { initDataMembers(v1,v2); }   //ctor #2
protected:
    void initDataMembers(int v1, int v2){
        _val1 = v1;
        _val2 = v2;
    }
private:
    int _val1;
    int _val2;
};

// C++11 solution: constructor delegation
class MyClass3
{
public:
    MyClass3() : MyClass3(0,0) {}    //ctor #1 calls constructor #2
    MyClass3(int v1, int v2) : _val1(v1), _val2(v2) {}   //ctor #2
private:
    int _val1;
    int _val2;
};

int main()
{
    MyClass1 a1; //goto default ctor - ctor #1
    MyClass1 a2(4,5);    //goto ctor #2

    return 0;
}
