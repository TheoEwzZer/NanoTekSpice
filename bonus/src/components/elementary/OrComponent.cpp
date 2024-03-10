/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "OrComponent.hpp"

nts::Tristate nts::OrComponent::compute(const size_t pin)
{
    const size_t inputPin1 = 1;
    const size_t inputPin2 = 2;
    const size_t outputPin = 3;
    nts::Tristate link1 = nts::Tristate::UNDEFINED;
    nts::Tristate link2 = nts::Tristate::UNDEFINED;
    nts::Tristate result = nts::Tristate::UNDEFINED;

    if (pin != outputPin) {
        const auto it = mPins.find(pin);
        if (it == mPins.end()) {
            return nts::Tristate::UNDEFINED;
        }
        return mPins[pin];
    }
    link1 = getTristate(inputPin1);
    link2 = getTristate(inputPin2);
    if ((link1 == nts::Tristate::TRUE) || (link2 == nts::Tristate::TRUE)) {
        result = nts::Tristate::TRUE;
    }
    if ((link1 == nts::Tristate::FALSE) && (link2 == nts::Tristate::FALSE)) {
        result = nts::Tristate::FALSE;
    }
    mPins[inputPin1] = link1;
    mPins[inputPin2] = link2;
    mPins[outputPin] = result;
    return mPins[outputPin];
}
