#include <iostream>
#include <stdio.h>
#include "ShellSort.h"
#include <time.h>
#include <filesystem>
#include <ctime>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

void ShellSort::criarPastas(){
    //Nome da Pasta Principal
    string pastaPrincipal = "ShellSortFiles";
    //Criação da Pasta Principal
    fs::create_directory(pastaPrincipal);

    //Nomes das Subpastas
    string pastaEntrada = pastaPrincipal + "/Entrada";
    string pastaSaida = pastaPrincipal + "/Saida";
    string pastaTempo = pastaPrincipal + "/Tempo";

    //Criação das subpastas
    fs::create_directory(pastaEntrada);
    fs::create_directory(pastaSaida);
    fs::create_directory(pastaTempo);
}

void ShellSort::escreverArquivo(const string& pasta, const string& nomeArquivo, const string& conteudo){
    //Caminho completo do arquivo
    string caminhoCompleto = pasta + "/" + nomeArquivo;
    //criação do arquivo
    ofstream arquivo(caminhoCompleto);
    //Escrita do conteudo no arquivo
    if(conteudo == "NUM"){
        arquivo << "Tamanho: " << this->Tam << "\n";
        for(int i = 0; i < this->Tam; i++){
            arquivo << this->GetN(i) << "\n";
        }
        }else if(conteudo == "TEMPO"){
            arquivo << "Tamanho: " << this->Tam << "\n";
            arquivo << this->GetT();
    }
}

ShellSort& ShellSort::funcOrdenaArquivos(int Tamanho, int Type){
    this->Tam = Tamanho;
    this->Tipo = Type;
    //Criação das Pastas
    this->criarPastas();
    string nomeArquivoEntrada, nomeArquivoSaida, nomeArquivoTempo;
    switch(this->Tipo){

        case 1:
            //Geração de nome unico para os arquivos baseado no tipo e tamanho
            nomeArquivoEntrada = to_string(this->Tam) + "R.txt";
            nomeArquivoSaida = to_string(this->Tam) + "R.txt";
            nomeArquivoTempo = to_string(this->Tam) + "R.txt";
            break;

        case 2:
            nomeArquivoEntrada = to_string(this->Tam) + "C.txt";
            nomeArquivoSaida = to_string(this->Tam) + "C.txt";
            nomeArquivoTempo = to_string(this->Tam) + "C.txt";
            break;

        case 3:
            nomeArquivoEntrada = to_string(this->Tam) + "D.txt";
            nomeArquivoSaida = to_string(this->Tam) + "D.txt";
            nomeArquivoTempo = to_string(this->Tam) + "D.txt";
            break;
    }

    //caminho completo dos arquivos
    string caminhoEntrada = "ShellSortFiles/Entrada";
    string caminhoSaida = "ShellSortFiles/Saida";
    string caminhoTempo = "ShellSortFiles/Tempo";
    //Chama a função de entrada e gera o arquivo de entrada
    this->funcEntrada(this->Tam, this->Tipo);
    this->escreverArquivo(caminhoEntrada, nomeArquivoEntrada, "NUM");
    //Chama a função de ordenação
    this->funcOrdena();
    //Gera os arquivos de saida e tempo
    this->escreverArquivo(caminhoSaida, nomeArquivoSaida, "NUM");
    this->escreverArquivo(caminhoTempo, nomeArquivoTempo, "TEMPO");

    //libera memoria
    delete[] this->Vetor;
    return *this;
}

int ShellSort::GetN(int i){
    return this->Vetor[i];
}

double ShellSort::GetT(){
    return this->tempo;
}

ShellSort& ShellSort::funcEntrada(int n, int m){
    this->Tam = n;
    this->Tipo = m;
    this->Vetor = new int[Tam];
    switch(this->Tipo){

        case 1:

            for(int i = 0; i < this->Tam; i++){
                this->Vetor[i] = rand();
            }
            return *this;
            break;


        case 2:

        this->Vetor[0] = rand();
        for(int i = 0; i  <this->Tam - 1; i++){
            this->Vetor[i+1] = this->Vetor[i] + 1;
        }
        return *this;
        break;

        case 3:

        this->Vetor[0] = rand();
        for(int i = 0; i < this->Tam - 1; i++){
            this->Vetor[i+1] = this->Vetor[i] - 1;
        }
        return *this;
        break;
    }
}

ShellSort& ShellSort::funcOrdena (){
    system("cls");
    cout << "The Algorithm is working..." << endl;
    double temp;
    clock_t tInicial, tFim;
    int i, j, t, h;
    this->Tam--;
    h = 1;
    do{
        h = 3 * h + 1;
    }   while(h < this->Tam);
    while(h > 0){
        for(i = h; i <= this->Tam; i++){
            t = this->Vetor[i];
            for(j = i - h; ((j >= 0) && (this->Vetor[j] > t)); j = j - h){
                this->Vetor[j + h] = this->Vetor[j];
            }
            this->Vetor[j + h] = t;
        }
        h /= 3;
    }
    tFim = clock();
    temp = (tFim - tInicial) / (double)CLOCKS_PER_SEC;
    this->tempo = temp;
    system("cls");
    cout << "The Program Has Ended" << endl;
    return *this;
}
