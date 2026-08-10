#include <iostream>
#include <fstream>
#include <unordered_map>
#include <ranges>
std::unordered_map<std::string,int> inteiros{

};
bool acha (char a, std::string st){
    for(char i:st){
        if(i==a){
            return true;
        }
    }
    return false;
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

int operacoes(std::string linha){
    if(acha('+',linha)){
        int i = linha.find('+');
        int Primeiro= numero(linha.substr(0,i));
        int Segundo= numero(linha.substr(i+1,linha.length()-1));
        return Primeiro+Segundo;
    } else if(acha('-',linha)){
        int i = linha.find('-');
        int Primeiro= numero(linha.substr(0,i));
        int Segundo= numero(linha.substr(i+1,linha.length()-1));
        return Primeiro-Segundo;
    } else if(acha('*',linha)){
        int i = linha.find('*');
        int Primeiro= numero(linha.substr(0,i));
        int Segundo= numero(linha.substr(i+1,linha.length()-1));
        return Primeiro*Segundo;
    }else if(acha('/',linha)){
        int i = linha.find('/');
        int Primeiro= numero(linha.substr(0,i));
        int Segundo= numero(linha.substr(i+1,linha.length()-1));
        return Primeiro / Segundo;
    }else{
        return numero(linha);
    }
}

void func(std::string linha,std::string palavra){
    if(palavra=="Mamacita"){
        int i = linha.find('=');
        std::string palavra = linha.substr(0,i-1);
        linha.erase(0,i+1);
        inteiros[palavra]= operacoes(linha);
    }else if(palavra=="mostrar"){
        int i = linha.find(' ');
        std::string palavra = linha.substr(0,i);
        std::string linhas = linha;
        linhas.erase(0,i+1);
        if(palavra=="Mamacita"){
            std::cout<<inteiros[linhas]<<"\n";
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