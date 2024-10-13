#include <iostream>
#include <stdio.h>
#include "InsertionSort.h"
#include <time.h>
#include <filesystem>
#include <ctime>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

void Insertion::criarPastas(){
    //Nome da Pasta Principal
    string pastaPrincipal = "InsertionSortFiles";
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

void Insertion::escreverArquivo(const string& pasta, const string& nomeArquivo, const string& conteudo){
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


Insertion& Insertion::funcOrdenaArquivos(int Tamanho, int Type){
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
    string caminhoEntrada = "InsertionSortFiles/Entrada";
    string caminhoSaida = "InsertionSortFiles/Saida";
    string caminhoTempo = "InsertionSortFiles/Tempo";
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

int Insertion::GetN(int i){
    return this->Vetor[i];
}

double Insertion::GetT(){
    return this->tempo;
}

Insertion& Insertion::funcEntrada(int n, int m){

    this->Tam = n;
    this->Tipo = m;
    this->Vetor = new int[Tam];

    switch(this->Tipo){

        case 1: //random

            for(int i = 0; i < this->Tam; i++){
                this->Vetor[i] = rand();
            }
            return *this;
            break;
        case 2: //crescente

            this->Vetor[0] = rand();
            for(int i = 0; i < this->Tam - 1; i++){
                this->Vetor[i+1] = this->Vetor[i] + 1;
            }
            return *this;
            break;

        case 3: //decrescente

            this->Vetor[0] = rand();
            for(int i = 0; i < this->Tam - 1; i++){
                this->Vetor[i+1] = this->Vetor[i] - 1;
            }
            return *this;
            break;
    }
}

Insertion& Insertion::funcOrdena(){
    system("cls");
    cout << "The Algorithm is working..." << endl;
    double temp;
    int key;
    int j = 0;
    clock_t tInicial, tFim;
    tInicial = clock();
    for(int i = 0; i < this->Tam; i++){
            key = this->Vetor[i];
            j = j-1;
            while(j>= 0 && this->Vetor[j] > key){
                this->Vetor[j+1] = this->Vetor[j];
                j = j-1;
            }
            this->Vetor[j+1] = key;
    }
    tFim = clock();
    temp = (tFim - tInicial) / (double)CLOCKS_PER_SEC;
    this->tempo = temp;
    system("cls");
    cout << "The Program Has ended";
    return *this;
}

