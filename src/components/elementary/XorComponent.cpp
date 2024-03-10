/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "XorComponent.hpp"

nts::Tristate nts::XorComponent::compute(const size_t pin)
{
    const size_t inputPin1 = 1;
    const size_t inputPin2 = 2;
    const size_t outputPin = 3;
    nts::Tristate link1 = UNDEFINED;
    nts::Tristate link2 = UNDEFINED;
    nts::Tristate result = UNDEFINED;

    if (pin != outputPin) {
        const auto it = mPins.find(pin);
        if (it == mPins.end()) {
            return UNDEFINED;
        }
        return mPins[pin];
    }
    link1 = getTristate(inputPin1);
    link2 = getTristate(inputPin2);
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
    mPins[inputPin1] = link1;
    mPins[inputPin2] = link2;
    mPins[outputPin] = result;
    return mPins[outputPin];
}
