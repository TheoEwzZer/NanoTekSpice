/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Digital Electronics
*/

#pragma once

#include "../error/Error.hpp"
#include "IComponent.hpp"
#include "advanced/Gate4008.hpp"
#include "advanced/Gate4013.hpp"
#include "advanced/Gate4017.hpp"
#include "advanced/LoggerComponent.hpp"
#include "elementary/AndComponent.hpp"
#include "elementary/NotComponent.hpp"
#include "elementary/OrComponent.hpp"
#include "elementary/XorComponent.hpp"
#include "gates/Gate4001.hpp"
#include "gates/Gate4011.hpp"
#include "gates/Gate4030.hpp"
#include "gates/Gate4069.hpp"
#include "gates/Gate4071.hpp"
#include "gates/Gate4081.hpp"
#include "special/ClockComponent.hpp"
#include "special/FalseComponent.hpp"
#include "special/InputComponent.hpp"
#include "special/OutputComponent.hpp"
#include "special/TrueComponent.hpp"
#include <exception>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

using std::string;
using std::unique_ptr;
using std::function;
using std::unordered_map;
using std::make_unique;

namespace nts {
    class Factory {
        public:
            Factory();
            ~Factory() = default;

            template <typename Type>
            void registerComponent(const string &type)
            {
                mCreators[type] = [this]() { return make_unique<Type>(); };
            }

            unique_ptr<IComponent> createComponent(const string &type);

        private:
            using Creator = function<unique_ptr<nts::IComponent>()>;
            unordered_map<string, Creator> mCreators;
    };
}
