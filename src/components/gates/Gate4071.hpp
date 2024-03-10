/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include "../AComponent.hpp"
#include "../elementary/AndComponent.hpp"

using nts::Tristate;

namespace nts {
    class Gate4071 : public AComponent {
        public:
            Tristate compute(const size_t pin) override;
            Tristate getOr(const Tristate link1, const Tristate link2) const;
    };
}
