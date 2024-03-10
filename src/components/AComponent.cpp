/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "AComponent.hpp"
#include "../error/Error.hpp"
using std::size_t;

nts::Tristate nts::AComponent::compute(const size_t pin)
{
    if (!mLinks.contains(pin)) {
        return UNDEFINED;
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
    if (!mLinks.contains(pin)) {
        mLinks.try_emplace(pin, link);
        return;
    }
    throw nts::Error("Pin already linked");
}

nts::Tristate nts::AComponent::getTristate(const size_t pin) const
{
    if (!mLinks.contains(pin)) {
        throw nts::Error("Pin not found: " + pin);
    }
    nts::IComponent &linkedComponent = mLinks.at(pin).component;
    return linkedComponent.compute(mLinks.at(pin).pin);
}
