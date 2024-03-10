/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/
#pragma once

#include "../AComponent.hpp"

namespace nts {
    class ClockComponent : public AComponent {
        public:
            ClockComponent();

            Tristate compute(const size_t pin) override;
            void simulate(const size_t tick) override;
            void changeState(const Tristate state);
        private:
            Tristate mState = Tristate::UNDEFINED;
            bool mNeedChange = false;
    };
}
