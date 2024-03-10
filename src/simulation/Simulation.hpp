/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include "../circuits/Circuit.hpp"
#include <iostream>
#include <string>
#include <regex>
#include <string>
#include <algorithm>
#include <ranges>
#include <csignal>

using std::getline;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::regex;
using std::smatch;
using std::string;
using enum nts::Tristate;

namespace nts {
    class Simulation {
        public:
            explicit Simulation(nts::Circuit &circuit);
            ~Simulation() = default;

            void display();
            void loop();
            void run();
            void simulate();
            bool getInput();
            void change(const string &input, const string &value);
        private:
            nts::Circuit &mCircuit;
            string mInput;
            size_t mTick = 0;
    };
}
