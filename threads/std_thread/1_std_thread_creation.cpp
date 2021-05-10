//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <vector>
#include <thread>
#include <iostream>
#include <functional>   //for std::ref

void simpleFunction(){
    for(int i=0; i<10; ++i){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

struct SimpleFunctor
{
    void operator()(){ 
        for(int i=0; i<10; ++i){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;       
    }
};

void test_simple_thread()
{
    //creating the thread with a function pointer:
    std::cout<<"-------------------\n";
    std::cout<<"Function Pointer:\n";
    std::cout<<"-------------------\n";
    std::thread t1(simpleFunction); 
    std::thread t2(simpleFunction);
    t1.join();
    t2.join();  
    std::cout<<"-------------------\n";
    std::cout<<"Function Object:\n";
    std::cout<<"-------------------\n";
    //creating the trhead with a functor:
    SimpleFunctor func;
    std::thread t3(func); 
    std::thread t4((SimpleFunctor()));  //need to enclose the creation due to function declaration conversion
    t3.join();
    t4.join();  
    std::cout<<"-------------------\n";
    std::cout<<"Lambda Function:\n";
    std::cout<<"-------------------\n";
    
    int result = 0;
    auto lambdaFunc = [&result] {
        for(int i=0; i<10; ++i){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;   
        result = 10;    
    };

    std::thread t5([] {
        for(int i=0; i<10; ++i){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;       
    }
    );
    std::thread t6(lambdaFunc);
    t5.join();
    t6.join(); 
    std::cout<<"[main] result of lambdaFunc: "<<result<<std::endl;   
}

void accumulator_function(const std::vector<int> &v, unsigned long long &sum, 
                            unsigned int beginIndex, unsigned int endIndex)
{
    sum = 0;
    for (unsigned int i = beginIndex; i < endIndex; ++i)
    {
        sum += v[i];
    }
}
template <class T>
void test_initThreads_usingFunctionPtr(const std::vector<T>& v)
{
    
    unsigned long long sum1 = 0;
    unsigned long long sum2 = 0;
    std::thread t1(accumulator_function, std::ref(v), 
                    std::ref(sum1), 0, v.size() / 2);
    std::thread t2(accumulator_function, std::ref(v), 
                    std::ref(sum2), v.size() / 2, v.size());
    t1.join();
    t2.join();

    std::cout << "acm1: " << sum1 << std::endl;
    std::cout << "acm2: " << sum2 << std::endl;
    std::cout << "acm1 + acm2: " << sum1 + sum2 << std::endl;
}

int main()
{
    test_simple_thread();
    std::cout<<"-------------------\n";
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    test_initThreads_usingFunctionPtr(v);
}