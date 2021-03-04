class CMyVector {
public:
	//...
	CMyVector& operator=(const CMyVector& vec) {
		// [...]
		// Make a clone of what vec.m_pArr refers to.
		// Destruct the resource that m_pArr refers to. 
		// Attach the clone to m_pArr.
		// [...]

		return *this;
	}
private:
	int* m_pArr;
};

CMyVector foo(CMyVector v) {
	return v;
}

int main() {
	CMyVector x;
	// perhaps use x in various ways
	x = foo(x);
	//...

	return 0;
}

