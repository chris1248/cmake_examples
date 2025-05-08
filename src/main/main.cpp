// main.cpp

#include <iostream>

#include <staticlib.h>
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
     double pi = GetPi();
     cout << "Pi: " << pi << endl;

     double a = 2.0;
     double b = 3.0;
     double result = MultiplyDoubles(a, b);
     cout << "MultiplyDoubles: " << result << endl;

     cout << "Platform Architecture: " << getPlatformArchitecture() << endl;

     cout << "Shared Library Test" << endl;
     TestSharedMethod();

     return(0);

}
