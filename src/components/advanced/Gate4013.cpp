/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Gate4013.hpp"

nts::Gate4013::Gate4013()
{
    mPins[1] = UNDEFINED;
    mPins[2] = UNDEFINED;
    mPins[12] = UNDEFINED;
    mPins[13] = UNDEFINED;
}

nts::Tristate nts::Gate4013::get1()
{
    const nts::Tristate clk = mPins[3];
    const nts::Tristate reset = mPins[4];
    const nts::Tristate data = mPins[5];
    const nts::Tristate set = mPins[6];

    if ((set == TRUE) && (reset != UNDEFINED)) {
        return TRUE;
    }
    if ((set == FALSE) && (reset == TRUE)) {
        return FALSE;
    }
    if ((set == FALSE) && (reset == FALSE)) {
        if ((clk == TRUE) && (data != UNDEFINED)) {
            return data;
        }
        if (clk == FALSE) {
            return mPins[1];
        }
    }
    return UNDEFINED;
}

nts::Tristate nts::Gate4013::get2()
{
    const nts::Tristate clk = mPins[3];
    const nts::Tristate reset = mPins[4];
    const nts::Tristate data = mPins[5];
    const nts::Tristate set = mPins[6];

    if ((set == TRUE) && (reset == TRUE)) {
        return TRUE;
    }
    if ((set == TRUE) && (reset != UNDEFINED)) {
        return FALSE;
    }
    if ((set == FALSE) && (reset == TRUE)) {
        return TRUE;
    }
    if ((set == FALSE) && (reset == FALSE)) {
        if ((clk == TRUE) && (data != UNDEFINED)) {
            return data == TRUE ? FALSE : TRUE;
        }
        if (clk == FALSE) {
            return mPins[2];
        }
    }
    return UNDEFINED;
}

nts::Tristate nts::Gate4013::get13()
{
    const nts::Tristate clk = mPins[11];
    const nts::Tristate reset = mPins[10];
    const nts::Tristate data = mPins[9];
    const nts::Tristate set = mPins[8];

    if ((set == TRUE) && (reset != UNDEFINED)) {
        return TRUE;
    }
    if ((set == FALSE) && (reset == TRUE)) {
        return FALSE;
    }
    if ((set == FALSE) && (reset == FALSE)) {
        if ((clk == TRUE) && (data != UNDEFINED)) {
            return data;
        }
        if (clk == FALSE) {
            return mPins[13];
        }
    }
    return UNDEFINED;
}

nts::Tristate nts::Gate4013::get12()
{
    const nts::Tristate clk = mPins[11];
    const nts::Tristate reset = mPins[10];
    const nts::Tristate data = mPins[9];
    const nts::Tristate set = mPins[8];

    if ((set == TRUE) && (reset == TRUE)) {
        return TRUE;
    }
    if ((set == TRUE) && (reset != UNDEFINED)) {
        return FALSE;
    }
    if ((set == FALSE) && (reset == TRUE)) {
        return TRUE;
    }
    if ((set == FALSE) && (reset == FALSE)) {
        if ((clk == TRUE) && (data != UNDEFINED)) {
            return data == TRUE ? FALSE : TRUE;
        }
        if (clk == FALSE) {
            return mPins[12];
        }
    }
    return UNDEFINED;
}

nts::Tristate nts::Gate4013::compute(const size_t pin)
{
    for (size_t i = 3; i <= 11; i++) {
        if (i != 7) {
            mPins[i] = getTristate(i);
        }
    }
    if (pin == 1) {
        mPins[1] = get1();
        return mPins[1];
    }
    if (pin == 2) {
        mPins[2] = get2();
        return mPins[2];
    }
    if (pin == 12) {
        mPins[12] = get12();
        return mPins[12];
    }
    if (pin == 13) {
        mPins[13] = get13();
        return mPins[13];
    }
    throw nts::Error(format("Pin {} is not computable.", pin));
}
