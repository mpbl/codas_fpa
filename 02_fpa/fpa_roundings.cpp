#include <vector>
#include <random>
#include <cfenv>
#include <iostream>
#include <iomanip>

class SumRoundings {
public:
    SumRoundings(int n) : v(n)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist1(std::numeric_limits<float>::min(), 1);

        // std::generate(v.begin(), v.begin() + n, [&dist1, &gen] { return dist1(gen); });
        for (auto &x: v) {
            x = dist1(gen);
        }
    }

    float sum()
    {
        return std::accumulate(v.begin(), v.end(), 0.f);
    }

    void show_different_rounding_results()
    {
        std::cout << "=========================================\n";
        std::cout << " Summing " << v.size() << " elements\n ";

        std::cout.precision(std::numeric_limits<float>::digits10);

        std::cout << std::endl;

        std::fesetround(FE_DOWNWARD);
        std::cout << std::setw(30) << "Sum, rounding downward: " << sum() << std::endl;

        std::fesetround(FE_TONEAREST);
        std::cout << std::setw(30) << "Sum, rounding to nearest: " << sum() << std::endl;

        std::fesetround(FE_TOWARDZERO);
        std::cout << std::setw(30) << "Sum, rounding toward zero: " << sum() << std::endl;

        std::fesetround(FE_UPWARD);
        std::cout << std::setw(30) << "Sum, rounding upward: " << sum() << std::endl;

        std::cout << std::endl;
    }

private:
    std::vector<float> v;
};

int main() {
    for (auto n : {100, 1000, 10000, 1000000, 10000000}) {
        SumRoundings sr(n);
        sr.show_different_rounding_results();
    }
    return 0;
}
