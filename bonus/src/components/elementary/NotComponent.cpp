/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "NotComponent.hpp"

nts::Tristate nts::NotComponent::compute(const size_t pin)
{
    const size_t inputPin = 1;
    const size_t outputPin = 2;
    nts::Tristate link = nts::Tristate::UNDEFINED;
    nts::Tristate result = nts::Tristate::UNDEFINED;

    if (pin != outputPin) {
        return nts::AComponent::compute(pin);
    }
    link = getTristate(inputPin);
    if (link == nts::Tristate::TRUE) {
        result = nts::Tristate::FALSE;
    }
    if (link == nts::Tristate::FALSE) {
        result = nts::Tristate::TRUE;
    }
    mPins[inputPin] = link;
    mPins[outputPin] = result;
    return mPins[outputPin];
}
