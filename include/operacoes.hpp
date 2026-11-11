#include <string>
#include <unordered_map>
#include <cstdint>
#include <iostream>
#include "numero.hpp"
#include "palavra.hpp"
#pragma once

enum tipo{
    inteiro,string
};
bool acha (char a, std::string st);
std::string operacoes(std::string linha,tipo tipodeoperacao);
void func(std::string linha,std::string palavra);
bool acha (char a, std::string st);
