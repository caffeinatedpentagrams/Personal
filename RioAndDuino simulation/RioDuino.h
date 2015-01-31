#ifndef RIODUINO_H
#define RIODUINO_H


class RioDuino
{ //first byte is split, second is 7 bits, third is full byte but termination code
    public:
        RioDuino();
        void wipeBuffer(); //moves buffer into process[2] and wipes buffer
        void updateBufferSubscript();
        void receiveByte(int incomingByte); //last bit of incoming byte determines if terminator byte
        void processBytes(); //optimized too
        void outputStoreValues(); //outputs array of stored values for debug
        //beginning of interp functions
        void updateLEDs(int, int, int); //takes section, pattern, and color
    protected:
    private:
        int bufferSubscript = 0;
        int buffer[2] = {};
        int process[2] = {};
        int bitmaskTermination;
        int storeValues[3] = {}; //goes section, effect, color
};

#endif // RIODUINO_H
