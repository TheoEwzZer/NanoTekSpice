#include "Gate4514.hpp"

nts::Gate4514::Gate4514()
{
    mCounter = 0;
    for (int i=1; i<=24; i++) {
        mPins[i] = UNDEFINED;
    }
}

void nts::Gate4514::update()
{
    static const unordered_map<int, size_t> counterToPin = {
        {0, 11}, {1, 9}, {2, 10}, {3, 8}, {4, 7}, {5, 6}, {6, 5}, {7, 4},
        {8, 18}, {9, 17}, {10, 20}, {11, 19}, {12, 14}, {13, 13}, {14, 16},
        {15, 15}
    };

    if (mPins[23] == TRUE) {
        // Inhibit is high, all outputs low
        for (const auto &[counter, p] : counterToPin) {
            mPins[p] = FALSE;
        }
    } else if (mPins[23] == FALSE) {
        // Inhibit is low, decode
        for (const auto &[counter, p] : counterToPin) {
            mPins[p] = (mCounter == counter) ? TRUE : FALSE;
        }
    } else {
        // Inhibit is undefined, outputs undefined
        for (const auto &[counter, p] : counterToPin) {
            mPins[p] = UNDEFINED;
        }
    }
}

nts::Tristate nts::Gate4514::compute(const size_t pin)
{
    mPins[1] = getTristate(1); // Strobe
    mPins[23] = getTristate(23); // Inhibit
    mPins[2] = getTristate(2); // A
    mPins[3] = getTristate(3); // B
    mPins[21] = getTristate(21); // C
    mPins[22] = getTristate(22); // D

    if (mPins[1] == TRUE) {
        // Transparent mode: update counter
        if (mPins[2] == UNDEFINED || mPins[3] == UNDEFINED || mPins[21] == UNDEFINED || mPins[22] == UNDEFINED) {
            mCounter = -1; // Undefined state
        } else {
            mCounter = (mPins[2] == TRUE ? 1 : 0) |
                       ((mPins[3] == TRUE ? 1 : 0) << 1) |
                       ((mPins[21] == TRUE ? 1 : 0) << 2) |
                       ((mPins[22] == TRUE ? 1 : 0) << 3);
        }
    }
    
    if (mCounter == -1) {
        static const unordered_map<int, size_t> counterToPin = {
            {0, 11}, {1, 9}, {2, 10}, {3, 8}, {4, 7}, {5, 6}, {6, 5}, {7, 4},
            {8, 18}, {9, 17}, {10, 20}, {11, 19}, {12, 14}, {13, 13}, {14, 16},
            {15, 15}
        };
        for (const auto &[c, p] : counterToPin) {
            mPins[p] = UNDEFINED;
        }
    } else {
        update();
    }
    
    return mPins[pin];
}
