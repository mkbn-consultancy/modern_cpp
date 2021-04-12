//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//

//compilation line: g++ -Wall -Wextra .\1_attributes.cpp

//--------------------------------------------------------------------

void f(){}
void g(){}
void h(){}

char getChar(){ return 'a';}

void test_fallthrough()
{
    char c = getChar();

    switch (c) 
    {
    case 'a':
        f(); // Warning! fallthrough is perhaps a programmer error
    case 'b':
        g();
    [[fallthrough]]; // Warning suppressed, fallthrough is ok
    case 'c':
        h();
    }
}

//--------------------------------------------------------------------

// [[nodiscard]] int foo() {return 5;}  //warning!
int foo(){return 5;}    //no warning

//if we'll discard the return value we will have memory leak!
template<typename T>
[[nodiscard]] T* getArray(int size) {
    return new T[size];
}

void test_nodiscard_1() {
    foo(); // Warning! return value of a
           // nodiscard function is discarded
    getArray<char>(10);
}

[[nodiscard]] struct DoNotThrowMeAway{};
DoNotThrowMeAway func();
void test_nodiscard_2() {
    func();     // Warning emitted, return value of a   
                 // nodiscard function is discarded
}

//--------------------------------------------------------------------

static void impl1() { /*...*/ } // Compilers may warn about this
[[maybe_unused]] static void impl2() { /*...*/ } // Warning suppressed


void test_maybe_unused() {
   int x = 42; // Compilers may warn about this
   [[maybe_unused]] int y = 42; // Warning suppressed
}

//--------------------------------------------------------------------



//--------------------------------------------------------------------
int main()
{
}