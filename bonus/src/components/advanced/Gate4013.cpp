/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Gate4013.hpp"

nts::Gate4013::Gate4013() : mPrevClock1(UNDEFINED), mPrevClock2(UNDEFINED)
{
    mPins[1] = UNDEFINED;
    mPins[2] = UNDEFINED;
    mPins[12] = UNDEFINED;
    mPins[13] = UNDEFINED;
}

nts::Tristate nts::Gate4013::get1() { return mPins[1]; }
nts::Tristate nts::Gate4013::get2() { return mPins[2]; }
nts::Tristate nts::Gate4013::get12() { return mPins[12]; }
nts::Tristate nts::Gate4013::get13() { return mPins[13]; }

nts::Tristate nts::Gate4013::compute(const size_t pin)
{
    for (size_t i = 3; i <= 11; i++) {
        if (i != 7) {
            mPins[i] = getTristate(i);
        }
    }

    // Flip-Flop 1 (Pins 1, 2, 3=Clk, 4=R, 5=D, 6=S)
    const nts::Tristate clk1 = mPins[3];
    const nts::Tristate rst1 = mPins[4];
    const nts::Tristate d1 = mPins[5];
    const nts::Tristate set1 = mPins[6];

    if (set1 == TRUE && rst1 == TRUE) {
        mPins[1] = TRUE;
        mPins[2] = TRUE;
    } else if (set1 == TRUE && rst1 != UNDEFINED) {
        mPins[1] = TRUE;
        mPins[2] = FALSE;
    } else if (set1 == FALSE && rst1 == TRUE) {
        mPins[1] = FALSE;
        mPins[2] = TRUE;
    } else if (set1 == FALSE && rst1 == FALSE) {
        if (mPrevClock1 == FALSE && clk1 == TRUE) {
            if (d1 != UNDEFINED) {
                mPins[1] = d1;
                mPins[2] = (d1 == TRUE) ? FALSE : TRUE;
            } else {
                mPins[1] = UNDEFINED;
                mPins[2] = UNDEFINED;
            }
        }
    } else {
        mPins[1] = UNDEFINED;
        mPins[2] = UNDEFINED;
    }
    mPrevClock1 = clk1;

    // Flip-Flop 2 (Pins 13, 12, 11=Clk, 10=R, 9=D, 8=S)
    const nts::Tristate clk2 = mPins[11];
    const nts::Tristate rst2 = mPins[10];
    const nts::Tristate d2 = mPins[9];
    const nts::Tristate set2 = mPins[8];

    if (set2 == TRUE && rst2 == TRUE) {
        mPins[13] = TRUE;
        mPins[12] = TRUE;
    } else if (set2 == TRUE && rst2 != UNDEFINED) {
        mPins[13] = TRUE;
        mPins[12] = FALSE;
    } else if (set2 == FALSE && rst2 == TRUE) {
        mPins[13] = FALSE;
        mPins[12] = TRUE;
    } else if (set2 == FALSE && rst2 == FALSE) {
        if (mPrevClock2 == FALSE && clk2 == TRUE) {
            if (d2 != UNDEFINED) {
                mPins[13] = d2;
                mPins[12] = (d2 == TRUE) ? FALSE : TRUE;
            } else {
                mPins[13] = UNDEFINED;
                mPins[12] = UNDEFINED;
            }
        }
    } else {
        mPins[13] = UNDEFINED;
        mPins[12] = UNDEFINED;
    }
    mPrevClock2 = clk2;

    if (pin == 1 || pin == 2 || pin == 12 || pin == 13) {
        return mPins[pin];
    }
    throw nts::Error(format("Pin {} is not computable.", pin));
}
