struct A
{
  A() = default;
 
private:
  A(const A&);
  A& operator=(const A&);
};

struct B{
    B() {}
    B(const B&) = delete;
    B& operator=(const B&) = delete;
};

void test_deleted_ctor()
{
    A a1;
    B b1;
    // B b2 = b1;  //error!
}

//--------------------------------------

struct F
{
    F(int) {}   //this ctor can bind also double or float values...

    F(double) = delete; //this line prevents from F(int) ctor to bind double values.
};

void test_conversion_ctor_deleted()
{
    F f{5}; //OK
    // F f{3.5}; //ERROR!
}

//--------------------------------------
// we can also delete free functions

void process(int data){}
void process(double data) = delete; //prevents from double parameters to be sent to print(int)

int main(){
    // process(3.4); //ERROR!
}