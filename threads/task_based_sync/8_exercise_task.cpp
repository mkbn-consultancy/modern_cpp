#include <thread>
#include <iostream>

using namespace std::chrono_literals;

int main()
{
    std::cout<<"\n----------------------------------\n";

    //create a task that will return an array with the numbers 1,...,25
    std::cout<<"[main]: creating the task for creating the array...\n";

    //create a task that will get as a std::promise the vector that the former task returned
    //and will return the sum of all vector's elements        
    //(try to use lambda expression istead of a function)
    std::cout<<"[main]: creating the task for sum the array...\n";

    std::this_thread::sleep_for(5s);

    //set the data to the promise so it will be able to work
    std::cout<<"[main]: set data to promise...\n";

    //get the result from the second task and print the sum

    std::cout<<"\n----------------------------------\n";
}