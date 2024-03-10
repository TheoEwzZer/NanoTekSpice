#pragma once

#include "../AComponent.hpp"
#include <array>
using std::array;

namespace nts {
    class Gate4514 : public AComponent {
    public:
        Gate4514();
        Tristate compute(std::size_t pin) override;
        void update();

    private:
        int mCounter = -1;
        Tristate mPreviousStrobe = nts::Tristate::UNDEFINED;
    };
}
