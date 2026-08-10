#include "Gate4094.hpp"
nts::Gate4094::Gate4094() : mShiftReg(0), mPrevClock(UNDEFINED) {}
nts::Tristate nts::Gate4094::compute(const size_t pin) {
    Tristate strobe = getTristate(1);
    Tristate data = getTristate(2);
    Tristate clock = getTristate(3);
    Tristate oe = getTristate(15);
    if (mPrevClock == FALSE && clock == TRUE) {
        if (strobe == TRUE && data != UNDEFINED) {
            mShiftReg = (mShiftReg >> 1) | ((data == TRUE ? 1 : 0) << 7);
        }
    }
    mPrevClock = clock;
    int pins[] = {4, 5, 6, 7, 14, 13, 12, 11};
    if (oe == TRUE) {
        for (int i=0; i<8; i++) mPins[pins[i]] = (mShiftReg & (1<<i)) ? TRUE : FALSE;
    } else {
        for (int i=0; i<8; i++) mPins[pins[i]] = UNDEFINED;
    }
    mPins[9] = (mShiftReg & 128) ? TRUE : FALSE;
    mPins[10] = (mShiftReg & 128) ? TRUE : FALSE; // Simplified
    return mPins[pin];
}
