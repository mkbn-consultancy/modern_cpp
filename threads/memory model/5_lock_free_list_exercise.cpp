#include <atomic>
#include <memory>

template<class T>
struct Node{
    T _value;
    std::shared_ptr<Node>    _next;
};


template<class T>
class List
{
public:
    List() = default;
    ~List() = default;

    void push_front(T val){
        //TODO: implement
        //...
        //1. prepare the data
        //2. update the _head (do the swap of the value)
    }
private:
    std::atomic<std::shared_ptr<Node<T>>>  _head;
};