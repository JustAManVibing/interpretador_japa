#include <iostream>
#include <fstream>
#include <unordered_map>

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

int operacoes(std::string linha){
    if(acha('+',linha)){
        int i = linha.find('+');
        int Primeiro= std::stoi(linha.substr(0,i));
        int Segundo= std::stoi(linha.substr(i+1,linha.length()-1));
        return Primeiro+Segundo;
    } else if(acha('-',linha)){
        int i = linha.find('-');
        int Primeiro= std::stoi(linha.substr(0,i));
        int Segundo= std::stoi(linha.substr(i+1,linha.length()-1));
        return Primeiro-Segundo;
    } else if(acha('*',linha)){
        int i = linha.find('*');
        int Primeiro= std::stoi(linha.substr(0,i));
        int Segundo= std::stoi(linha.substr(i+1,linha.length()-1));
        return Primeiro*Segundo;
    }else if(acha('/',linha)){
        int i = linha.find('/');
        int Primeiro= std::stoi(linha.substr(0,i));
        int Segundo= std::stoi(linha.substr(i+1,linha.length()-1));
        return Primeiro / Segundo;
    }else{
        return std::stoi(linha);
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
        linha.erase(0,i+1);
        if(palavra=="Mamacita"){
            std::cout<<inteiros[linha]<<"\n";
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