#include <iostream>
#include <fstream>
#include <unordered_map>
#include <ranges>
#include <cstdint>
#include <string>
std::unordered_map<std::string,int64_t> inteiros{

};
std::unordered_map<std::string,std::string> strings{

};
enum tipo{
    inteiro,string
};
bool acha (char a, std::string st){
    for(char i:st){
        if(i==a){
            return true;
        }
    }
    return false;
}
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

std::string operacoes(std::string linha,tipo tipodeoperacao=inteiro){
    if(tipodeoperacao==inteiro){
        if(acha('+',linha)){
            int i = linha.find('+');
            int Primeiro= numero(linha.substr(0,i));
            int Segundo= numero(linha.substr(i+1,linha.length()-1));
            return std::to_string((Primeiro+Segundo));
        } else if(acha('-',linha)){
            int i = linha.find('-');
            int Primeiro= numero(linha.substr(0,i));
            int Segundo= numero(linha.substr(i+1,linha.length()-1));
            return std::to_string(Primeiro-Segundo);
        } else if(acha('*',linha)){
            int i = linha.find('*');
            int Primeiro= numero(linha.substr(0,i));
            int Segundo= numero(linha.substr(i+1,linha.length()-1));
            return std::to_string(Primeiro*Segundo);
        }else if(acha('/',linha)){
            int i = linha.find('/');
            int Primeiro= numero(linha.substr(0,i));
            int Segundo= numero(linha.substr(i+1,linha.length()-1));
            return std::to_string(Primeiro / Segundo);
        }else{
            return std::to_string(numero(linha));
        }
    }else{
        
        if(acha('+',linha)){
            int i = linha.find('+');
            std::string Primeiro= palavra(linha.substr(0,i));
            std::string Segundo= palavra(linha.substr(i+1,linha.length()-1));
            
            return Primeiro+" "+Segundo;
        }else{
            return palavra(linha);
        }
    }
}

void func(std::string linha,std::string palavra){
    if(palavra=="Mamacita"){
        int i = linha.find('=');
        std::string palavra = linha.substr(0,i-1);
        linha.erase(0,i+1);
        inteiros[palavra]= std::stoi(operacoes(linha));
    }else if(palavra=="Paralelepípedo"){
        int i = linha.find('=');
        std::string palavra = linha.substr(0,i-1);
        linha.erase(0,i+1);
        strings[palavra]= operacoes(linha,string);
    }else if(palavra=="mostrar"){
        int i = linha.find(' ');
        std::string palavra = linha.substr(0,i);
        std::string linhas = linha;
        linhas.erase(0,i+1);
        if(palavra=="Mamacita"){
            std::cout<<inteiros[linhas]<<"\n";
        }if(palavra=="Paralelepípedo"){
            std::cout<<strings[linhas];
        }else{
            std::cout<<linha<<"\n";
        }
    }
}


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