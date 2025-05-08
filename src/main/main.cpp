// main.cpp

#include <iostream>

#include <staticlib.h>
#include <sharedlib.h>

#include "utils.h"

using namespace std;

int main(void) {
     std::string machine_name = getMachineHostname();
     cout << "Running on machine: " << machine_name << endl;

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

#ifdef DEBUGGING
     cout << "Debug mode is enabled." << endl;
     cout << "Run the Shared Libarary Test" << endl;
     TestSharedMethod();
#else
     cout << "Release mode is enabled." << endl;
     cout << "Show Multiple Doubles again" << endl;
     double a2 = 4.0;
     double b2 = 5.0;
     double result2 = MultiplyDoubles(a2, b2);
     cout << "MultiplyDoubles: " << result2 << endl;
#endif

     return(0);

}
