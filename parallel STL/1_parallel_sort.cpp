#include <algorithm>
#include <random>
#include <vector>
#include <execution>
#include <chrono>

#include <iostream>

int main() {
    constexpr size_t testSize = 10'000'000;
    // std::random_device rd;
    std::default_random_engine engine{std::random_device{}()};
    std::uniform_int_distribution<long> dist{0,testSize};
    // generate some random numbers:
    std::vector<long> numbers(testSize);

    for (int i=0; i<testSize; ++i) {
        numbers.push_back(dist(engine));
    }

    //--------------------------------------------
    using clock_time_t = std::chrono::steady_clock::time_point;

    clock_time_t start = std::chrono::steady_clock::now();

    // std::string type = "Serial: ";
    // std::sort(std::execution::seq, numbers.begin(), numbers.end());
    std::string type = "Parallel: ";
    std::sort(std::execution::par_unseq, numbers.begin(), numbers.end());

    clock_time_t end = std::chrono::steady_clock::now();

    auto dif = end-start;
    std::cout   <<type
                <<std::chrono::duration_cast<std::chrono::milliseconds>(dif).count()
                <<std::endl;

}

