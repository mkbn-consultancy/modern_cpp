//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//

//source: https://gist.github.com/sguzman/9594227

#include <mutex>
#include <condition_variable>
#include <iostream>
#include <chrono>
#include <thread>

class semaphore
{
public:

  semaphore(int count_ = 0) : count{count_}
  {}

  void signal(){
    std::unique_lock<std::mutex> lck(mtx);
    ++count;
    cv.notify_one();
  }

  void wait(){
    std::unique_lock<std::mutex> lck(mtx);
    while(count == 0){
      cv.wait(lck); //unique_lock has a bool() operator to check if it is locked or not
    }
    //now the lck is locked by us so we can update count.
    --count;
  }

private:
  std::mutex mtx;
  std::condition_variable cv;
  int count;
};

semaphore sem(3);

void thread(int id)
{
    //wait
    sem.wait();
    std::cout<<"Thread #"<<id<<" entered..\n";
  
    //critical section
    std::this_thread::sleep_for(std::chrono::seconds(2));
      
    //signal
    std::cout<<"Thread #"<<id<<" just Exiting...\n";
    sem.signal();
}

int main(){
    std::thread t1(thread,1);
 
    // std::this_thread::sleep_for(std::chrono::seconds(2));
   
    std::thread t2(thread,2);
    std::thread t3(thread,3);
    std::thread t4(thread,4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}