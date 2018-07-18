#include <iostream>
#include <map>
#include <string>

template <typename Integer>
void world_population() {
    // https://en.wikipedia.org/wiki/List_of_continents_by_population
    // in 2010
    std::cout << "Sizeof(Integer) : " << sizeof(Integer) << std::endl;

    std::map<std::string, Integer> continents = {
            {"africa",  1044107001},
            {"americas", 943952001},
            {"asia",    4169860001},
            {"europe",   735395001},
            {"oceania",   36411001}
    };

    Integer total = 0;
    for (auto &continent : continents) {
        std::cout << continent.first << " : " << continent.second << std::endl;
        total += continent.second;
    }
    std::cout <<  "Total world population : " << total << std::endl;
    std::cout <<  "Larger than Asia alone : " << (total > continents["asia"] ? "true" : "false") << std::endl;
}


int main()
{
    // 1) What's wrong with:
    world_population<uint32_t>();
    // 2) Fix it:
    // ...

    return 0;
}
