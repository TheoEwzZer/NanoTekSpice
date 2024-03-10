/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "FalseComponent.hpp"

nts::Tristate nts::FalseComponent::compute(const size_t pin)
{
    const size_t outputPin = 1;

    if (pin != outputPin) {
        const auto it = mPins.find(pin);
        if (it == mPins.end()) {
            return nts::Tristate::UNDEFINED;
        }
        return mPins[pin];
    }
    mPins[outputPin] = nts::Tristate::FALSE;
    return mPins[outputPin];
}
