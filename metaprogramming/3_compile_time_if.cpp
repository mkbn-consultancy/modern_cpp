#include <iostream>
#include <cstdint>

//forward declaration
template <bool Condition, typename TrueResult, typename FalseResult>
class if_;

//declaring struct if_ with partial specialization (true)
template <typename TrueResult, typename FalseResult>
struct if_<true, TrueResult, FalseResult>
{
  typedef TrueResult result;
};

//declaring struct if_ with partial specialization (false)
template <typename TrueResult, typename FalseResult>
struct if_<false, TrueResult, FalseResult>
{
  typedef FalseResult result;
};

void testIf_()
{
    typename if_<true, int, void*>::result number(3); //result is int
    typename if_<false, int, void*>::result pointer(&number); //result is void*

    typedef typename if_<(sizeof(void *) > sizeof(uint32_t)), 
                        uint64_t, 
                        uint32_t>
                        ::result 
        integral_ptr_t;
	  
    integral_ptr_t converted_pointer = reinterpret_cast<integral_ptr_t>(pointer);
}

///////////////////////////////////////

template <bool Bigger, int A, int B> 
struct if_max_;

template <int A, int B>
struct if_max_<true,A,B>
{
    enum{result = A};
};

template <int A, int B>
struct if_max_<false,A,B>
{
    enum{result = B};
};

void test_if_max_()
{
    std::cout<< if_max_< (2>3), 2, 3>::result<<std::endl;
    std::cout<< if_max_< (3>2), 3, 2>::result<<std::endl;
}

/////////////////////////////

template <bool isEven, int A>
struct if_even_;

template <int A>
struct if_even_<true, A>
{
    enum{result=true};
};

template <int A>
struct if_even_<false, A>
{
    enum{result=false};
};

void testIf_even_()
{
    std::cout<<"The number 12 is even? "<<if_even_<(12%2==0),12>::result<<std::endl;
}
/////////////////////////////

template<typename T>              
struct removeConst{ 
    typedef T type;               
};

template<typename T>              
struct removeConst<const T> { 
    typedef T type;              
};


void testRemoveConst(){
    std::is_same<int, removeConst<int>::type>::value;        // true 
    std::is_same<int, removeConst<const int>::type>::value;  // true 
}

/////////////////////////////

int main()
{
    // test_if_max_();
    testIf_even_();
}