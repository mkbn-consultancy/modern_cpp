/*
Modern C++ Course: Lambda Expressions Hands-On Exercise
Create lambda expressions for the following functions:
*/

// 1.	T max(T, T); - Returns the largest element between two parameters.

// 2.	bool isGreater(T, T) ; - Return true if first argument is greater than the second

// 3.	std::pair<T,T> MinMax(ItrBegin, ItrEnd) ; - Accept iterators of any container and return the largest and smallest element from that container.

// 4.	Declare a lambda expression that can get any type as a parameter, and return the value+1 if it gets an integer, and the string "ooops" otherwise. You should use if-constexpr + type traits (use google…).
// Example: 
// auto lambda = …
// auto result1 = lambda(123); //result1 = 124
// auto result2 = lambda("hello"); //result2 = "ooops"

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
