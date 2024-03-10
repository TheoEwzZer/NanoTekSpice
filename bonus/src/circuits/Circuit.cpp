/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Circuit.hpp"

nts::Circuit::Circuit(const Factory &factory) : mFactory(factory)
{
}

nts::Link nts::Circuit::getLink(const size_t pin)
{
    if (mPins.find(pin) == mPins.end()) {
        throw nts::Error("Pin not found: " + pin);
    }
    return mLinks.at(pin);
}

nts::Tristate nts::Circuit::compute(const size_t pin)
{
    (void)pin;
    return nts::Tristate::UNDEFINED;
}

void nts::Circuit::simulate(const size_t tick)
{
    for (const auto &[name, component] : mComponents) {
        component->simulate(tick);
    }
}

void nts::Circuit::addComponent(const string &name,
    unique_ptr<IComponent> component)
{
    mComponents[name] = move(component);
}

nts::IComponent &nts::Circuit::getComponent(const string &name)
{
    if (mComponents.find(name) == mComponents.end()) {
        throw nts::Error("Unknown component name '" + name + "'");
    }
    return *mComponents[name];
}

void nts::Circuit::createComponent(const string &type, const string &name)
{
    addComponent(name, mFactory.createComponent(type));

    if ((type == "input") || (type == "clock")) {
        mInputs.push_back(name);
    } else if (type == "output") {
        mOutputs.push_back(name);
    } else if (type == "logger") {
        mLoggers.push_back(name);
    }
}

void nts::Circuit::change(const string &input, const nts::Tristate state)
{
    if (mComponents.find(input) == mComponents.end()) {
        nts::IComponent *const comp = mComponents[input].get();
        auto *const componentInput = dynamic_cast<nts::InputComponent *>(comp);
        auto *const componentClock = dynamic_cast<nts::ClockComponent *>(comp);

        if (componentInput != nullptr) {
            componentInput->changeState(state);
        } else if (componentClock != nullptr) {
            componentClock->changeState(state);
        }
    }
}

const unordered_map<string, unique_ptr<nts::IComponent>>&
    nts::Circuit::getComponents() const
{
    return mComponents;
}

const vector<string> &nts::Circuit::getInputs() const
{
    return mInputs;
}

const vector<string> &nts::Circuit::getOutputs() const
{
    return mOutputs;
}

const vector<string> &nts::Circuit::getLoggers() const
{
    return mLoggers;
}
