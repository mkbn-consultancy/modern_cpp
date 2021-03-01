#include <iostream>

class MyClass
{
public:
	MyClass() = default;
	MyClass(const MyClass& m) {std::cout<<"copy-ctor\n";}
	MyClass(MyClass&& m) {std::cout<<"move-ctor\n";}
};


void foo(/*const*/ MyClass& m)	//will work with the const for rvalue
{
	std::cout<<"inside lvalue foo\n";
}

/*
void foo(MyClass&& m)
{
	std::cout<<"inside rvalue foo\n";
}
*/

MyClass get(MyClass a){
	return a;
}

int main(){
	MyClass obj(3);

	std::cout<<"-----------\n";
	foo(obj);

	std::cout<<"-----------\n";
	foo(get(obj));

	return 0;
}

