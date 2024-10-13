#include <iostream>
#include <stdio.h>
#include "MergeSort.h"
#include <time.h>
#include <filesystem>
#include <ctime>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

void MergeSort::criarPastas(){
    //Nome da Pasta Principal
    string pastaPrincipal = "MergeSortFiles";
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

void MergeSort::escreverArquivo(const string& pasta, const string& nomeArquivo, const string& conteudo){
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

MergeSort& MergeSort::funcOrdenaArquivos(int Tamanho, int Type){
    this->Tam = Tamanho;
    this->Tipo = Type;
    //Criação das Pastas
    this->criarPastas();
    cout << "Criou as pastas";
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
    string caminhoEntrada = "MergeSortFiles/Entrada";
    string caminhoSaida = "MergeSortFiles/Saida";
    string caminhoTempo = "MergeSortFiles/Tempo";
    //Chama a função de entrada e gera o arquivo de entrada
    this->funcEntrada(this->Tam, this->Tipo);
    this->escreverArquivo(caminhoEntrada, nomeArquivoEntrada, "NUM");
    //Chama a função de ordenação
    this->funcOrdena(0, this->Tam - 1);
    system("cls");
    cout << "The Program Is Working" << endl;
     //Gera os arquivos de saida e tempo
    this->escreverArquivo(caminhoSaida, nomeArquivoSaida, "NUM");
    this->escreverArquivo(caminhoTempo, nomeArquivoTempo, "TEMPO");
    system("cls");
    cout << "The Program Has Ended" << endl;

    //libera memoria
    delete[] this->Vetor;
    return *this;
}

int MergeSort::GetN(int i){
    return this->Vetor[i];
}

double MergeSort::GetT(){
    return this->tempo;
}

int MergeSort::GetTam(){
    return this->Tam;
}

MergeSort& MergeSort::funcEntrada(int n, int m){
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

MergeSort& MergeSort::merge(int esquerda, int meio, int direita){
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int *Vetor1, *Vetor2;
    Vetor1 = new int[n1];
    Vetor2 = new int[n2];

    for(int i = 0; i < n1; i++){
        Vetor1[i] = this->Vetor[esquerda + 1];
    }
    for(int j = 0; j < n2; j++){
        Vetor2[j] = this->Vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = esquerda;

    while(i < n1 && j < n2){
        if(Vetor1[i] <= Vetor2[j]){
            this->Vetor[k] = Vetor1[i];
            i++;
        }else{
            this->Vetor[k] = Vetor2[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        this->Vetor[k] = Vetor1[i];
        i++;
        k++;
    }

    while(j < n2){
        this->Vetor[k] = Vetor2[j];
        j++;
        k++;
    }

}

MergeSort& MergeSort::funcOrdena(int esquerda, int direita){
    double temp;
    clock_t tInicial, tFim;

    if(esquerda < direita){
        int meio =  esquerda + (direita - esquerda) / 2;

        funcOrdena(esquerda, meio);
        funcOrdena(meio + 1, direita);
        merge(esquerda, meio, direita);
    }

    tFim = clock();
    temp = (tFim - tInicial) / (double)CLOCKS_PER_SEC;
    this->tempo = temp;
    return *this;
    }
