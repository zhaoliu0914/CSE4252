#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc != 3) {
        return 0;
    }
    char *end;
    // Please check https://cplusplus.com/reference/cstdlib/strtoll/
    // about how to use strtoll
    long long num1 = strtoll(argv[1], &end, 10);
    long long num2 = strtoll(argv[2], &end, 10);

    std::cout << num1 + num2 << std::endl;

    return 0;
}

