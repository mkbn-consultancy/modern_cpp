//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
//source: https://vorbrodt.blog/2019/03/24/propagate-exceptions-across-threads/

#include <iostream>
#include <sstream>
#include <thread>
#include <exception>
#include <stdexcept>

int main(int, char**)
{
	std::exception_ptr ep = nullptr;

	std::thread t([&ep](){
		try{
			std::stringstream str;
			str << std::this_thread::get_id();
			throw std::runtime_error(str.str().c_str());
		}
		catch(...){
            std::cout<<"[THREAD "<<std::this_thread::get_id()<<"]: throwing an exception\n";
			ep = std::current_exception();
		}
	});
	t.join();

    //check the exception caught in the main thread
	if(ep != nullptr)
	{
		try{
			rethrow_exception(ep);
		}
		catch(std::exception& e)
		{
			std::cout << "[THREAD " << std::this_thread::get_id() << "]: caught exception from thread " << e.what() << std::endl;
		}
	}
}