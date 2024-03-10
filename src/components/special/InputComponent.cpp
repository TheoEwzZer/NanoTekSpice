/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "InputComponent.hpp"

nts::InputComponent::InputComponent()
{
    mPins[1] = UNDEFINED;
}

nts::Tristate nts::InputComponent::compute(const size_t pin)
{
    return mPins[pin];
}

void nts::InputComponent::simulate(const size_t tick)
{
    (void)tick;

    if (mNeedChange) {
        mPins[1] = mState;
        mNeedChange = false;
    }
}

void nts::InputComponent::changeState(const nts::Tristate state)
{
    mState = state;
    mNeedChange = true;
}
