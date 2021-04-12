//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

struct Device
{
    enum class State_e{SLEEP, READY, BAD};
    State_e state() const {return _state;}
    
    operator State_e() {return _state;} //do we need this?
private:
    State_e _state = State_e::READY;
};
Device get_device(){
    return Device();
}

int main()
{
    //In order to do this we need neither:
    //1. declare dev in the outer scope and here test dev.state()
    //2. or supply a conversion from the device to enum type
    switch (Device dev = get_device()) 
    {
       case Device::State_e::SLEEP: /*...*/ break;
       case Device::State_e::READY: /*...*/ break;
       case Device::State_e::BAD: /*...*/ break;
    }
    // the C++17 init-statement syntax can be helpful when there is
    // no implicit conversion to integral or enumeration type
    switch (Device dev = get_device(); dev.state())
    {
       case Device::State_e::SLEEP: /*...*/ break;
       case Device::State_e::READY: /*...*/ break;
       case Device::State_e::BAD: /*...*/ break;
    }
}