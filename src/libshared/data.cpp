#include "data.h"

Data::Data()
    : Schema_Version(0)
    , call_sign(nullptr)
    , BINGO_Fuel(0)
    , BINGO_Date_Time(nullptr)
    , TOS_Hours(0.0)
    , Error_String(nullptr)
    , Warnings(nullptr)
{}

Data::~Data()
{
    delete call_sign;
    delete BINGO_Date_Time;
    delete Error_String;
    delete Warnings;
}