/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Gate4013.hpp"

nts::Gate4013::Gate4013()
{
    mPins[1] = nts::Tristate::UNDEFINED;
    mPins[2] = nts::Tristate::UNDEFINED;
    mPins[12] = nts::Tristate::UNDEFINED;
    mPins[13] = nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Gate4013::get1()
{
    const nts::Tristate clk = mPins[3];
    const nts::Tristate reset = mPins[4];
    const nts::Tristate data = mPins[5];
    const nts::Tristate set = mPins[6];

    if ((set == nts::Tristate::TRUE) && (reset != nts::Tristate::UNDEFINED)) {
        return nts::Tristate::TRUE;
    }
    if ((set == nts::Tristate::FALSE) && (reset == nts::Tristate::TRUE)) {
        return nts::Tristate::FALSE;
    }
    if ((set == nts::Tristate::FALSE) && (reset == nts::Tristate::FALSE)) {
        if ((clk == nts::Tristate::TRUE) && (data != nts::Tristate::UNDEFINED)) {
            return data;
        }
        if (clk == nts::Tristate::FALSE) {
            return mPins[1];
        }
    }
    return nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Gate4013::get2()
{
    const nts::Tristate clk = mPins[3];
    const nts::Tristate reset = mPins[4];
    const nts::Tristate data = mPins[5];
    const nts::Tristate set = mPins[6];

    if ((set == nts::Tristate::TRUE) && (reset == nts::Tristate::TRUE)) {
        return nts::Tristate::TRUE;
    }
    if ((set == nts::Tristate::TRUE) && (reset != nts::Tristate::UNDEFINED)) {
        return nts::Tristate::FALSE;
    }
    if ((set == nts::Tristate::FALSE) && (reset == nts::Tristate::TRUE)) {
        return nts::Tristate::TRUE;
    }
    if ((set == nts::Tristate::FALSE) && (reset == nts::Tristate::FALSE)) {
        if ((clk == nts::Tristate::TRUE) && (data != nts::Tristate::UNDEFINED)) {
            return data == nts::Tristate::TRUE ? nts::Tristate::FALSE : nts::Tristate::TRUE;
        }
        if (clk == nts::Tristate::FALSE) {
            return mPins[2];
        }
    }
    return nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Gate4013::get13()
{
    const nts::Tristate clk = mPins[11];
    const nts::Tristate reset = mPins[10];
    const nts::Tristate data = mPins[9];
    const nts::Tristate set = mPins[8];

    if ((set == nts::Tristate::TRUE) && (reset != nts::Tristate::UNDEFINED)) {
        return nts::Tristate::TRUE;
    }
    if ((set == nts::Tristate::FALSE) && (reset == nts::Tristate::TRUE)) {
        return nts::Tristate::FALSE;
    }
    if ((set == nts::Tristate::FALSE) && (reset == nts::Tristate::FALSE)) {
        if ((clk == nts::Tristate::TRUE) && (data != nts::Tristate::UNDEFINED)) {
            return data;
        }
        if (clk == nts::Tristate::FALSE) {
            return mPins[13];
        }
    }
    return nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Gate4013::get12()
{
    const nts::Tristate clk = mPins[11];
    const nts::Tristate reset = mPins[10];
    const nts::Tristate data = mPins[9];
    const nts::Tristate set = mPins[8];

    if ((set == nts::Tristate::TRUE) && (reset == nts::Tristate::TRUE)) {
        return nts::Tristate::TRUE;
    }
    if ((set == nts::Tristate::TRUE) && (reset != nts::Tristate::UNDEFINED)) {
        return nts::Tristate::FALSE;
    }
    if ((set == nts::Tristate::FALSE) && (reset == nts::Tristate::TRUE)) {
        return nts::Tristate::TRUE;
    }
    if ((set == nts::Tristate::FALSE) && (reset == nts::Tristate::FALSE)) {
        if ((clk == nts::Tristate::TRUE) && (data != nts::Tristate::UNDEFINED)) {
            return data == nts::Tristate::TRUE ? nts::Tristate::FALSE : nts::Tristate::TRUE;
        }
        if (clk == nts::Tristate::FALSE) {
            return mPins[12];
        }
    }
    return nts::Tristate::UNDEFINED;
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
    throw nts::Error("Invalid pin");
}
