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

    //TODO: use structured binding to print all keys & values in map
	for(auto itr = sites.begin(); itr!=sites.end(); ++itr){
		std::cout<<itr->first<<" : "<<itr->second<<std::endl;
		// std::cout<<siteName<<" : "<<siteDescr<<std::endl;
	}

	return 0; 
} 
