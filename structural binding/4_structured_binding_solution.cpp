//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream> 
#include <map> 
using namespace std; 

int main() 
{ 
	// Creating a map with key and value 
	// fields as String 
	map<string, string> sites; 
	
	sites.insert({ "GeeksforGeeks", "Coding Resources" }); 
	sites.insert({ "StackOverflow", "Q-A type" }); 
	sites.insert({ "Wikipedia", "Resources + References" }); 

    //use structured binding to print all keys & values in map
	for (auto & [ key, value ] : sites) 
	{ 
	    cout << key << " " << value << endl; 
	} 
	
	return 0; 
} 
