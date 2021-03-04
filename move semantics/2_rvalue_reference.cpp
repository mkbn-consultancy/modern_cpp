#include <iostream>
#include <string>

void printRef(const std::string& str){
    std::cout<<"print const ref&: "<<str<<std::endl;
}

void printRef(std::string&& str){
    std::cout<<"print ref&&: "<<str<<std::endl;
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