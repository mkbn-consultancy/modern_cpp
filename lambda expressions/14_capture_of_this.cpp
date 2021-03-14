#include <iostream>
#include <string>

class Example{
public:
    Example() : _var{10} {std::cout<<"default ctor\n";}
    Example(const Example& e) : _var(e._var) {std::cout<<"copy ctor\n";}
    void func()
    {
        [*this]() mutable {++_var;
            std::cout<<"inside [*this]: "<<_var<<std::endl;
        }();
    }
public:
    int _var;
};
int test1(){
    Example e;
    e.func();
    std::cout<<e._var<<std::endl;   //didn't changed
}

//---------------------------------------

class Data
{
public:
    Data(const std::string& name, int id) : _name(name), _id(id){}

    // std::string getDescription(const std::string& header){
    //     std::string desc = header;
    //     desc += "\n";
    //     desc = desc + "name: " + _name + "\n";
    //     desc = desc + "id: " + std::to_string(_id) + "\n";
    //     return desc;
    // }

    auto getDescription(){
        return [this](const std::string& header){
            std::string desc = header;
            desc += "\n";
            desc = desc + "name: " + _name + "\n";
            desc = desc + "id: " + std::to_string(_id) + "\n";
            return desc;
        };
    }

private:
    std::string _name;
    int _id;
};

int test2(){
    Data d("product",10);
    auto descF = d.getDescription();
    std::cout<<descF("=====")<<std::endl;

    //if we declare d on the heap, it may cause a problem if
    //we delete it before we call the lambda.
    //this is why we should capture [*this].
    //this must be copyable.
}

