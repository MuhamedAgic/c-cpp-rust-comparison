#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> vec(10);
    std::iota(vec.begin(), vec.end(), 1);

    // Square in place using parallel transform
    std::transform(std::execution::par, vec.begin(), vec.end(), vec.begin(),
                   [](int x) { return x * x; });

    // Filter out values less than threshold
    int threshold = 10;
    std::vector<int> filtered;
    std::copy_if(std::execution::par, vec.begin(), vec.end(), std::back_inserter(filtered),
                 [threshold](int x) { return x >= threshold; });

    std::cout << "Filtered squares >= " << threshold << ":\n";
    for (auto v : filtered)
        std::cout << v << ' ';
    std::cout << '\n';

    return 0;
}
