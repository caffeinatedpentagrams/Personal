#ifndef ROBORIO_H
#define ROBORIO_H


class RoboRio
{
    public:
        RoboRio();
        int sendByte(int);//sends proto byte
    protected:
    private:
        int outgoingByte; //split into 4, 3, and 1
};

#endif // ROBORIO_H
