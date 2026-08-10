#pragma once
#include "../AComponent.hpp"
namespace nts {
    class Gate4801 : public nts::AComponent {
        unsigned char memory[1024];
        Tristate mPrevWe;
    public:
        Gate4801();
        nts::Tristate compute(const size_t pin) override;
    };
}
