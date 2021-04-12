//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
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
        //   create a new node into a temp object
        std::shared_ptr<Node<T>> newHead = new Node<T>;
        newHead->_value = val;

        currentHead = _head;
        // if(temp==_head){
        //     newHead->_next = _head;
        //     _head.store(newHead)
        // }
        _head = newHead;

        do{
            newNode->_next = currentHead;
        }(!_head.compare_exchange_strong(currentHead, newHead));

        //2. update the _head (do the swap of the value)
    }
private:
    std::atomic<std::shared_ptr<Node<T>>>  _head;
};