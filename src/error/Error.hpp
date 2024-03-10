/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include <stdexcept>
#include <string>

using std::exception;
using std::string;

namespace nts {
    class Error : public exception {
        public:
            explicit Error(const string &text);

            const char *what() const noexcept override;
        private:
            string mText;
    };
}
