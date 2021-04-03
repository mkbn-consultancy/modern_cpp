#include <optional>
#include <string>

class ContactData
{
public:
    ContactData(const std::string& f, 
                const std::optional<std::string>& m,
                const std::string& l) : _first{f}, _middle{m}, _last{l}
    {}

private:
    std::string _first;
    std::optional<std::string> _middle;
    std::string _last;
};

int main()
{
    //no need to create an empty std::string in the class
    ContactData cd("John",std::nullopt ,"Doe");
}