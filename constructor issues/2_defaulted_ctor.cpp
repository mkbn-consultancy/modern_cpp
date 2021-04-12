//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

class Point
{
public:
	//since we used non static member initialization, why do we
	//need to declare a default constructor?
	
	//Point() = default;
	
	//Point(int x = 0) = default; //Error!
	Point(){}
	Point(int x, int y) : _x(x), _y(y) {}
private:
	int _x{0};
	int _y{0};
};

int main()
{
	//Point p;	//compilation error if we do not declare a default ctor

	Point p2{1,1};
}