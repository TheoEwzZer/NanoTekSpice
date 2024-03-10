/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "TrueComponent.hpp"

nts::Tristate nts::TrueComponent::compute(const size_t pin)
{
    const size_t outputPin = 1;

    if (pin != outputPin) {
        const auto it = mPins.find(pin);
        if (it == mPins.end()) {
            return UNDEFINED;
        }
        return mPins[pin];
    }
    mPins[outputPin] = TRUE;
    return mPins[outputPin];
}
