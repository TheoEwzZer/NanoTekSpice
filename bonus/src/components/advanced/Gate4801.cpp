#include "Gate4801.hpp"
#include <cstring>
nts::Gate4801::Gate4801() : mPrevWe(UNDEFINED) { 
    std::memset(memory, 0, 1024);
    for (int i=1; i<=24; i++) mPins[i] = UNDEFINED;
}
nts::Tristate nts::Gate4801::compute(const size_t pin) {
    Tristate ce = getTristate(18);
    Tristate oe = getTristate(20);
    Tristate we = getTristate(21);
    
    int addressPins[] = {8, 7, 6, 5, 4, 3, 2, 1, 23, 22}; // A0 to A9
    int dataPins[] = {9, 10, 11, 13, 14, 15, 16, 17}; // DQ0 to DQ7
    
    int address = 0;
    bool addressValid = true;
    for (int i=0; i<10; i++) {
        Tristate a = getTristate(addressPins[i]);
        if (a == UNDEFINED) addressValid = false;
        else if (a == TRUE) address |= (1 << i);
    }
    
    // Write cycle
    if (ce == FALSE && we == FALSE) {
        if (addressValid) {
            unsigned char data = 0;
            bool dataValid = true;
            for (int i=0; i<8; i++) {
                Tristate d = getTristate(dataPins[i]);
                if (d == UNDEFINED) dataValid = false;
                else if (d == TRUE) data |= (1 << i);
            }
            if (dataValid) {
                memory[address] = data;
            }
        }
    }
    mPrevWe = we;
    
    // Read cycle
    if (ce == FALSE && we == TRUE && oe == FALSE) {
        if (addressValid) {
            unsigned char data = memory[address];
            for (int i=0; i<8; i++) {
                mPins[dataPins[i]] = (data & (1 << i)) ? TRUE : FALSE;
            }
        } else {
            for (int i=0; i<8; i++) mPins[dataPins[i]] = UNDEFINED;
        }
    } else {
        // High Z
        for (int i=0; i<8; i++) mPins[dataPins[i]] = UNDEFINED;
    }
    
    return mPins[pin];
}
