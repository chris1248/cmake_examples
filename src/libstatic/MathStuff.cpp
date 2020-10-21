#include "MathStuff.h"

extern "C" {
    unsigned long Factorial(unsigned long val)
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
}