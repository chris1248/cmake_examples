// test.cpp

#include <iostream>

#include <MathStuff.h>
#include <sharedlib.h>

using namespace std;

int main(void) {

     cout << "Compute Factorial" << endl;
     cout << "Enter a number: ";
     unsigned int val;
     cin >> val;
     cout << "You entered the value: " << val << endl;
     unsigned int factorial = Factorial(val);
     cout << "Factorial: " << factorial << endl;

     TestSharedMethod();

     return(0);

}
