//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
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

/*
     BASE
     ^  ^
     |  |virtual
    D1  D2
*/
struct D1 : public BASE {
    //OK, the implicit default constructor of BASE is a constexpr constructor.
    constexpr D1() : BASE(), mem(55) { }
    
    //OK, the implicit copy constructor of BASE is a constexpr constructor.
    constexpr D1(const D1& d) : BASE(d), mem(55) { mem++; } //since C++14 the body can be non-empty

    //OK, all reference types are literal types.
    constexpr D1(NL &n) : BASE(), mem(55) { }

private:    
    int mem;
};  

struct D2 : virtual BASE { 
    //error, D2 must not have virtual base class.
    // constexpr D2() : BASE(), mem(55) { }    

private:
    int mem; 
};  


int main()
{
}