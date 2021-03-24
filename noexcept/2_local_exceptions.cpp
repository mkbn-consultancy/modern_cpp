#include <random>
#include <iostream>

void processData(){
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(5.0,3.0);
    std::vector<double> data;
    //fill the container with random numbers:
    for(int i=0; i<10; ++i){
        // std::cout<<distribution(generator)<<"  ";
        data.push_back(distribution(generator));
    }
      
    //assume valid data is only between 2.0 and 7.0
    for(auto x : data){
        try{
            if(x<2.0 || x>7.0){
                throw std::runtime_error("invalid data, cannot process\n");
            }
            else{
                std::cout<<"processing "<<x<<std::endl;
            }
        }
        catch(std::runtime_error& err){
            std::cout<<"in processData: Exception: "<<err.what();
        }
    }
}

int main(){
    processData();
}