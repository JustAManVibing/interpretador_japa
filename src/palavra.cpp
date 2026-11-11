#include "palavra.hpp"

std::unordered_map<std::string,std::string> strings{

};
std::string palavra(std::string linha){
    int i = linha.find("Mamacita ");
    if(i!=std::string::npos){
        std::string palavr=linha.substr(i+8);
        std::string retorno ="";
        bool continua = false;
        for(char c : palavr){if(c!=' '){retorno+=c;continua=true;}else if(continua){retorno+=c;}}
        return  std::to_string(inteiros[retorno]);
    }else{
        i=linha.find("Paralelepípedo ");
        
        if(i!=std::string::npos){
            std::string palavr=linha.substr(i+15);
            std::string retorno ="";
            for(char c : palavr){if(c!=' '){retorno+=c;}}
            
            return strings[retorno];
        }else{
            std::string retorno ="";
            bool continua = false;
            for(char c : linha){if(c!=' '){retorno+=c;continua=true;}else if(continua){retorno+=c;}}
            return retorno;
        }
    }
}