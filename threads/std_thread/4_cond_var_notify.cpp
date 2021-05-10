//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//

#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
 
std::condition_variable cv;
std::mutex cv_m; // This mutex is used for three purposes:
                 // 1) to synchronize accesses to i
                 // 2) to synchronize accesses to std:: cout
                 // 3) for the condition variable cv
int i = 0;
 
void waits(int index)
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cerr << "[waits:] Thread #"<<index<<" is waiting... \n";
    cv.wait(lk, [index]{if(i!=1){ std::cout<<"[bool pred:] Thread #"<<index<<" continues sleeping...\n";}
                        return i == 1;
                       });
    std::cerr << "[waits:] ...thread #"<<index<<" finished waiting. i == 1\n";
}
 
void signals(int index)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lk(cv_m);
        std::cout << "[signals:] Thread #"<<index<<" is notifying...\n";
    }
    cv.notify_all();
 
    std::this_thread::sleep_for(std::chrono::seconds(1));
 
    {
        std::lock_guard<std::mutex> lk(cv_m);
        std::cout << "[signals:] Thread #"<<index<<" changes i to be 1...\n";
        i = 1;
        std::cout << "[signals:] Thread #"<<index<<" is notifying again...\n";
    }
    cv.notify_all();    //threads will wake up since now i==1
}
 
int main()
{
    std::cout<<"\n---------------------------------\n";
    std::cout<<"[main:] creating 4 threads...\n";
    std::thread t1(waits,1), t2(waits,2), t3(waits,3), t4(signals,4);
    t1.join(); 
    t2.join(); 
    t3.join();
    t4.join();
    std::cout<<"[main:] main finished...\n";
    std::cout<<"\n---------------------------------\n";
}
