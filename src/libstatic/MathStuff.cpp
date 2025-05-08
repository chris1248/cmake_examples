#include "MathStuff.h"

unsigned  Factorial(unsigned  val)
{
    if (val == 1)
    {
        return 1;
    }
    else
    {
        return Factorial(val - 1) * val;
    }
}

double GetPi()
{
    return 3.141592653589793;
}

double MultiplyDoubles(double a, double b)
{
    return a * b;
}