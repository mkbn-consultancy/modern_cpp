//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
struct complex
{
    //a constant expression constructor
    constexpr complex(double r, double i) : re(r), im(i) { }//empty body
    //constant expression functions
    constexpr double real() const { return re; }
    constexpr double imag() const { return im; }
private:
    double re;
    double im;
};

int main(){
    constexpr complex COMP(0.0, 1.0); // creates a literal complex
 
    double x = 1.0;
    // constexpr complex cx1(x, 0); // error: x isn’t a constant expression
 
    const complex cx2(x, 1); //OK, dynamic initialization

    constexpr double xx = COMP.real(); // OK
    constexpr double imaglval = COMP.imag(); //OK, static init

    complex cx3(2, 4.6); //dynamic initialization
}