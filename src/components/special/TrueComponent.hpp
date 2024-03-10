/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
        public:
            Tristate compute(const size_t pin) override;
    };
}
