#include "RoboRio.h"
#include <iostream>
using namespace std;

RoboRio::RoboRio()
{
    //ctor
}

int RoboRio::sendByte(int x)
{
    outgoingByte = x;
    return outgoingByte;
}
