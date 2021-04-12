//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
/*
struct Base{
    virtual void foo();
};

struct A : public Base{
    void foo() final; //A::foo is overridden and it is the final override
    void bar() final; //error: non virtual function cannot be overridden or be final
};

struct B final : public A{
    void foo() override;    //Error: foo cannot be overridden as it's final in A
};

struct C : public B{    //error: B is final 
};
*/

//-----------------------------------------------------

class FooInterface{
public:
    virtual void mainFlow() = 0;
protected:
    virtual void mainFlowImplementation() = 0;
};

class FooBase : public FooInterface{
public:
    virtual void mainFlow() final{
        doFirst();
        mainFlowImplementation();
        doLast();
    }
private:
    void doFirst(){}
    void doLast(){}
};

class FooDerived : public FooBase{
protected:
    void mainFlowImplementation() override { /*some implementation*/}
};

int main(){}