
#include <iostream>
#include <thread>

class semaphore
{
public:

 
private:
};

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