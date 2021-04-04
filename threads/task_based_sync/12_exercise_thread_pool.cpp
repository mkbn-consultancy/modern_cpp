#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

//includes for testing:
#include <iostream> //for testing
using namespace std::chrono_literals; 

//////////////////////////////////////////////////////////////

class ThreadPool
{
public:
    //1. constructor that gets the pool's size and creates the threads

    //2. addTask 


private:
    //1. vector of threads

    //2. queue of tasks

    //3. some synchronization stuff...
};

//////////////////////////////////////////////////////////////

void func1() {
	std::cout << "in func1\n";
}

void func2(int i) {
	std::cout << "in func2 with parameter " << i << std::endl;
}

int main()
{
    std::cout<<"[main] creating a thread pool - example 1\n";
	//example 1
	ThreadPool pool1(2);
	pool1.addTask(func1);
	pool1.addTask(func2, 3);
    
    std::cout<<"----------------------------\n";
    std::cout<<"[main] creating a thread pool - example 2\n";
	//example 2
    ThreadPool pool2(4);
    std::vector< std::future<int> > results;

    //addTask returns the future of the thread when it starts running
    //we add 8 tasks for the thread pool (4 threads will handle them)
    for(int i = 0; i < 8; ++i) {
        results.emplace_back(
            pool2.addTask([i] {
                std::cout << "hello " << i << std::endl;
                std::this_thread::sleep_for(1s);
                std::cout << "world " << i <<std::endl;
                return i*i;
            })
        );
    }

    for(auto && result: results)
        std::cout <<'['<< result.get() << ']';
    std::cout << std::endl;

    return 0;
}
