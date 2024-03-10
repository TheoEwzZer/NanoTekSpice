/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Gate4017.hpp"

nts::Gate4017::Gate4017()
{
    update();
}

void nts::Gate4017::update()
{
    static const unordered_map<int, size_t> counterToPin = {
        {5, 1}, {1, 2}, {0, 3}, {2, 4}, {6, 5},
        {7, 6}, {3, 7}, {8, 9}, {4, 10}, {9, 11}
    };

    for (const auto& [counter, pin] : counterToPin) {
        mPins[pin] = (mCounter == counter) ? TRUE : FALSE;
    }
    mPins[12] = mCounter < 5 ? TRUE : FALSE;
}

void nts::Gate4017::reset()
{
    mCounter = 0;
    for (auto &[key, value] : mPins) {
        if ((key == 3) || (key == 12)) {
            value = TRUE;
        } else {
            value = FALSE;
        }
    }
}

nts::Tristate nts::Gate4017::getPin(const nts::Tristate &pin13,
    const nts::Tristate &pin14, const size_t pin)
{
    mPins[13] = pin13;
    mPins[14] = pin14;
    return mPins[pin];
}

nts::Tristate nts::Gate4017::compute(const size_t pin)
{
    const nts::Tristate pin13 = getTristate(13);
    const nts::Tristate pin14 = getTristate(14);
    const nts::Tristate pin15 = getTristate(15);
    bool condition1 = false;
    bool condition2 = false;

    if (pin15 == TRUE) {
        reset();
        return getPin(pin13, pin14, pin);
    }
    if (mCounter == -1) {
        return getPin(pin13, pin14, pin);
    }
    if ((mPins[13] == TRUE) && (pin13 == FALSE) && (mPins[14] == TRUE)) {
        condition1 = true;
    }
    if ((mPins[14] == FALSE) && (pin14 == TRUE) && (mPins[13] != TRUE)) {
        condition2 = true;
    }
    if (condition1 || condition2) {
        if (mCounter < 9) {
            mCounter++;
        } else {
            mCounter = 0;
        }
    }
    update();
    return getPin(pin13, pin14, pin);
}
