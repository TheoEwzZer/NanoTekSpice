/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#include "LoggerComponent.hpp"

void nts::LoggerComponent::simulate(const size_t tick)
{
    (void)tick;
    char byte = 0;
    const size_t pinCount = 8;
    const int clockPin = 9;
    const int inhibitPin = 10;
    const string filePath = "./log.bin";
    const int bitValue = 2;

    for (size_t i = 1; i <= inhibitPin; i++) {
        mPins[i] = getTristate(i);
    }
    if ((mPins[clockPin] == nts::Tristate::UNDEFINED) || (mPins[inhibitPin] != nts::Tristate::FALSE)) {
        return;
    }
    for (size_t i = 1; i <= pinCount; i++) {
        if (mPins[i] == nts::Tristate::TRUE) {
            byte += static_cast<char>(pow(bitValue, i - 1));
        } else if (mPins[i] == nts::Tristate::UNDEFINED) {
            return;
        }
    }
    mValue.clear();
    mValue += byte;
    if (mPins[clockPin] == nts::Tristate::TRUE) {
        if (!mHasPrint) {
            ofstream file(filePath, std::ios_base::app);
            file.write(mValue.c_str(), 1);
            file.close();
            mHasPrint = true;
        }
    } else {
        mHasPrint = false;
    }
}
