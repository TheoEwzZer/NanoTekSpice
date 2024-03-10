/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include "../components/AComponent.hpp"
#include "../components/Factory.hpp"
#include "../components/special/InputComponent.hpp"
#include "../components/special/ClockComponent.hpp"
#include "../error/Error.hpp"
#include <unordered_map>
#include <vector>
#include <string>

using std::unordered_map;
using std::string;
using std::unique_ptr;
using std::move;
using std::vector;
using std::string;

namespace nts {
    class Circuit : public AComponent {
        public:
            explicit Circuit(const Factory &factory);
            ~Circuit() override = default;

            Tristate compute(const size_t pin) override;

            void simulate(const size_t tick) override;

            void addComponent(const string &name,
                unique_ptr<IComponent> component);
            IComponent &getComponent(const string &name);
            void createComponent(const string &type, const string &name);
            void change(const string &input, const nts::Tristate state);
            Link getLink(const size_t pin) override;

            [[nodiscard]] const unordered_map<string, unique_ptr<IComponent>> &
                getComponents() const;
            [[nodiscard]] const vector<string> &getInputs() const;
            [[nodiscard]] const vector<string> &getOutputs() const;
            [[nodiscard]] const vector<string> &getLoggers() const;
            unordered_map<string, unique_ptr<IComponent>> mComponents;
        private:
            vector<string> mInputs;
            vector<string> mOutputs;
            vector<string> mLoggers;
            Factory mFactory;
    };
}
