#include <iostream>
#include <map>
#include <string>

template <typename Integer>
void world_population() {
    // https://en.wikipedia.org/wiki/List_of_continents_by_population
    // in 2010
    std::cout << "Sizeof(Integer) : " << sizeof(Integer) << std::endl;

    std::map<std::string, Integer> continents = {
            {"africa", 1'044'107'001},
            {"americas", 943'952'001},
            {"asia",   4'169'860'001},
            {"europe",   735'395'001},
            {"oceania",   36'411'001}
    };

    Integer total = 0;
    for (auto &continent : continents) {
        total += continent.second;
    }
    std::cout <<  "Total world population : " << total << std::endl;
}


int main()
{
    // 1) What's wrong with:
    world_population<int32_t>();
    // 2) Fix it:
    // ...

    return 0;
}