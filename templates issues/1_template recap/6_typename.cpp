//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <vector>
#include <iostream>
#include <cassert>

template <typename T> 
T inner_product (const std::vector<T>& v1, const std::vector<T>& v2) { 
    T res= 0; 
    typename std::vector<T>::const_iterator iter1; 
    typename std::vector<T>::const_iterator iter2; 
    for (iter1= v1.begin(), iter2= v2.begin(); 
            iter1!=v1.end(); 
            ++iter1,++iter2) 
    { 
	    assert(iter2!=v2.end());
        res+= (*iter1) * (*iter2); 
    }
    assert(iter2==v2.end());
    return res;
}

int main(){
    std::vector<int> v1 = {1,2,3,4};
    std::vector<int> v2 = {4,5,6,7};

    std::cout<<"inner product is: "<<inner_product(v1,v2)<<std::endl;
}



