#include <iostream>
#include <string>
#include <fstream>


int main(int argc, char*argv[]) {
    std::string last(argv[argc - 1]);
    std::string flag = "-s";
    bool sqflag = false;
    if (!last.compare(flag)) {
        // Squeeze the empty line
        sqflag = true;
    }


    // Your code

    return 0;
}
