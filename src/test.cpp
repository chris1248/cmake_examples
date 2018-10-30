// test.cpp

#include <iostream>

#include "lib/MathStuff.h"

using namespace std;

int main(void) {

     cout << "Compute Factorial" << endl;
     cout << "Enter a number: ";
     unsigned int val;
     cin >> val;
     cout << "You entered the value: " << val << endl;
     unsigned int factorial = Factorial(val);

     cout << "Factorial: " << factorial << endl;

     return(0);

}
