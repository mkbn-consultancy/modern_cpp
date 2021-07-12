    #include <iostream>
#include <algorithm>
#include <vector>

//compile with -std=c++17

// 1.	T max(T, T); - Returns the largest element between two parameters.
auto max = [](auto a, auto b){
    return a>b ? a : b;
};

// 2.	bool isGreater(T, T) ; - Return true if first argument is greater than the second

auto isGreater = [](auto a, auto b){
    return a>b;
};

// 3.	std::pair<T,T> MinMax(ItrBegin, ItrEnd) ; - Accept iterators of any container and return the largest and smallest element from that container.

auto minMax = [](auto begin, auto end) {
    auto min = *begin;
    auto max = *begin;
    // std::cout<<"[minMax]: min = "<<min<<" max = "<<max<<std::endl;

    std::for_each(begin, end, [&](const auto &a) mutable {
        min = [&]() -> auto { return a < min ? a : min; }();
        max = [&]() -> auto { return a > max ? a : max; }();
        // std::cout<<"[lambda]: min = "<<min<<" max = "<<max<<std::endl;
    });
    return std::make_pair(min,max);

};

// 4.	Declare a lambda expression that can get any type as a parameter, and return the value+1 if it gets an integer, and the string "ooops" otherwise. You should use if-constexpr + type traits (use google…).
// Example: 
// auto lambda = …
// auto result1 = lambda(123); //result1 = 124
// auto result2 = lambda("hello"); //result2 = "ooops"

auto lambda4 = [](auto x){
     if constexpr(std::is_same_v<decltype(x), int>){
        return x+1;
    }else{
        return "ooops...";
    }
};

// 5.	Suppose we have the following structs:
struct add_tax{};
struct apply_discount{};

// We wish to declare a lambda expression that captures a total variable and updates it according to parameters it gets:
// a) If the lambda expression gets as parameters an add_tax object and a value, than the total is incremented by the specified tax "value"%. (for example sending 10 means a tax of 10%).
// b) If the lambda expression gets as parameters an apply_discount object and a value, than the total is decreased by the discount of "value".
// The lambda should return the updated total.
// c) If the lambda accepts other parameter than add_tax or apply_discount, it should return an error message ("No idea what to do").
// Example:
// double result = 100.00;
// auto lambda = …
// std::cout<<lambda(applyDiscountObj , 5.00);	//95.00;
// std::cout<<lambda(addTaxObj , 10);	//104.5 (+10% tax)
// Try to implement the lambda using if-constexpr feature (C++17).

int main()
{
    std::cout<<"(1) max(-5,3) = "<<max(-5,3)<<std::endl;

    std::cout<<"(2) isGreater(4,-5) = "<<std::boolalpha<<isGreater(4,-5)<<std::endl;

    std::vector<int> vec{3,5,-9,2,0,18};
    auto res = minMax(vec.begin(), vec.end());
    std::cout<<"(3) minMax of [3,5,-9,2,0,18] = [" << res.first <<" , "<<res.second<<"]"<<std::endl;

    std::cout<<"(4) lambda(10) = "<<lambda4(10)<<", and lambda(2.4) = "<<lambda4(2.4)<<std::endl;

    constexpr add_tax add_tax_obj;
    constexpr apply_discount apply_discount_obj;
    double total = 100.00;
    auto totalPrice = [=](auto op, auto value) mutable{
        using Operation = decltype(op);
        if constexpr (std::is_same_v<Operation, add_tax>) {
            total += total * value/100; // value is the tax rate
            return total;
        } else if constexpr (std::is_same_v<Operation, apply_discount>) {
            total -= value; //std::max(value, total); // value is the discount
            return total;
        } else {
            return "Don't know what you are asking me to do.";
        }    
    };
    std::cout<<"(5) 100.00 - 5.00 = "<<totalPrice(apply_discount_obj , 5.00);	//95.00;
    std::cout<<"||| 95 + 10% = "<<totalPrice(add_tax_obj , 10)<<std::endl;	//104.5 (+10% tax)
    std::cout<<"Wrong operation: "<<totalPrice(10,10)<<std::endl;
}