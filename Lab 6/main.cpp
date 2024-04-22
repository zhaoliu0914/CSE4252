#include <iostream>
#include <vector>
#include <array>
#include "parallel_sort.h"

int main() {
    std::vector<int> array;
    std::vector<double> decArr;
    std::array<int, 10> arr10 = {10, 9, 8, 7, 6, 5, 4, 1, 2, 3};
    std::array<double, 5> arr5 = {1.0, 8.1, 2.0, 5.0, 1.0};

    for (int i = 0; i < 100; ++i) {
        array.push_back(100 - 2 * i);
        decArr.push_back((100.0 - i)/ 0.5);
    }

    parallelSort(array.begin(), array.end());
    parallelSort(decArr.begin(), decArr.end());
    parallelSort(arr10.begin(), arr10.end());
    parallelSort(arr5.begin(), arr5.end());

}
