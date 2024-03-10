/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include <cstddef>
#include <iostream>

using std::size_t;

namespace nts {
    enum class Tristate {
        UNDEFINED = -1,
        TRUE = 1,
        FALSE = 0
    };

    class Link;

    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual void simulate(const size_t tick) = 0;
            virtual Tristate compute(const size_t pin) = 0;
            virtual void setLink(size_t pin, Link link) = 0;
            virtual Link getLink(const size_t pin) = 0;
    };

    class Link {
        public:
            Link(const size_t pin, IComponent &comp) : pin(pin), component(comp)
            {
            }
            ~Link() = default;
            size_t pin;
            IComponent &component;
    };
}
