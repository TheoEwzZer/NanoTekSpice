/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Gate4001.hpp"

Tristate nts::Gate4001::getNor(const Tristate link1, const Tristate link2) const
{
    Tristate result = nts::Tristate::UNDEFINED;

    if ((link1 == nts::Tristate::TRUE) || (link2 == nts::Tristate::TRUE)) {
        result = nts::Tristate::FALSE;
    }
    if ((link1 == nts::Tristate::FALSE) && (link2 == nts::Tristate::FALSE)) {
        result = nts::Tristate::TRUE;
    }
    return result;
}

Tristate nts::Gate4001::compute(const size_t pin)
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
    Tristate link1 = nts::Tristate::UNDEFINED;
    Tristate link2 = nts::Tristate::UNDEFINED;
    Tristate result = nts::Tristate::UNDEFINED;

    if (pin == outputPin1) {
        link1 = getTristate(inputPin1);
        link2 = getTristate(inputPin2);
        mPins[inputPin1] = link1;
        mPins[inputPin2] = link2;
        mPins[outputPin1] = getNor(link1, link2);
        result = mPins[outputPin1];
    } else if (pin == outputPin2) {
        link1 = getTristate(inputPin3);
        link2 = getTristate(inputPin4);
        mPins[inputPin3] = link1;
        mPins[inputPin4] = link2;
        mPins[outputPin2] = getNor(link1, link2);
        result = mPins[outputPin2];
    } else if (pin == outputPin3) {
        link1 = getTristate(inputPin5);
        link2 = getTristate(inputPin6);
        mPins[inputPin5] = link1;
        mPins[inputPin6] = link2;
        mPins[outputPin3] = getNor(link1, link2);
        result = mPins[outputPin3];
    } else if (pin == outputPin4) {
        link1 = getTristate(inputPin7);
        link2 = getTristate(inputPin8);
        mPins[inputPin7] = link1;
        mPins[inputPin8] = link2;
        mPins[outputPin4] = getNor(link1, link2);
        result = mPins[outputPin4];
    } else {
        result = nts::AComponent::compute(pin);
    }
    return result;
}
