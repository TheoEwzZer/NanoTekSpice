/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Gate4030.hpp"

Tristate nts::Gate4030::getXor(const Tristate link1, const Tristate link2) const
{
    Tristate result = UNDEFINED;

    if ((link1 == TRUE) && (link2 == TRUE)) {
        result = FALSE;
    }
    if ((link1 == FALSE) && (link2 == FALSE)) {
        result = FALSE;
    }
    if ((link1 == TRUE) && (link2 == FALSE)) {
        result = TRUE;
    }
    if ((link1 == FALSE) && (link2 == TRUE)) {
        result = TRUE;
    }
    return result;
}

Tristate nts::Gate4030::compute(const size_t pin)
{
    const size_t inputPin1 = 1;
    const size_t inputPin2 = 2;
    const size_t outputPin1 = 3;
    const size_t outputPin2 = 4;
    const size_t inputPin3 = 5;
    const size_t inputPin4 = 6;
    const size_t inputPin5 = 8;
    const size_t inputPin6 = 9;
    const size_t outputPin3 = 10;
    const size_t outputPin4 = 11;
    const size_t inputPin7 = 12;
    const size_t inputPin8 = 13;
    Tristate link1 = Tristate::UNDEFINED;
    Tristate link2 = Tristate::UNDEFINED;
    Tristate result = Tristate::UNDEFINED;

    if (pin == outputPin1) {
        link1 = getTristate(inputPin1);
        link2 = getTristate(inputPin2);
        mPins[inputPin1] = link1;
        mPins[inputPin2] = link2;
        mPins[outputPin1] = getXor(link1, link2);
        result = mPins[outputPin1];
    } else if (pin == outputPin2) {
        link1 = getTristate(inputPin3);
        link2 = getTristate(inputPin4);
        mPins[inputPin3] = link1;
        mPins[inputPin4] = link2;
        mPins[outputPin2] = getXor(link1, link2);
        result = mPins[outputPin2];
    } else if (pin == outputPin3) {
        link1 = getTristate(inputPin5);
        link2 = getTristate(inputPin6);
        mPins[inputPin5] = link1;
        mPins[inputPin6] = link2;
        mPins[outputPin3] = getXor(link1, link2);
        result = mPins[outputPin3];
    } else if (pin == outputPin4) {
        link1 = getTristate(inputPin7);
        link2 = getTristate(inputPin8);
        mPins[inputPin7] = link1;
        mPins[inputPin8] = link2;
        mPins[outputPin4] = getXor(link1, link2);
        result = mPins[outputPin4];
    } else {
        result = nts::AComponent::compute(pin);
    }
    return result;
}
