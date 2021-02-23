struct Foo{
	const int& cref() const{
		return _m;
	}
	int& mref(){
		return _m;
	}
private:
	int _m = 0;
};

int main(){
	auto foo = Foo{};
    
    auto val = foo.cref();  //qualifier is not kept!
    val++;

	auto& cref = foo.cref(); //cref is a const reference – bad practice!
	auto& mref = foo.mref(); //mref is a mutable reference
}

