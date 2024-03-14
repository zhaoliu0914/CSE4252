#include <vector>
#include <iostream>
// You may add other header files if needed
using namespace std;

class Example {
public:
    int a;

    // This function will take
    // object as arguments and
    // return object
    Example add(Example Ea, Example Eb) {
        Example Ec;
        Ec.a = Ea.a + Eb.a;

        // returning the object
        return Ec;
    }
};