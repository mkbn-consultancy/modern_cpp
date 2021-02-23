#include <iostream>

//---------------------------------------------------
// The class that runs the algorithm on T object

template< bool b > 
struct algorithm_selector 
{ 
  template< typename T > 
  static void implementation( T& object ) 
  { 
	//implement the algorithm operating on "object" here 
     std::cout<<"default implementation\n";
  } 
};

template<> 
struct algorithm_selector< true >
{ 
  template< typename T > 
  static void implementation( T& object )
  { 
      object.optimised_implementation(); //let T do that
  } 
};

//---------------------------------------------------

class ObjectA{
    //... has nothig special ...
};

class ObjectB { 
public: 
  void optimised_implementation() { 
      //sepcific implementation for ObjectB...
      std::cout<<"ObjectB implementation\n";
  } 
};

//specialisation of supports_optimised_implementation trait 
//for ObjectB
template<class T> 
struct supports_optimised_implementation { 
  static const bool value = false; 
};

template<> 
struct supports_optimised_implementation< ObjectB > { 
  static const bool value = true; 
};

//---------------------------------------------------

template< typename T > 
void algorithm( T& object ) { 
  algorithm_selector< supports_optimised_implementation< T >::value >
	::implementation(object); 
}

//---------------------------------------------------
int main(int argc, char* argv[]) { 

  ObjectA a; 
  algorithm( a ); //calls default implementation 
  
  ObjectB b; 
  algorithm( b ); //calls ObjectB::optimised_implementation(); 
  
  return 0; 
}
