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


class ThreadPool {
public:
    ThreadPool(size_t);

    template<class F, class... Args>
    auto addTask(F&& f, Args&&... args) 
        -> std::future<typename std::result_of<F(Args...)>::type>;
    
    ~ThreadPool();

protected:
    void createThreads(size_t);
 
private:
    std::vector< std::thread > _workers;
    std::queue< std::function<void()> > _tasks;
    
    // synchronization
    std::mutex _queue_mutex;
    std::condition_variable _condition;
    bool _stop;
};
 
// the constructor just launches some amount of workers
ThreadPool::ThreadPool(size_t poolSize)
    :   _stop(false)
{
    std::cout<<"[ThreadPool] inside constructor\n";
    createThreads(poolSize);

}

void ThreadPool::createThreads(size_t poolSize)
{
    std::cout<<"[ThreadPool] inside createThreads...";
    for(size_t i = 0;i<poolSize;++i){
       _workers.emplace_back( //Inserts a new element at the end of the vector. 
            [this]{
				//this thread will run this code
                for(;;){ //will take from queue a task and run it
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(this->_queue_mutex);
						//The execution of the current thread (which shall have locked lck's mutex) 
						//is blocked until notified.
						//A callable object or function that takes no arguments and returns a value 
						//that can be evaluated as a bool.
						//This is called repeatedly until it evaluates to true.
                        this->_condition.wait(lock,
							//if the thread pool is stopped or empty - stop waiting
                            [this]{ return this->_stop || !this->_tasks.empty(); });
						if (this->_stop && this->_tasks.empty()) {
							//no work to do. no further task will come.
							return;
						}
                        task = std::move(this->_tasks.front());
                        this->_tasks.pop();
                    }
					//call the task in this thread
                    task();
                }
            }
        );
    }
    std::cout<<"done!\n";
}

template<class F, class... Args>
auto ThreadPool::addTask(F&& f, Args&&... args) 
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    std::cout<<"[ThreadPool] inside addTask...\n";
	//This function will return the result of the F with args.
    using return_type = typename std::result_of<F(Args...)>::type;
	//A packaged_task wraps a callable element and allows its result to be retrieved asynchronously.
    auto task = std::make_shared< std::packaged_task<return_type()> >(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    
    std::future<return_type> res = task->get_future();
    
    //lock the tasks Q in order to add the new task
    {
        std::unique_lock<std::mutex> lock(_queue_mutex);

        // don't allow enqueueing after stopping the pool
		if (_stop) {
			throw std::runtime_error("Cannot add more tasks to the ThreadPool");
		}
        //insert the new task to the Q.
        _tasks.emplace([task](){ (*task)(); });
    }
    //release one of the threads that wait for incoming task
    _condition.notify_one();

    return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(_queue_mutex);
        _stop = true;
    }
    _condition.notify_all(); //unlock all tasks
	for (std::thread &worker : _workers) {
		worker.join(); //wait for all tasks to finish
	}
}

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
