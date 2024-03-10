/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/


#include "Error.hpp"

nts::Error::Error(const string &text) : mText(text)
{
}

const char *nts::Error::what() const noexcept
{
    return mText.c_str();
}
