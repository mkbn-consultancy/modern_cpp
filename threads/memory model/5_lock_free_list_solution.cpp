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
        //1. prepare the data
        std::shared_ptr<Node<T>> newHead = new Node<T>;
        newNode->_value = val;
        
        std::shared_ptr<Node<T>> currentHead = _head;

        //2. update the _head (do the swap of the value)

        //we would like to exchange the value of _head (currentHead) with the new value (newHead),
        //but we need to verify that the value of _head is most updated.
        do{
            newNode->_next = currentHead;
        }while(!_head.compare_exchange_strong(currentHead,newHead));
    }
private:
    std::atomic<std::shared_ptr<Node<T>>>  _head;
};