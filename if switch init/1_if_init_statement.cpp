//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <string>
#include <iostream>
#include <fstream>
#include <set>

void test1()
{
    const std::string myString = "My Hello World Wow";

    //we need the variable it only for the if
    const auto it = myString.find("Hello");
    if (it != std::string::npos){
        std::cout << it << " Hello\n";
    }
    //what if we don't need it anymore from here?
}

void test2()
{
    const std::string myString = "My Hello World Wow";
    
    {
        const auto it = myString.find("Hello");
        if (it != std::string::npos){
            std::cout << it << " Hello\n";
        }
    }
}

void test3()
{
    const std::string myString = "My Hello World Wow";

    //we need the variable it only for the if
    if (const auto it = myString.find("Hello"); it != std::string::npos){
        std::cout << it << " Hello\n";
    }
    //it is not declared in this scope
}

void test4()
{
    const std::string myString = "My Hello World Wow";

    //we need the variable it only for the if
    if (const auto it = myString.find("Program"); it != std::string::npos){
        std::cout << it << " Program\n";
    }
    else{
        std::cout << "Try another string since we got index "<<it<<"...\n";
    }
    //it is not declared in this scope
}

void test5(const std::string& message)
{
    if(std::ofstream fout("output.txt"); !message.empty()){
        fout<<message;
    }
    else{
        fout<<"empty message";
    }
    //here the fout is not recognized and destroyed (file closed)
}

void test5()
{
    using mySet = std::set<std::pair<std::string,int>>;
    mySet set1;
    std::pair<std::string,int> itemsToAdd[3]{{"hello",1},{"world",1},{"world",2}};
    for(auto &p : itemsToAdd)
    {
        // if-initializer + structured binding
        if(const auto [iter,inserted] = set1.insert(p);inserted)
        {
            std::cout << "Value(" << iter->first << ", " << iter->second << ") was inserted\n";
        }
        else
        {
            std::cout << "Value(" << iter->first << ", " << iter->second << ") was not inserted\n";
        }
    }
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}