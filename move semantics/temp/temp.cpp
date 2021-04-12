//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
struct A
{
    A() {
        std::shared_ptr<int> pool =  new int[10];
        //EXCEPTION!!!
        _data = new int[20];
    }

private:
    int* _pool;
    int* _data;
}