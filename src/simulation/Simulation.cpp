/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "Simulation.hpp"

static bool gotSignal = false;

nts::Simulation::Simulation(nts::Circuit &circuit) : mCircuit(circuit)
{
}

void nts::Simulation::change(const string &input, const string &value)
{
    nts::Tristate state = UNDEFINED;
    const unordered_map<string, unique_ptr<IComponent>> &components =
        mCircuit.getComponents();

    if (components.contains(input)) {
        if (value == "0") {
            state = FALSE;
        } else if (value == "1") {
            state = TRUE;
        }
        mCircuit.change(input, state);
        return;
    }
    cerr << "Unknown component type: " << input << endl;
}

void nts::Simulation::run()
{
    const regex pattern("^(\\w+)=(0|1|U)$");
    smatch match;
    const int expectedMatchSize = 3;

    while (getInput()) {
        if (mInput == "exit") {
            return;
        } else if (mInput == "simulate") {
            simulate();
        } else if (mInput == "display") {
            display();
        } else if (mInput == "loop") {
            loop();
        } else if (regex_search(mInput, match, pattern)
            && (match.size() == expectedMatchSize)) {
            const string input = match.str(1);
            const string value = match.str(2);
            change(input, value);
        } else {
            cerr << "Unknown command: " << mInput << endl;
        }
    }
}

void nts::Simulation::display()
{
    nts::Tristate inputVal = UNDEFINED;
    nts::Tristate outputVal = UNDEFINED;
    vector<string> inputNames = mCircuit.getInputs();
    std::ranges::sort(inputNames);

    cout << "tick: " << mTick << endl;
    cout << "input(s):" << endl;
    for (const auto &inputName: inputNames) {
        inputVal = mCircuit.getComponent(inputName).compute(1);
        cout << "  " << inputName << ": ";
        if (inputVal == UNDEFINED) {
            cout << "U";
        } else {
            cout << static_cast<int>(inputVal);
        }
        cout << endl;
    }
    cout << "output(s):" << endl;
    vector<string> outputNames = mCircuit.getOutputs();
    std::ranges::sort(outputNames);
    for (const auto &outputName: outputNames) {
        outputVal = mCircuit.getComponent(outputName).compute(1);
        cout << "  " << outputName << ": ";
        if (outputVal == UNDEFINED) {
            cout << "U";
        } else {
            cout << static_cast<int>(outputVal);
        }
        cout << endl;
    }
}

void nts::Simulation::simulate()
{
    mTick++;
    for (const auto &inputName: mCircuit.getInputs()) {
        mCircuit.getComponent(inputName).simulate(mTick);
    }
    for (const auto &loggerName: mCircuit.getLoggers()) {
        mCircuit.getComponent(loggerName).simulate(mTick);
    }
    for (const auto &outputName: mCircuit.getOutputs()) {
        mCircuit.getComponent(outputName).compute(1);
    }
}

void handleSignal(const int mySignal)
{
    if (mySignal == SIGINT) {
        ::gotSignal = true;
    }
}

void nts::Simulation::loop()
{
    ::signal(SIGINT, ::handleSignal);
    while (!::gotSignal) {
        simulate();
        display();
    }
    ::signal(SIGINT, SIG_DFL);
}

bool nts::Simulation::getInput()
{
    if (cin.eof()) {
        return false;
    }
    cout << "> ";
    getline(cin, mInput);
    if (cin.eof()) {
        return false;
    }
    return true;
}
