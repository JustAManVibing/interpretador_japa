#include <iostream>
#include <fstream>
#include <unordered_map>

std::unordered_map<std::string,int> inteiros{

};


void func(std::string linha,std::string palavra){
    if(palavra=="Mamacita"){
        int i = linha.find(' ');
        std::string palavra = linha.substr(0,i);
        linha.erase(0,i+3);
        inteiros[palavra]= std::stoi(linha);
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