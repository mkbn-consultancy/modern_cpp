#include <iostream>
#include <memory>

struct Data
{
    Data(int id) : _id(id) {std::cout<<"[Data] ctor\n";}
    Data(const Data&) {std::cout<<"[Data] copy ctor\n";}
    Data(Data&&) {std::cout<<"[Data] move ctor\n";}
    ~Data() {std::cout<<"[Data] destructor\n";}

    int _id;
};

int main(){
    std::shared_ptr<Data> p1 = std::make_shared<Data>(1);
    std::shared_ptr<Data> p2(p1);

    std::cout<<"p1 ref.cnt = "<<p1.use_count()<<"\t id = "<<(*p1)._id<<std::endl;
    p1.reset();
    std::cout<<"p1 ref.cnt = "<<p1.use_count()<<std::endl;

    p1 = std::make_shared<Data>(2);
    std::cout<<"p1 ref.cnt = "<<p1.use_count()<<"\t id = "<<(*p1)._id<<std::endl;

}