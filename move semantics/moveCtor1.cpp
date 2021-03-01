#include <iostream>

class MyClass
{
public:
	MyClass() = default;
	MyClass(const MyClass& m) {std::cout<<"copy-ctor\n";}
	MyClass(MyClass&& m) {std::cout<<"move-ctor\n";}
};

MyClass get(MyClass a){
	return a;
}

void foo(MyClass m)
{
	std::cout<<"inside by-value foo\n";
}


int main(){
	MyClass obj;

	std::cout<<"-----------\n";
	foo(obj);

	std::cout<<"-----------\n";
	foo(get(obj));

	return 0;
}

