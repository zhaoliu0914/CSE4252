#include "temperature.h"


/*
Tf = (9/5)Tc + 32
*/
double Temperature::celsius2fahrenheit(double celsius) {
    double answer = (9.0/5.0)*celsius + 32.0;
    
    return answer;
}


/*
Tc = (5/9)Tf - (5*32)/9
*/
double Temperature::fahrenheit2celsius(double fahrenheit) {
    double answer = (5.0/9.0)*fahrenheit - (5.0*32.0)/9.0;
    return answer;
}
