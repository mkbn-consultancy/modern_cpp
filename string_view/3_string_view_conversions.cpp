#include <iostream>
#include <string>
#include <experimental/string_view>
#include <cstring>

void func(std::string s)
{}
 
void convertToString()
{
  std::experimental::string_view sv{ "hello" };
 
//   func(sv); // compile error: won't implicitly convert
 
  std::string str{ sv }; // okay
 
  func(str); // okay
 
  func(static_cast<std::string>(sv)); // okay
}

void convertToCStyleString()
{
  std::experimental::string_view sv{ "hello" };
  
  // Create a std::string from the std::string_view
  std::string str{ sv };
 
  // Get the null-terminated C-style string.
  const char* szNullTerminated{ str.c_str() };
 
  // Pass the null-terminated string to the function that we want to use.
  std::cout << str << " has " << std::strlen(szNullTerminated) << " letter(s)\n";
}

int main(){
    convertToCStyleString();
}