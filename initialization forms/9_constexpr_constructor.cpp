struct BASE {
};

struct B2 {
    int i;
};

//NL is a non-literal type.
struct NL {     
    virtual ~NL() {}
};    

int i = 11;

struct D1 : public BASE {
    //OK, the implicit default constructor of BASE is a constexpr constructor.
    constexpr D1() : BASE(), mem(55) { }
    
    //OK, the implicit copy constructor of BASE is a constexpr constructor.
    constexpr D1(const D1& d) : BASE(d), mem(55) { } 

    //OK, all reference types are literal types.
    constexpr D1(NL &n) : BASE(), mem(55) { }

    //The conversion operator is not constexpr.
    operator int() const { return 55; }      

private:    
    int mem;
};  

struct D2 : virtual BASE { 
    //error, D2 must not have virtual base class.
    // constexpr D2() : BASE(), mem(55) { }    

private:
    int mem; 
};  

struct D3 : B2 {
    //error, D3 must not be a function try block.   
    // constexpr D3(int) try : B2(), mem(55) { } catch(int) { }

    //error, illegal statement is in body.
    // constexpr D3(char) : B2(), mem(55) { mem = 55; } 
    
    //error, initializer for mem is not a constant expression. 
    // constexpr D3(double) : B2(), mem(i) { }

    //error, implicit conversion is not constexpr. 
    // constexpr D3(const D1 &d) : B2(), mem(d) { }                   

    //error, parameter NL is a non-literal type.
    // constexpr D3(NL) : B2(), mem(55) { } 

private: 
    int mem;
};