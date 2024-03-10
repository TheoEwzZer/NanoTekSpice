/*
** EPITECH PROJECT, 2024
** nano
** File description:
** nano
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
        public:
            Tristate compute(const size_t pin) override;
    };
}
