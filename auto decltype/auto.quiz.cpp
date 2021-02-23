//Given the following code, write it according to C++14 standard
struct Foo{
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

//C++14 version:
struct Foo{
    //TODO:
    
private:
    int _m;
}