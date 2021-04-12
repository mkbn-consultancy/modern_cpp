//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <string>
#include <experimental/string_view>

int testString()
{
  char text[]{ "hello" };
  std::string str{ text };
  std::string more{ str };
 
  str+=" world";
  std::cout << text << " // " << str << " // " << more << '\n';
  
  return 0;
}

int testStringView()
{
  char text[]{ "hello" }; // view the text "hello", which is stored in the binary
  std::experimental::string_view str{ text }; // view of the same "hello"
  std::experimental::string_view more{ str }; // view of the same "hello"
 
  text[0] = 'H';

  std::cout << text << ' ' << str << ' ' << more << '\n';
 
  return 0;
}


int main()
{
    testString();

    testStringView();

}