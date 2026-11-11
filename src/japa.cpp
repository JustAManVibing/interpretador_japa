#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include "operacoes.hpp"
#include "numero.hpp"





int main(int argc,char* argv[]){
    std::ifstream arquivo(argv[1]);
    std::string linha;
    while(std::getline(arquivo,linha)){
        int i = linha.find(' ');
        std::string palavra = linha.substr(0,i);
        linha.erase(0,i+1);
        func(linha,palavra);
    }
    
    return 0;
}