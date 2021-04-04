#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
 
std::condition_variable cv;
std::mutex cv_m; // This mutex is used for three purposes:
                 // 1) to synchronize accesses to i
                 // 2) to synchronize accesses to std::cerr
                 // 3) for the condition variable cv
int i = 0;
 
void waits(int index)
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cerr << "Thread #"<<index<<" is waiting... \n";
    cv.wait(lk, [index]{if(i!=1){ std::cout<<"Thread #"<<index<<" continues sleeping...\n";}
                        return i == 1;
                       });
    std::cerr << "...thread #"<<index<<" finished waiting. i == 1\n";
}
 
void signals(int index)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lk(cv_m);
        std::cout << "Thread #"<<index<<" is notifying...\n";
    }
    cv.notify_all();
 
    std::this_thread::sleep_for(std::chrono::seconds(1));
 
    {
        std::lock_guard<std::mutex> lk(cv_m);
        i = 1;
        std::cout << "Thread #"<<index<<" is notifying again...\n";
    }
    cv.notify_all();    //threads will wake up since now i==1
}
 
int main()
{
    std::thread t1(waits,1), t2(waits,2), t3(waits,3), t4(signals,4);
    t1.join(); 
    t2.join(); 
    t3.join();
    t4.join();
}
