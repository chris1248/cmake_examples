#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "sharedlib.h"

extern "C" {
  void TestSharedMethod() {
    printf("This is called from a library...\n");
  }

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

    double Multiply(float x, float y)
    {
      return x * y;
    }

    void PrintString(wchar_t* msg)
    {
      printf("Received string: %s\n", msg);
    }

    char* GetString()
    {
      char* msg = new char[256];
      strcpy(msg, "Zrom Linux native with love");
      return msg;
    }
}