#include <iostream>
#include <vector>

#include "vector_test.h"

int main() {
    std::vector<std::vector<float>> b = {
            {1.0, 2.0},
            {3.0, 4.5},
            {5.0, 6.0}
    };

    std::cout << b[0].size() << std::endl;

    //std::vector<int> rowVector;
    //rowVector.resize(3);
    std::vector<std::vector<int>> result(2, std::vector<int>(3));
    std::cout << "result.size = " << result.size() << std::endl;

    result[0][0] = 1;
    result[1][1] = 4;

    Example E1;
    E1.a = 50;

    Example E2;
    E2.a = 100;

    Example E3;

    Example E4 = E3.add(E1, E2);
    std::cout << "New values \n";
    std::cout << "Value of object 1: " << E1.a
         << ", \nobject 2: " << E2.a
         << ", \nobject 4: " << E4.a
         << "\n";

}
