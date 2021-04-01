#include <atomic>
#include <iostream>
 
std::atomic<int>  ai;
 
int  tst_val= 4;
int  new_val= 5;
bool exchanged= false;
 
void printValues()
{
    std::cout << "ai= " << ai
	      << "  tst_val= " << tst_val
	      << "  new_val= " << new_val
	      << "  exchanged= " << std::boolalpha << exchanged
	      << "\n";
}
 
int main()
{
    ai= 3;
    printValues();
 
    // tst_val != ai   ==>  tst_val is modified
    exchanged= ai.compare_exchange_strong( tst_val, new_val );
    printValues();
 
    // tst_val == ai   ==>  ai is modified
    exchanged= ai.compare_exchange_strong( tst_val, new_val );
    printValues();
}