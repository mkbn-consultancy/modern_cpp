//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <experimental/string_view>
 
int main()
{
  std::experimental::string_view str{ "Peach" };
 
  std::cout << str << '\n';
 
  // Ignore the first character.
  str.remove_prefix(1);
 
  std::cout << str << '\n';
 
  // Ignore the last 2 characters.
  str.remove_suffix(2);
 
  std::cout << str << '\n';
 
  return 0;
}
