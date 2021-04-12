//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <optional>
#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>

std::optional<std::string> readFile(const std::string& fName)
{
    std::ifstream fin(fName);
    if(!fin.is_open()){
        //error. no such file or directory.
        //what if we do not want to use exceptions?
        return{};
    }

    std::string content;
    //read the file into content string...
    return content;
}

std::optional<int> getNumber(){
    // return 5;
    return std::nullopt; //same as return {}
}

int main()
{
    //--- initialize an optional ---//
    std::optional<int> op1; //empty one
    std::optional op2{4};   //direct initialization using CTAD
    std::optional op3 = std::make_optional(5);

 
    //--- check if there is a return value ---//
    auto res = readFile("not_a_real_file");

   //we can use the has_value method
    if(!res.has_value()){
        std::cout<<"something went wrong with this file...\n";
    }
    //we can use the bool operator
    if(!res){
        std::cout<<"something went wrong with this file...\n";
    }
    //another option is to use value_or method:
    std::cout<<res.value_or("no such file or directory")<<std::endl;
    //the value of the parameter must be as T
    // std::cout<<res.value_or(5)<<std::endl;  //error!

    //--- get the value out of the optional object ---//

    if(auto num = getNumber()){
        //use the value() method
        std::cout<<"number is: "<<num.value()<<std::endl;
        //use operator*
        std::cout<<"number is: "<<*num<<std::endl;
        // std::cout<<"number is: "<<num<<std::endl;   //error!
    }

    
    try{
        auto res = getNumber();
        //next line throws an exception!
        std::cout<<"trying to print the empty optional: "<<res.value()<<std::endl;
        //but this one is undefined behavior:
        std::cout<<*res;
    }catch(std::bad_optional_access& e){
        std::cout<<"[exception] "<<e.what()<<std::endl;
    }
}