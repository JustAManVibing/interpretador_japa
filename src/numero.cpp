#include "numero.hpp"
#include <string>
std::unordered_map<std::string,int64_t> inteiros{

};

int numero( std::string linha){
    try{
        int i = std::stoi(linha);
        return i;
    }catch(...){
        int i = linha.find("Mamacita");
        if(i!=std::string::npos){
            std::string palavra=linha.substr(i+8);
            std::string retorno ="";
            for(char c : palavra){if(c!=' '){retorno+=c;}}
            return inteiros[retorno];
        }
    }
    return 0;
}