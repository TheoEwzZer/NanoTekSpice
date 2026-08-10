#pragma once
#include "../AComponent.hpp"
namespace nts {
    class Gate4094 : public nts::AComponent {
        int mShiftReg;
        Tristate mPrevClock;
    public:
        Gate4094();
        nts::Tristate compute(const size_t pin) override;
    };
}
