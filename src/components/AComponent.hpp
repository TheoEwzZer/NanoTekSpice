/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include "IComponent.hpp"
#include <unordered_map>
#include <iostream>
#include <memory>

using std::unordered_map;
using enum nts::Tristate;
using std::size_t;

namespace nts {
    class AComponent : public IComponent {
        public:
            AComponent() = default;
            ~AComponent() override = default;

            Tristate compute(const size_t pin) override;

            void simulate(const size_t tick) override;

            void setLink(const size_t pin, Link link) override;

            Tristate getTristate(const size_t pin) const;

            Link getLink(const size_t pin) override;

        protected:
            unordered_map<size_t, Link> mLinks;
            unordered_map<size_t, Tristate> mPins;
    };
}
