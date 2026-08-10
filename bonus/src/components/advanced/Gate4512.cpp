#include "Gate4512.hpp"
nts::Tristate nts::Gate4512::compute(const size_t pin) {
    Tristate a = getTristate(11), b = getTristate(12), c = getTristate(13);
    Tristate inhibit = getTristate(10), oe = getTristate(15);
    if (oe == TRUE) return (mPins[14] = UNDEFINED);
    if (inhibit == TRUE) return (mPins[14] = FALSE);
    if (a == UNDEFINED || b == UNDEFINED || c == UNDEFINED) return (mPins[14] = UNDEFINED);
    int sel = (a==TRUE?1:0) | ((b==TRUE?1:0)<<1) | ((c==TRUE?1:0)<<2);
    int inputs[] = {1, 2, 3, 4, 5, 6, 7, 9};
    mPins[14] = getTristate(inputs[sel]);
    return mPins[pin];
}
