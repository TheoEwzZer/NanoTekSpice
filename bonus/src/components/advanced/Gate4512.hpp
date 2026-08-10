#pragma once
#include "../AComponent.hpp"
namespace nts {
    class Gate4512 : public nts::AComponent {
    public:
        Gate4512() = default;
        nts::Tristate compute(const size_t pin) override;
    };
}
