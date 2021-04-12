//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <string>
#include <string_view>

struct S{
    //we can initialize inside the class only literal types!
    const static std::string _str = "Hello World";  //ERROR!
};

//the right way to do this:
struct S{
    const static std::string _str;
};
//should be in a cpp file:
const std::string S::_str = "Hello World";

//in c++17 we can do it better:
struct S{
    //we can initialize inside the class only literal types!
    inline const static std::string _str = "Hello World";
};

//Note: to be more efficient, consider the following code:
struct S{
    constexpr static std::string_view str(){
        return "Hello World";
    }
};

int main()
{

}