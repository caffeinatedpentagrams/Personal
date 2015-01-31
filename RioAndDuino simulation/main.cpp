#include <iostream>
#include "RioDuino.h"
#include "RoboRio.h"
using namespace std;

/*remember
left shifting is equivalent to multiplying by a power of 2
right shift is integer division by 2
a bitmask is "masking" part of the bitset so you only see certain parts that you want to work with
*/

int main()
{
    RoboRio rio;
    RioDuino duino; //working
    duino.receiveByte(rio.sendByte(0b00001001)); //sends effect 1 to section 1, no termination bit
    duino.receiveByte(rio.sendByte(0b00000111)); //sends color code of 7 no term
    duino.receiveByte(rio.sendByte(0b11111111)); //termination byte, should always be 255
    return 0;
}
