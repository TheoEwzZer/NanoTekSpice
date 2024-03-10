/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/parsing/Parsing.hpp"
#include "../src/circuits/Circuit.hpp"
#include "../src/simulation/Simulation.hpp"

/* Create Component */

Test(test_createComponent, test_createComponent_success)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);

    circuit.createComponent("true", "true");

    nts::IComponent *const comp = circuit.mComponents["true"].get();
    auto const *const compTrue = dynamic_cast<nts::TrueComponent *>(comp);
    cr_assert(compTrue != nullptr, "Failed to create component 'true'");
}

Test(test_createComponent, test_createComponent_failure)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);

    try {
        circuit.createComponent("invalid", "invalid");
        cr_assert(false, "Expected exception not thrown");
    } catch (const std::exception&) {
        cr_assert(true, "Exception thrown as expected");
    }
}

/* And Gate */

Test(test_andGate, test_andGate_true_true)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("true", "true1");
    circuit.createComponent("true", "true2");
    circuit.createComponent("and", "and");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("true1"), 1,
        circuit.getComponent("and"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("true2"), 1,
        circuit.getComponent("and"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("and"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::TRUE, "Failed to simulate circuit");
}

Test(test_andGate, test_andGate_true_false)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("true", "true");
    circuit.createComponent("false", "false");
    circuit.createComponent("and", "and");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("true"), 1,
        circuit.getComponent("and"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("false"), 1,
        circuit.getComponent("and"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("and"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::FALSE, "Failed to simulate circuit");
}

Test(test_andGate, test_andGate_false_false)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("false", "false1");
    circuit.createComponent("false", "false2");
    circuit.createComponent("and", "and");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("false1"), 1,
        circuit.getComponent("and"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("false2"), 1,
        circuit.getComponent("and"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("and"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::FALSE, "Failed to simulate circuit");
}

Test(test_andGate, test_andGate_true_undefined)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("true", "true");
    circuit.createComponent("input", "input");
    circuit.createComponent("and", "and");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("true"), 1,
        circuit.getComponent("and"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("input"), 1,
        circuit.getComponent("and"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("and"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::UNDEFINED, "Failed to simulate circuit");
}

Test(test_andGate, test_andGate_false_undefined)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("false", "false");
    circuit.createComponent("input", "input");
    circuit.createComponent("and", "and");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("false"), 1,
        circuit.getComponent("and"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("input"), 1,
        circuit.getComponent("and"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("and"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::FALSE, "Failed to simulate circuit");
}

Test(test_andGate, test_andGate_undefined_undefined)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("input", "undefined1");
    circuit.createComponent("input", "undefined2");
    circuit.createComponent("and", "and");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("undefined1"), 1,
        circuit.getComponent("and"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("undefined2"), 1,
        circuit.getComponent("and"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("and"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::UNDEFINED, "Failed to simulate circuit");
}

/* Or Gate */

Test(test_orGate, test_orGate_true_true)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("true", "true1");
    circuit.createComponent("true", "true2");
    circuit.createComponent("or", "or");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("true1"), 1,
        circuit.getComponent("or"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("true2"), 1,
        circuit.getComponent("or"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("or"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::TRUE, "Failed to simulate circuit");
}

Test(test_orGate, test_orGate_true_false)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("true", "true");
    circuit.createComponent("false", "false");
    circuit.createComponent("or", "or");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("true"), 1,
        circuit.getComponent("or"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("false"), 1,
        circuit.getComponent("or"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("or"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::TRUE, "Failed to simulate circuit");
}

Test(test_orGate, test_orGate_false_false)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("false", "false1");
    circuit.createComponent("false", "false2");
    circuit.createComponent("or", "or");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("false1"), 1,
        circuit.getComponent("or"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("false2"), 1,
        circuit.getComponent("or"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("or"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::FALSE, "Failed to simulate circuit");
}

Test(test_orGate, test_orGate_true_undefined)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("true", "true");
    circuit.createComponent("input", "input");
    circuit.createComponent("or", "or");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("true"), 1,
        circuit.getComponent("or"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("input"), 1,
        circuit.getComponent("or"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("or"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::TRUE, "Failed to simulate circuit");
}

Test(test_orGate, test_orGate_false_undefined)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("false", "false");
    circuit.createComponent("input", "input");
    circuit.createComponent("or", "or");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("false"), 1,
        circuit.getComponent("or"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("input"), 1,
        circuit.getComponent("or"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("or"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::UNDEFINED, "Failed to simulate circuit");
}

Test(test_orGate, test_orGate_undefined_undefined)
{
    const nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);

    circuit.createComponent("input", "undefined1");
    circuit.createComponent("input", "undefined2");
    circuit.createComponent("or", "or");
    circuit.createComponent("output", "output");

    parsing.linkComponents(
        circuit.getComponent("undefined1"), 1,
        circuit.getComponent("or"), 1
    );
    parsing.linkComponents(
        circuit.getComponent("undefined2"), 1,
        circuit.getComponent("or"), 2
    );
    parsing.linkComponents(
        circuit.getComponent("or"), 3,
        circuit.getComponent("output"), 1
    );

    circuit.simulate(1);

    auto const *const compOutput = dynamic_cast<nts::OutputComponent *>(circuit.mComponents["output"].get());
    cr_assert(compOutput != nullptr, "Failed to simulate circuit");
    cr_assert_eq(compOutput->getTristate(1), nts::Tristate::UNDEFINED, "Failed to simulate circuit");
}
