/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Factory.hpp"
#include "advanced/Gate4514.hpp"

nts::Factory::Factory()
{
    registerComponent<nts::AndComponent>("and");
    registerComponent<nts::ClockComponent>("clock");
    registerComponent<nts::FalseComponent>("false");
    registerComponent<nts::Gate4001>("4001");
    registerComponent<nts::Gate4008>("4008");
    registerComponent<nts::Gate4514>("4514");
    registerComponent<nts::Gate4011>("4011");
    registerComponent<nts::Gate4013>("4013");
    registerComponent<nts::Gate4017>("4017");
    registerComponent<nts::Gate4030>("4030");
    registerComponent<nts::Gate4069>("4069");
    registerComponent<nts::Gate4071>("4071");
    registerComponent<nts::Gate4081>("4081");
    registerComponent<nts::InputComponent>("input");
    registerComponent<nts::LoggerComponent>("logger");
    registerComponent<nts::NotComponent>("not");
    registerComponent<nts::OrComponent>("or");
    registerComponent<nts::OutputComponent>("output");
    registerComponent<nts::TrueComponent>("true");
    registerComponent<nts::XorComponent>("xor");
}

unique_ptr<nts::IComponent> nts::Factory::createComponent(const string &type)
{
    if (mCreators.find(type) != mCreators.end()) {
        return mCreators[type]();
    }
    throw nts::Error("Unknown component type '" + type + "'");
}
