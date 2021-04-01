//source : https://stackoverflow.com/questions/38501587/what-are-the-evaluation-order-guarantees-introduced-by-c17

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

struct Speaker{
    int i =0;
    Speaker(std::vector<std::string> words) :words(words) {}

    std::vector<std::string> words;

    std::string operator()(){
        assert(words.size()>0);
        if(i==words.size()) {
            i=0;
        }
        // Pre-C++17 version:
        auto word = words[i] + (i+1==words.size()?"\n":",");
        ++i;
        return word;
        // Still not possible with C++17:
        // return words[i++] + (i==words.size()?"\n":",");
    }
};

int main() {
    auto spk = Speaker{{"All", "Work", "and", "no", "play"}};
    std::cout << spk() << spk() << spk() << spk() << spk() ;
}