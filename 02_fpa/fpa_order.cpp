#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <iomanip>

class SumOrderDiff {
public:
    SumOrderDiff(int n) : v(n) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist1(std::numeric_limits<float>::min(), 1);

        std::generate(v.begin(), v.begin() + n, [&dist1, &gen]{return dist1(gen);});
    }

    float sum_raw() {
        return std::accumulate(v.begin(), v.end(), 0.f);
    }

    float sum_sorted() {
        auto v_sorted(v);
        std::sort(v_sorted.begin(), v_sorted.end(), std::less<float>());
        return std::accumulate(v_sorted.begin(), v_sorted.end(), 0.f);
    }

    float sum_reverse_sorted() {
        auto v_sorted(v);
        std::sort(v_sorted.begin(), v_sorted.end(), std::greater<float>());
        return std::accumulate(v_sorted.begin(), v_sorted.end(), 0.f);
    }

    void show_different_sum_order_results() {
        std::cout << "=========================================\n";
        std::cout << " Summing " << v.size() << " elements\n ";

        std::cout.precision(std::numeric_limits<float>::digits10);

        std::cout << std::endl;
        std::cout << std::setw(30) << "Sum of as-is vector: " << sum_raw() << std::endl;
        std::cout << std::setw(30) << "Sum of sorted vector: " << sum_sorted() << std::endl;
        std::cout << std::setw(30) << "Sum of reverse sorted vector: " << sum_reverse_sorted() << std::endl;
        std::cout << std::endl;
    }

private:
    std::vector<float> v;
};


int main() {
    for (auto n : {100, 1000, 10000, 1000000, 10000000}) {
        SumOrderDiff sod(n);
        sod.show_different_sum_order_results();
    }

    return 0;
}