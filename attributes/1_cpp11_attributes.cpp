//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//

[[deprecated("[FUNC DEP] this version is not supported anymore")]]
void oldFunction(){
}

class [[deprecated("[CLASS DEP] this class is not supported anymore")]]
MyClass{
};

namespace [[deprecated("[NAMESPACE DEP] this namespace is not supported anymore")]]
experimental_library
{
    void func(){}
}

void test_deprecated()
{
    oldFunction();
    MyClass m;
    experimental_library::func();
}

//--------------------------------------------------------------------

int main()
{

}