/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "AComponent.hpp"
#include "../error/Error.hpp"

nts::Tristate nts::AComponent::compute(const size_t pin)
{
    if (mLinks.find(pin) == mLinks.end()) {
        return nts::Tristate::UNDEFINED;
    }
    nts::Link link = mLinks.at(pin);
    mPins[pin] = link.component.compute(link.pin);
    return mPins[pin];
}

nts::Link nts::AComponent::getLink(const size_t pin)
{
    return Link(pin, *this);
}

void nts::AComponent::simulate(const size_t tick)
{
    (void)tick;
}

void nts::AComponent::setLink(const size_t pin, Link link)
{
    if (mLinks.find(pin) == mLinks.end()) {
        mLinks.try_emplace(pin, link);
        return;
    }
    throw nts::Error("Pin already linked");
}

nts::Tristate nts::AComponent::getTristate(const size_t pin) const
{
    if (mLinks.find(pin) == mLinks.end()) {
        throw nts::Error("Pin not found: " + pin);
    }
    nts::IComponent &linkedComponent = mLinks.at(pin).component;
    return linkedComponent.compute(mLinks.at(pin).pin);
}
