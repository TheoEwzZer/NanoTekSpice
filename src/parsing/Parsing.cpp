/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Parsing.hpp"

nts::Parsing::Parsing(nts::Circuit &circuit) : mCircuit(circuit)
{
}

void nts::Parsing::processLine(const string &line, smatch &match)
{
    if (mSection == CHIPSETS) {
        processChipsetsSection(line, match);
    } else if (mSection == LINKS) {
        if (!mHasChipsets) {
            throw nts::Error("No chipsets in the circuit");
        }
        processLinksSection(line, match);
    }
}

void nts::Parsing::processChipsetsSection(const string &line, smatch &match)
{
    const regex componentRegex("^[[:blank:]]*([a-zA-Z0-9]+)[[:blank:]]"
                          "+([a-zA-Z0-9_]+)(?:[[:blank:]]*#.*)?[[:blank:]]*$");
    const size_t COMPONENT_TYPE_GROUP = 1;
    const size_t COMPONENT_NAME_GROUP = 2;
    string type;
    string name;

    if (!regex_match(line, match, componentRegex)) {
        throw nts::Error("Invalid line: " + line);
    }
    type = match[COMPONENT_TYPE_GROUP];
    name = match[COMPONENT_NAME_GROUP];
    if (!isKnownComponentType(type)) {
        throw nts::Error("Unknown component type: " + type);
    }
    if (mComponentNames.contains(name)) {
        throw nts::Error("Duplicate component name: " + name);
    }
    mComponentNames.insert(name);
    mCircuit.createComponent(type, name);
}

void linkComponents(nts::IComponent &component1, const size_t pin1,
    nts::IComponent &component2, const size_t pin2) {
    nts::Link link1 = component1.getLink(pin1);
    nts::Link link2 = component2.getLink(pin2);

    link1.component.setLink(link1.pin, link2);
    link2.component.setLink(link2.pin, link1);
}

void nts::Parsing::processLinksSection(const string &line, smatch &match)
{
    const regex linkRegex("^[[:blank:]]*([a-zA-Z0-9_]+):([0-9]+)"
        "[[:blank:]]+([a-zA-Z0-9]+):([0-9]+)[[:blank:]]*(?:#.*)?[[:blank:]]*$");
    const size_t FIRST_COMPONENT_NAME_GROUP = 1;
    const size_t SECOND_COMPONENT_NAME_GROUP = 3;
    const size_t FIRST_COMPONENT_PIN_GROUP = 2;
    const size_t SECOND_COMPONENT_PIN_GROUP = 4;
    string componentName1;
    string componentName2;
    size_t pin1 = 0;
    size_t pin2 = 0;

    if (!regex_match(line, match, linkRegex)) {
        throw nts::Error("Invalid link: " + line);
    }
    componentName1 = match[FIRST_COMPONENT_NAME_GROUP];
    componentName2 = match[SECOND_COMPONENT_NAME_GROUP];
    pin1 = static_cast<size_t>(stoi(match[FIRST_COMPONENT_PIN_GROUP]));
    pin2 = static_cast<size_t>(stoi(match[SECOND_COMPONENT_PIN_GROUP]));
    if (!mComponentNames.contains(componentName1)) {
        throw nts::Error("Unknown component name '" + componentName1 + "'");
    }
    if (!mComponentNames.contains(componentName2)) {
        throw nts::Error("Unknown component name '" + componentName2 + "'");
    }
    nts::IComponent &component1 = mCircuit.getComponent(componentName1);
    nts::IComponent &component2 = mCircuit.getComponent(componentName2);
    ::linkComponents(component1, pin1, component2, pin2);
}

void nts::Parsing::loadCircuit(const string &filename)
{
    ifstream stream(filename);
    string line;
    mComponentNames = unordered_set<string>();
    mHasChipsets = false;
    smatch match;
    const regex commentRegex("^\\s*#.*$");
    const regex emptyLineRegex("^\\s*$");
    const regex chipsetsRegex("^\\.chipsets: *(?:#.*)?$");
    const regex linksRegex("^\\.links: *(?:#.*)?$");

    while (getline(stream, line)) {
        if ((!regex_match(line, commentRegex))
            && (!regex_match(line, emptyLineRegex))) {
            if (regex_match(line, chipsetsRegex)) {
                mSection = CHIPSETS;
                mHasChipsets = true;
            } else if (regex_match(line, linksRegex)) {
                mSection = LINKS;
            } else {
                processLine(line, match);
            }
        }
    }
    if ((!mHasChipsets) || (mCircuit.getComponents().empty())) {
        throw nts::Error("No chipsets in the circuit");
    }
}

bool nts::Parsing::isKnownComponentType(const string &type) const
{
    static const unordered_set<string> knownTypes {
        "input", "output", "true", "false", "clock", "and", "or", "xor",
        "not", "4001", "4011", "4030", "4069", "4071", "4081", "4008",
        "4013", "4017", "4040", "4094", "4512", "4514", "4801", "2716",
        "logger"
    };

    return knownTypes.contains(type);
}
