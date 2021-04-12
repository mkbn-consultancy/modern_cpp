//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

class MyClass
{
public:
	MyClass()  = default;
	MyClass(const MyClass& m) {std::cout<<"copy-ctor\n";}
	MyClass(MyClass&& m) {std::cout<<"move-ctor\n";}
};
//---------------------------------------------------

/*
void foo(MyClass& m)
{
	std::cout<<"inside lvalue foo\n";
}
*/

void foo(MyClass&& m)
{
	std::cout<<"inside rvalue foo\n";
}

//---------------------------------------------------
MyClass get(MyClass a){
	return a;
}
//---------------------------------------------------

int main(){
	MyClass obj;

	std::cout<<"-----------\n";
	foo(obj);

	std::cout<<"-----------\n";
	foo(get(obj));

	return 0;
}

