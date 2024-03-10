/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include <iostream>
#include "parsing/Parsing.hpp"
#include "circuits/Circuit.hpp"
#include "simulation/Simulation.hpp"

const int EXPECTED_ARG_COUNT = 2;
const int ERROR_CODE = 84;

using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char **argv)
{
    nts::Factory factory;
    nts::Circuit circuit(factory);
    nts::Parsing parsing(circuit);
    nts::Simulation simulation(circuit);

    if (argc != ::EXPECTED_ARG_COUNT) {
        cerr << "Usage: " << argv[0] << " [file.nts]" << endl;
        return ::ERROR_CODE;
    }
    try {
        parsing.loadCircuit(argv[1]);
    } catch (const nts::Error &error) {
        cerr << error.what() << endl;
        return ::ERROR_CODE;
    }
    simulation.run();
    return 0;
}
