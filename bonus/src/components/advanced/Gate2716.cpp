#include "Gate2716.hpp"
#include <cstring>
#include <iostream>
nts::Gate2716::Gate2716() : loaded(false) {
    std::memset(memory, 0, 2048);
    for (int i=1; i<=24; i++) mPins[i] = UNDEFINED;
    
    std::ifstream file("./rom.bin", std::ios::binary);
    if (file) {
        file.read(reinterpret_cast<char*>(memory), 2048);
        loaded = true;
    }
}
nts::Tristate nts::Gate2716::compute(const size_t pin) {
    Tristate ce = getTristate(18);
    Tristate oe = getTristate(20);
    
    int addressPins[] = {8, 7, 6, 5, 4, 3, 2, 1, 23, 22, 19}; // A0 to A10
    int dataPins[] = {9, 10, 11, 13, 14, 15, 16, 17}; // Q0 to Q7
    
    if (ce == FALSE && oe == FALSE && loaded) {
        int address = 0;
        bool addressValid = true;
        for (int i=0; i<11; i++) {
            Tristate a = getTristate(addressPins[i]);
            if (a == UNDEFINED) addressValid = false;
            else if (a == TRUE) address |= (1 << i);
        }
        
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
