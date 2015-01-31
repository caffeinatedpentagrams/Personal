#include "RioDuino.h"
#include <iostream>
using namespace std;

RioDuino::RioDuino()
{
    //ctor
}

void RioDuino::updateBufferSubscript()
{//updates buffer subscript so when each byte is checked and determined to not be the terminator, it is updated correctly
    if (bufferSubscript == 0)
        bufferSubscript = 1;
    else
        bufferSubscript = 0;
}

void RioDuino::wipeBuffer()
{
    for(int x=0; x<2; x++){
        process[x] = buffer[x];
        //cout << "This is the buffer val: " << buffer[x] << "\n";
        //cout << "This is the process val: " << process[x] << "\n"; //happening correctly
        buffer[x] = 0;
        //cout << "The buffer value has been reset. It reads: " << buffer[x] << endl;
    }
}

void RioDuino::processBytes()
{
    int copy = process[0]; //copies first byte for 3 split, splits are 4 + 3 + reserve (1)
    //cout << "Upon initial copy, copy is: " << copy << "\n";
    storeValues[0] = copy & 0b00000111; //shifts one right, anding to only read last three values, between 0 and 7
    //cout << "First value stored is: " << storeValues[0] << endl;
    //three split can now be read, three split is section, immediately stored in storeValues
    copy = process[0]; //recopies for the 4 split to read effect tag
    storeValues[1] = (copy<<1)>>4; //shifts one right to delete reserve bit, then four right to read value
    copy = process[1]; //now copying second byte for color interp
    storeValues[2] = copy; //can be taken as-is to get full color range
}

void RioDuino::outputStoreValues()
{
    for (int z=0; z < 3; z++)
    {
        cout << "In storeValues[" << z << "] the value is " << storeValues[z] << "." << endl;
    }
}

void RioDuino::receiveByte(int incomingByte)
{//not sure if terminology (bitmask) used correctly
    //termination check
    //no safety net because of low risk, if something goes wrong in real test then we may write one
    if (incomingByte == 255){ //checks to see if termination true AND if buffer full
        wipeBuffer();//moves things into process array, and wipes array
        //now onto processing the the bits
        processBytes(); //puts things into readable array of values, 0-1-2, section, effect, color
        outputStoreValues();
    }

    else {
        buffer[bufferSubscript] = incomingByte;
        updateBufferSubscript(); //this part should work
    }
}

void RioDuino::updateLEDs(int section, int pattern, int color)
{
    cout << "Pattern " << pattern << " sent to section " << " with the color code " << color << endl;
}
