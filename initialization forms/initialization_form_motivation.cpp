#include <vector>
#include <string>

//----------------------------------
// C++03 initialization forms
//----------------------------------
//two types of object initialization:
std::string s1("test");   // direct initialization 
std::string s2 = "test";  // copy initialization

struct X{
    X() : _val(0){}
    X(int v) : _val(v){}
private:
    int _val;
};

void initForms()
{
    int i;    // uninitialized built-in type
    
    int j = 10;  // initialized built-in type (copy initialization)
    
    int k(10); // initialized built-in type (direct initialization)
    
    int b[10];  //uninitialized
    int a[] = {1, 2, 3, 4}; // Aggregate initialization

    X x1;  // default constructor
    X x2(1);  // Parametrized constructor
    X x3 = 3; // Parametrized constructor with single argument
    X x4 = x3; // copy-constructor
}


struct S
{
    /*explicit*/ S(int x) : _x(x) {}
private:
    int _x;
};

void testS()
{
    S s1(1);
    S s2 = 1;
}

//No way to initialize a member array (except using the default ctor).
class A
{
public:
    A(int x) : _x(x) {}
private:
    int _x;
};

void testA()
{
 //   A array[10];
}

//No convenient form of initializing containers.
void testB()
{
    //we can initialize static vector:
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    //but we cannot do it with containers:
    std::vector<int> vec;
    for(int i=0; i<10; i++){
        vec.push_back(i);
    }
}

//No way to initialize dynamically allocated POD types.
void testC()
{
    char *buff=new char[1024]; //no proper way to initialize the elements of buff
}

int main()
{

}