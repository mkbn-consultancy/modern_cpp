//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <string>

void printRef(const std::string& str){
    std::cout<<"print const ref&: "<<str<<std::endl;
}

void printRef(std::string&& str){ //create str from a temp without paying deep copy?
    std::cout<<"print ref&&: "<<str<<std::endl;
    str+="Cohen";
}

std::string getName(){
    return "Joe";
}

int main()
{
    std::string me("Miri");
    printRef(me);

    printRef(getName());
}


