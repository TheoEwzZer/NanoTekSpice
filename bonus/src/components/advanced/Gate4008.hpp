/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include "../AComponent.hpp"
#include <array>
#include <unordered_map>

#pragma once

using std::array;
using std::unordered_map;

namespace nts {
    class Gate4008 : public AComponent {
        public:
            Gate4008() = default;
            Tristate compute(const size_t pin) override;
            nts::Tristate xorGate(const nts::Tristate &link1,
                const nts::Tristate &link2) const;
            nts::Tristate andGate(const nts::Tristate &link1,
                const nts::Tristate &link2) const;
            nts::Tristate orGate(const nts::Tristate &link1,
                const nts::Tristate &link2) const;

        private:
            int mCounter = -1;
    };
}
