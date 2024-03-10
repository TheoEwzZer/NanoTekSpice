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
    class Gate4017 : public AComponent {
        public:
            Gate4017();
            Tristate compute(const size_t pin) override;
            void update();
            void reset();
            Tristate getPin(const nts::Tristate &pin13,
                const nts::Tristate &pin14, const size_t pin);

        private:
            int mCounter = -1;
    };
}
