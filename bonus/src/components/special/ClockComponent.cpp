/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent()
{
    mPins[1] = nts::Tristate::UNDEFINED;
}

nts::Tristate nts::ClockComponent::compute(const size_t pin)
{
    return mPins[pin];
}

void nts::ClockComponent::simulate(const size_t tick)
{
    (void)tick;

    if (mNeedChange) {
        mPins[1] = mState;
        mNeedChange = false;
        return;
    }
    if (mPins[1] == nts::Tristate::TRUE) {
        mPins[1] = nts::Tristate::FALSE;
    } else if (mPins[1] == nts::Tristate::FALSE) {
        mPins[1] = nts::Tristate::TRUE;
    }
}

void nts::ClockComponent::changeState(const nts::Tristate state)
{
    mState = state;
    mNeedChange = true;
}
