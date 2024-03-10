/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Gate4069.hpp"

Tristate nts::Gate4069::getNot(const Tristate link) const
{
    Tristate result = nts::Tristate::UNDEFINED;

    if (link == nts::Tristate::TRUE) {
        result = nts::Tristate::FALSE;
    }
    if (link == nts::Tristate::FALSE) {
        result = nts::Tristate::TRUE;
    }
    return result;
}

Tristate nts::Gate4069::compute(const size_t pin)
{
    const size_t inputPin1 = 1;
    const size_t outputPin1 = 2;
    const size_t inputPin2 = 3;
    const size_t outputPin2 = 4;
    const size_t inputPin3 = 5;
    const size_t outputPin3 = 6;
    const size_t outputPin4 = 8;
    const size_t inputPin4 = 9;
    const size_t outputPin5 = 10;
    const size_t inputPin5 = 11;
    const size_t outputPin6 = 12;
    const size_t inputPin6 = 13;
    Tristate link = nts::Tristate::UNDEFINED;
    Tristate result = nts::Tristate::UNDEFINED;

    if (pin == outputPin1) {
        link = getTristate(inputPin1);
        mPins[inputPin1] = link;
        mPins[outputPin1] = getNot(link);
        result = mPins[outputPin1];
    } else if (pin == outputPin2) {
        link = getTristate(inputPin2);
        mPins[inputPin2] = link;
        mPins[outputPin2] = getNot(link);
        result = mPins[outputPin2];
    } else if (pin == outputPin3) {
        link = getTristate(inputPin3);
        mPins[inputPin3] = link;
        mPins[outputPin3] = getNot(link);
        result = mPins[outputPin3];
    } else if (pin == outputPin4) {
        link = getTristate(inputPin4);
        mPins[inputPin4] = link;
        mPins[outputPin4] = getNot(link);
        result = mPins[outputPin4];
    } else if (pin == outputPin5) {
        link = getTristate(inputPin5);
        mPins[inputPin5] = link;
        mPins[outputPin5] = getNot(link);
        result = mPins[outputPin5];
    } else if (pin == outputPin6) {
        link = getTristate(inputPin6);
        mPins[inputPin6] = link;
        mPins[outputPin6] = getNot(link);
        result = mPins[outputPin6];
    } else {
        return AComponent::compute(pin);
    }
    return result;
}
