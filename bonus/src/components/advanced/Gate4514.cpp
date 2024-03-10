#include "Gate4514.hpp"

nts::Gate4514::Gate4514() : mPreviousStrobe(nts::Tristate::TRUE)
{
    update();
}

void nts::Gate4514::update()
{
    static const unordered_map<int, size_t> counterToPin = {
        {0, 11}, {1, 9}, {2, 10}, {3, 8}, {4, 7}, {5, 6}, {6, 5}, {7, 4},
        {8, 18}, {9, 17}, {10, 20}, {11, 19}, {12, 14}, {13, 13}, {14, 16},
        {15, 15}
    };

    if ((mPins[23] == nts::Tristate::FALSE) && (mPins[1] == nts::Tristate::FALSE)) {
        for (const auto &[counter, pin] : counterToPin) {
            mPins[pin] = (mCounter == counter) ? nts::Tristate::TRUE : nts::Tristate::FALSE;
        }
    }
}

nts::Tristate nts::Gate4514::compute(const size_t pin)
{
    static const unordered_map<size_t, int> pinValues = {
        {2, 1}, {3, 2}, {21, 4}, {22, 8}
    };
    for (size_t i = 1; i <= 3; i++) {
        mPins[i] = getTristate(i);
    }
    for (size_t i = 21; i <= 23; i++) {
        mPins[i] = getTristate(i);
    }
    if ((mPins[1] == nts::Tristate::TRUE) || (mPins[1] == nts::Tristate::UNDEFINED)
    || (mPins[23] == nts::Tristate::UNDEFINED)) {
        mPreviousStrobe = mPins[23];
        return nts::Tristate::UNDEFINED;
    }
    if ((mPins[23] == nts::Tristate::TRUE) && (mPreviousStrobe == nts::Tristate::FALSE)) {
        mPreviousStrobe = mPins[23];
        update();
        return mPins[pin];
    }
    mCounter = 0;
    for (const auto &[currentPin, value] : pinValues) {
        if (mPins[currentPin] == nts::Tristate::TRUE) {
            mCounter += value;
        }
    }
    std::cout << static_cast<int>(mPreviousStrobe) << std::endl;
    update();
    return mPins[pin];
}
