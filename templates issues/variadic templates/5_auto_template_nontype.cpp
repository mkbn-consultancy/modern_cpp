//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

template <typename Type, Type value> constexpr Type constant1 = value;
constexpr auto const IntConstant42_a = constant1<int, 42>;

//C++17:
template <auto value> constexpr auto constant2 = value;
constexpr auto const IntConstant42_b = constant2<42>;

/////////////////////////////////////////////////////////

template <auto ... vs> 
struct HeterogenousValueList 
{
    size_t getListSize() const {return sizeof...(vs);}
    void print(){ print1(vs...); }
protected:
    void print1(){std::cout<<"the end...\n";}
    template<typename T, typename ... args>
    void print1(T a1, args ... a2){
        std::cout<<a1<<std::endl;
        print1(a2...);
    }
 };

using MyList = HeterogenousValueList<'a', 100, 'b'>;

void print(){
    std::cout<<"the end...\n";
}

template<typename T, typename ... Types>
void print(T var1, Types... var2){
    std::cout<<var1<<std::endl;
    print(var2...);
}
int main()
{
    MyList m;
    std::cout<<m.getListSize()<<std::endl;

    print(1, 2, 3.14, "Pass me any "
              "number of arguments",  
                  "I will print\n");
    
    m.print();
}