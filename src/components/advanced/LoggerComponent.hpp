/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include "../AComponent.hpp"
#include <cmath>
#include <string>
#include <fstream>

using std::pow;
using std::string;
using std::ofstream;

namespace nts {
    class LoggerComponent : public AComponent {
        public:
            LoggerComponent() = default;

            void simulate(const size_t tick) override;

        private:
            string mValue = "";
            bool mHasPrint = false;
    };
}
