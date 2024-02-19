#include <iostream>
#include "temperature.h"

int main() {
    Temperature temp;
    double celsius = 100.0;
    double fahrenheit = temp.celsius2fahrenheit(celsius);
    std::cout << " Convert " << celsius << " in Celsius to Fahrenheit is "
        << fahrenheit << std::endl;

    fahrenheit = 32.0;
    celsius =  temp.fahrenheit2celsius(fahrenheit);
    std::cout << " Convert " << fahrenheit << " in Fahrenheit to Celsius is "
        << celsius << std::endl;
}
