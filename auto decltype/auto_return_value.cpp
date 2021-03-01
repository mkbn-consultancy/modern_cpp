//C++03 style
struct Foo1{
	int val() const{
		return _m;
	}
	const int& cref() const{
		return _m;
	}
	int& mref(){
		return _m;
	}
private:
	int _m;
};

//C++14 style
struct Foo2{
	auto val() const{
		return _m;
	}
	auto& cref() const{
		return _m;
	}
	auto& mref(){
		return _m;
	}
private:
	int _m;
};

int main()
{

}