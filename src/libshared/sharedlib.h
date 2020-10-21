#pragma once

#include "shared_exports.h"
extern "C" {
    SHARED_EXPORTS void TestSharedMethod();
    SHARED_EXPORTS unsigned long Factorial(unsigned long);
    SHARED_EXPORTS double Multiply(float,float);
    SHARED_EXPORTS void PrintString(wchar_t*);
    SHARED_EXPORTS char* GetString();
}