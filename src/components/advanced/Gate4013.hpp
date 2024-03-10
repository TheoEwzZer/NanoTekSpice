/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include "../AComponent.hpp"
#include "../../error/Error.hpp"
#include <format>

using std::format;

namespace nts {
    class Gate4013 : public nts::AComponent {
        public:
            Gate4013();
            nts::Tristate compute(const size_t pin) override;
            nts::Tristate get1();
            nts::Tristate get2();
            nts::Tristate get12();
            nts::Tristate get13();
    };
}
