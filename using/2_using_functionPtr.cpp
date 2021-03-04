#include <vector>
#include <list>
#include <iostream>

using IntVector = std::vector<int>;

class Employee{ /*...*/};
using RDGroups = std::vector<std::list<Employee>>;
RDGroups ui_teams;
RDGroups::iterator it = ui_teams.begin();

//---------------------------------------------------------------------------------

const char* getErrorMessage(int errorNum){
    //... implement creating the right message according to errorNum
    return "Testing...\n";
}
//v1
void printErrorMsg_v1(const char *(*pfn)(int), int errorNum){
    std::cout<<"ERROR: "<<(*pfn)(errorNum)<<std::endl;
}
//v2
typedef const char* (*PFN_t)(int);
void printErrorMsg_v2(PFN_t pfn, int errorNum){
    std::cout<<"ERROR: "<<(*pfn)(errorNum)<<std::endl;
}
//v3
using PFN = const char* (*)(int);
void printErrorMsg_v3(PFN pfn, int errorNum){
    std::cout<<"ERROR: "<<(*pfn)(errorNum)<<std::endl;
}

int main()
{
    printErrorMsg_v1(getErrorMessage,0);
    printErrorMsg_v2(getErrorMessage,0);
    printErrorMsg_v3(getErrorMessage,0);
}

