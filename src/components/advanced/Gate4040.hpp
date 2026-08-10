#pragma once
#include "../AComponent.hpp"
namespace nts {
    class Gate4040 : public nts::AComponent {
        int mCounter;
        Tristate mPrevClock;
    public:
        Gate4040();
        nts::Tristate compute(const size_t pin) override;
        void updateOutputs();
    };
}
