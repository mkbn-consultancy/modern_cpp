#include <string>

int main()
{
    int n{}; 		//zero initialization: n is initialized to 0
    int *p1{}; 		//initialized to nullptr
    double d{4.5}; 	//initialized to 0.0
    char s1[12]{}; 	//all 12 chars are initialized to '\0’
    std::string s2{};	//same as: string s;
    char *p2 = new char [5]{}; // all five chars are initialized to '\0'
    int arr[] = {1,2,3};

    //notice that this is not an initialization but a declaration:
    int b();    //instead of int b{} which initializes b to zero.
}


class C1
{
	int _x=7; //class member initializer
public:
	C1();
};

class C2
{
	int _y[5] {1,2,3,4};
public:
	C2();
};

class C3{
	std::string _s1{"abc"};
    std::string _s2 = std::string("def");
	double 	    _d {0};
	char * 	    _p {nullptr};
	int 		_y[5] {1,2,3,4};
    int *       _q = new int[10];
public:
	C3();
};

class C4{
	std::string _s;
	double 	    _d;
	char * 	    _p;
	int         _y[5];
public:
	C4() : _s("abc"), _d(0.0), _p(nullptr), _y{1,2,3,4} {}
};

class C5{ 
    int _x=7; 	//class member initializer 
public:
    C5() {} //x is initialized to 7 when the default ctor is invoked 
    C5(int y) : _x(y) {} //overrides the class member initializer 
}; 

C5 c; 		//c._x = 7 
C5 c2(5); 	//c2._x = 5
