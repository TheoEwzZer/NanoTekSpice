/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include "../circuits/Circuit.hpp"
#include "../error/Error.hpp"
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::regex;
using std::regex_match;
using std::smatch;
using std::string;
using std::unordered_set;

namespace nts {
    class Parsing {
        public:
            enum Section {
                CHIPSETS,
                LINKS,
                NONE
            };

            explicit Parsing(nts::Circuit &circuit);
            ~Parsing() = default;

            void loadCircuit(const string &filename);
            [[nodiscard]] bool isKnownComponentType(const string &type) const;
            void processLine(const string &line, smatch &match);
            void processChipsetsSection(const string &line, smatch &match);
            void processLinksSection(const string &line, smatch &match);
            void linkComponents(nts::IComponent &component1, const size_t pin1,
                nts::IComponent &component2, const size_t pin2);
        private:
            nts::Circuit &mCircuit;
            Section mSection = NONE;
            bool mHasChipsets = false;
            unordered_set<string> mComponentNames;
    };
}
