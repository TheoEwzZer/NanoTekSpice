#pragma once
#include "../AComponent.hpp"
#include <fstream>
namespace nts {
    class Gate2716 : public nts::AComponent {
        unsigned char memory[2048];
        bool loaded;
    public:
        Gate2716();
        nts::Tristate compute(const size_t pin) override;
    };
}
