#include <string>
#include <vector>
#include <map>
// #include <iostream>

int main()
{
    std::string s{"hello"};
    std::string s2{s}; //copy constructor

    std::vector<std::string> vs{"alpha", "beta", "gamma"};

    std::map<int,int> sources {{1,58}, {2,79}};

    double* pd = new double[3] {0.5, 1.2, 12.99};
}
//-----------------------------------------------------
class C{
    int x[4];
public:
    C() : x{0,1,2,3} {}
};
//-----------------------------------------------------
struct Blah{
    //will use a default constructor string if none is provided
    //instead of writing Blah(const std::string& s = std::string()) : _s(s) {}
    explicit Blah(const std::string& s = {}) : _s{s} {}
private:
    std::string _s;
};

