#include "Gate4040.hpp"
nts::Gate4040::Gate4040() : mCounter(0), mPrevClock(UNDEFINED) {
    for (int i=1; i<=15; i++) if (i!=8) mPins[i] = UNDEFINED;
}
void nts::Gate4040::updateOutputs() {
    int pins[] = {9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1};
    for (int i=0; i<12; i++) {
        mPins[pins[i]] = (mCounter & (1 << i)) ? TRUE : FALSE;
    }
}
nts::Tristate nts::Gate4040::compute(const size_t pin) {
    Tristate clock = getTristate(10);
    Tristate reset = getTristate(11);
    if (reset == TRUE) {
        mCounter = 0;
    } else if (reset == FALSE) {
        if (mPrevClock == TRUE && clock == FALSE) {
            mCounter = (mCounter + 1) & 0xFFF;
        }
    } else {
        mCounter = -1;
    }
    mPrevClock = clock;
    if (mCounter != -1) updateOutputs();
    else {
        int pins[] = {9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1};
        for (int i=0; i<12; i++) mPins[pins[i]] = UNDEFINED;
    }
    return mPins[pin];
}
