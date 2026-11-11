#include "operacoes.hpp"

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
        }else if(palavra=="Paralelepípedo"){
            std::cout<<strings[linhas]<<"\n";
        }else{
            std::cout<<linha<<"\n";
        }
    }
}
bool acha (char a, std::string st){
    for(char i:st){
        if(i==a){
            return true;
        }
    }
    return false;
}