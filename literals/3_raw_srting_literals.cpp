#include <iostream>

int main()
{
//    const char* fname1 = "c:\users\files\file.txt"; //error! tries to process \u and \f

    const char* fname2 = "c:\native\actions\team.txt";  //not sure we got the string we wanted...
    std::cout<<fname2<<std::endl; 

    const char* fname3 = R"(c:\native\actions\team.txt)";
    std::cout<<fname3<<std::endl; 

    const char* name = R"(Miri (Kopel) Ben-Nissan)";
    std::cout<<name<<std::endl;

    //what if I want to print ")" on screen, including the ""?
    // const char* parens = R"This course is called Modern C++ ("C++11/14/17")";   //Compilation Error!
    const char* parens = R"d_d(This course is called Modern C++ ("C++11/14/17)")d_d";   //Compilation Error!
    std::cout<<parens<<std::endl;
}
