#pragma once

class Data
{
public:
    Data();
    ~Data();
    int Schema_Version;
    wchar_t* call_sign;
    double   BINGO_Fuel;
    wchar_t* BINGO_Date_Time;
    double   TOS_Hours;
    wchar_t* Error_String;
    wchar_t* Warnings;
};