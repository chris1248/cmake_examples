#include "MathStuff.h"

int Factorial(int val)
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