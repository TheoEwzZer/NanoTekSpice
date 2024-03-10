/*
** EPITEcH PROJEcT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Gate4008.hpp"

nts::Tristate nts::Gate4008::compute(const size_t pin)
{
    for (size_t i = 1; i <= 9 ; i++) {
        if (i != 8) {
            mPins[i] = getTristate(i);
        }
    }
    mPins[15] = getTristate(15);
    const nts::Tristate a1 = mPins[6];
    const nts::Tristate b1 = mPins[7];
    const nts::Tristate a2 = mPins[5];
    const nts::Tristate b2 = mPins[4];
    const nts::Tristate a3 = mPins[3];
    const nts::Tristate b3 = mPins[2];
    const nts::Tristate a4 = mPins[1];
    const nts::Tristate b4 = mPins[15];
    const nts::Tristate cin = mPins[9];
    nts::Tristate &s1 = mPins[10];
    nts::Tristate &s2 = mPins[11];
    nts::Tristate &s3 = mPins[12];
    nts::Tristate &s4 = mPins[13];
    nts::Tristate &cout = mPins[14];
    s1 = xorGate(xorGate(a1, b1), cin);
    cout = orGate(andGate(xorGate(a1, b1), cin), andGate(a1, b1));
    s2 = xorGate(xorGate(a2, b2), cout);
    cout = orGate(andGate(xorGate(a2, b2), cout), andGate(a2, b2));
    s3 = xorGate(xorGate(a3, b3), cout);
    cout = orGate(andGate(xorGate(a3, b3), cout), andGate(a3, b3));
    s4 = xorGate(xorGate(a4, b4), cout);
    cout = orGate(andGate(xorGate(a4, b4), cout), andGate(a4, b4));
    return mPins[pin];
}

nts::Tristate nts::Gate4008::xorGate(const nts::Tristate &link1,
    const nts::Tristate &link2) const
{
    nts::Tristate result = nts::Tristate::UNDEFINED;

    if ((link1 == nts::Tristate::TRUE) && (link2 == nts::Tristate::TRUE)) {
        result = nts::Tristate::FALSE;
    }
    if ((link1 == nts::Tristate::FALSE) && (link2 == nts::Tristate::FALSE)) {
        result = nts::Tristate::FALSE;
    }
    if ((link1 == nts::Tristate::TRUE) && (link2 == nts::Tristate::FALSE)) {
        result = nts::Tristate::TRUE;
    }
    if ((link1 == nts::Tristate::FALSE) && (link2 == nts::Tristate::TRUE)) {
        result = nts::Tristate::TRUE;
    }
    return result;
}

nts::Tristate nts::Gate4008::andGate(const nts::Tristate &link1,
    const nts::Tristate &link2) const
{
    nts::Tristate result = nts::Tristate::UNDEFINED;

    if ((link1 == nts::Tristate::TRUE) && (link2 == nts::Tristate::TRUE)) {
        result = nts::Tristate::TRUE;
    }
    if ((link1 == nts::Tristate::FALSE) || (link2 == nts::Tristate::FALSE)) {
        result = nts::Tristate::FALSE;
    }
    return result;
}

nts::Tristate nts::Gate4008::orGate(const nts::Tristate &link1,
    const nts::Tristate &link2) const
{
    nts::Tristate result = nts::Tristate::UNDEFINED;

    if ((link1 == nts::Tristate::TRUE) || (link2 == nts::Tristate::TRUE)) {
        result = nts::Tristate::TRUE;
    }
    if ((link1 == nts::Tristate::FALSE) && (link2 == nts::Tristate::FALSE)) {
        result = nts::Tristate::FALSE;
    }
    return result;
}
