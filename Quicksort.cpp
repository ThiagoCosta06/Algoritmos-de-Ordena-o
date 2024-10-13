#include <iostream>
#include <stdio.h>
#include "Quicksort.h"
#include <time.h>
#include <filesystem>
#include <ctime>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

void Quicksort::criarPastas(){
    //Nome da Pasta Principal
    string pastaPrincipal = "QuickSortFiles";
    //Criação da Pasta Principal
    fs::create_directory(pastaPrincipal);

    //subpastas
    string pastaQuicksortRandon = pastaPrincipal + "/QuickRandon";
    string pastaQuicksortFirst = pastaPrincipal + "/QuickFirst";
    string pastaQuicksortMedia = pastaPrincipal + "/QuickMedia";
    string pastaQuicksortMediana = pastaPrincipal + "/QuickMediana";

    fs::create_directory(pastaQuicksortRandon);
    fs::create_directory(pastaQuicksortFirst);
    fs::create_directory(pastaQuicksortMedia);
    fs::create_directory(pastaQuicksortMediana);

    cout << "Trabalhando" << endl;

    //Nomes das Subpastas
    string pastaEntrada1 = pastaPrincipal + pastaQuicksortRandon + "/Entrada";
    string pastaSaida1 = pastaPrincipal + pastaQuicksortRandon + "/Saida";
    string pastaTempo1 = pastaPrincipal + pastaQuicksortRandon + "/Tempo";
    string pastaEntrada2 = pastaPrincipal + pastaQuicksortFirst + "/Entrada";
    string pastaSaida2 = pastaPrincipal + pastaQuicksortFirst + "/Saida";
    string pastaTempo2 = pastaPrincipal + pastaQuicksortFirst + "/Tempo";
    string pastaEntrada3 = pastaPrincipal + pastaQuicksortMedia + "/Entrada";
    string pastaSaida3 = pastaPrincipal + pastaQuicksortMedia + "/Saida";
    string pastaTempo3 = pastaPrincipal + pastaQuicksortMedia + "/Tempo";
    string pastaEntrada4 = pastaPrincipal + pastaQuicksortMediana + "/Entrada";
    string pastaSaida4 = pastaPrincipal + pastaQuicksortMediana + "/Saida";
    string pastaTempo4 = pastaPrincipal + pastaQuicksortMediana + "/Tempo";

    cout << "Trabalhando " << endl;

    //Criação das subpastas
    fs::create_directory(pastaEntrada1);
    fs::create_directory(pastaSaida1);
    fs::create_directory(pastaTempo1);
    fs::create_directory(pastaEntrada2);
    fs::create_directory(pastaSaida2);
    fs::create_directory(pastaTempo2);
    fs::create_directory(pastaEntrada3);
    fs::create_directory(pastaSaida3);
    fs::create_directory(pastaTempo3);
    fs::create_directory(pastaEntrada4);
    fs::create_directory(pastaSaida4);
    fs::create_directory(pastaTempo4);

    cout << "Terminei" << endl;
}

void Quicksort::escreverArquivo(const string& pasta, const string& nomeArquivo, const string& conteudo){
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

Quicksort& Quicksort::funcOrdenaArquivos(int Tamanho, int Type, int Algoritmo){
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

    string caminhoEntrada, caminhoSaida, caminhoTempo;

    if(Algoritmo == 1){
        //caminho completo dos arquivos
        caminhoEntrada = "QuickSortFiles/QuickRandon/Entrada";
        caminhoSaida = "QuickSortFiles/QuickRandon/Saida";
        caminhoTempo = "QuickSortFiles/QuickRandon/Tempo";
    }else if(Algoritmo == 2){
        //caminho completo dos arquivos
        caminhoEntrada = "QuicksortFiles/QuickFirst/Entrada";
        caminhoSaida = "QuicksortFiles/QuickFirst/Saida";
        caminhoTempo = "QuicksortFiles/QuickFirst/Tempo";
    }else if(Algoritmo == 3){
        //caminho completo dos arquivos
        caminhoEntrada = "QuicksortFiles/QuickMedia/Entrada";
        caminhoSaida = "QuicksortFiles/QuickMedia/Saida";
        caminhoTempo = "QuicksortFiles/QuickMedia/Tempo";
    }else if(Algoritmo == 4){
        //caminho completo dos arquivos
        caminhoEntrada = "QuicksortFiles/QuickMediana/Entrada";
        caminhoSaida = "QuicksortFiles/QuickMediana/Saida";
        caminhoTempo = "QuicksortFiles/QuickMediana/Tempo";
    }
    //Chama a função de entrada e gera o arquivo de entrada
    this->funcEntrada(this->Tam, this->Tipo);
    this->escreverArquivo(caminhoEntrada, nomeArquivoEntrada, "NUM");
    //Chama a função de ordenação
    if(Algoritmo == 1){
        this->funcOrdenaRandon(0, this->Tam - 1);
    }else if(Algoritmo == 2){
        this->funcOrdenaFirst(0, this->Tam - 1);
    }else if(Algoritmo == 3){
        this->funcOrdenaMediana(0, this->Tam - 1);
    }else if(Algoritmo == 4){
        this->funcOrdenaMediana(0, this->Tam - 1);
    }
    //Gera os arquivos de saida e tempo
    this->escreverArquivo(caminhoSaida, nomeArquivoSaida, "NUM");
    this->escreverArquivo(caminhoTempo, nomeArquivoTempo, "TEMPO");

    //libera memoria
    delete[] this->Vetor;
    return *this;
}

int Quicksort::GetN(int i){
    return this->Vetor[i];
}

double Quicksort::GetT(){
    return this->tempo;
}

int Quicksort::GetTam(){
    return this->Tam;
}

Quicksort& Quicksort::swap(int a, int b){
    int temp = this->Vetor[a];
    this->Vetor[a] = this->Vetor[b];
    this->Vetor[b] = temp;
    return *this;
}

int Quicksort::pivoRandon(int esquerda, int direita){
    int randon = esquerda + rand() % (direita - esquerda + 1);
    swap(randon, direita);
    return this->Vetor[direita];
}

int Quicksort::particiona(int esquerda, int direita){
    int pivo = pivoRandon(esquerda, direita);
    int i = esquerda - 1;

    for(int j = esquerda; j <= direita - 1; j++){
        if(this->Vetor[j] < pivo){
            i++;
            swap(i, j);
        }
    }

    swap(i + 1, direita);
    return i + 1;
}

int Quicksort::particiona2(int esquerda, int direita){
    int pivo = this->Vetor[esquerda];
    int i =  esquerda + 1;

    for(int j = esquerda + 1; j <= direita; j++){
        if(this->Vetor[j] < pivo){
            swap(i, j);
            i++;
        }
    }
    swap(esquerda, i-1);
    return i - 1;
}

int Quicksort::encontrarMedia(int esquerda, int direita){
    int meio = (esquerda + direita) / 2;

    if(this->Vetor[esquerda] > this->Vetor[meio]){
        swap(esquerda, meio);
    }
    if(this->Vetor[esquerda] > this->Vetor[direita]){
        swap(esquerda, direita);
    }
    if(this->Vetor[meio] > this->Vetor[direita]){
        swap(meio, direita);
    }

    swap(meio, direita);
    return direita;
}

int Quicksort::particiona3(int esquerda, int direita){
    int pivo =  encontrarMedia(esquerda, direita);
    int pivot = this->Vetor[pivo];
    int i = esquerda - 1;

    for(int j = esquerda; j <= direita - 1; j++){
        if(this->Vetor[j] < pivot){
            i++;
            swap(i, j);
        }
    }

    swap(i + 1, pivo);
    return i + 1;
}

Quicksort& Quicksort::funcEntrada(int n, int m){
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

Quicksort& Quicksort::funcOrdenaRandon(int low, int high){
    system("cls");
    cout << "The Algorithm is working..." << endl;
    double temp;
    clock_t tInicial = clock();
    int esquerda = low;
    int direita = high;
    if(esquerda < direita){
        int pi = particiona(esquerda, direita);
        funcOrdenaRandon(esquerda, pi - 1);
        funcOrdenaRandon(pi + 1, direita);
    };

    clock_t tFim = clock();
    temp = (tFim - tInicial) / (double)CLOCKS_PER_SEC;
    this->tempo = temp;
    system("cls");
    cout << "The Program Has Ended" << endl;
    return *this;
}

Quicksort& Quicksort::funcOrdenaFirst(int low, int high){
    system("cls");
    cout << "The Algorithm is working..." << endl;
    double temp;
    clock_t tInicial = clock();
    int esquerda = low;
    int direita = high;
    if(esquerda < direita){
        int pi = particiona2(esquerda, direita);
        funcOrdenaFirst(esquerda, pi - 1);
        funcOrdenaFirst(pi + 1, direita);
    };

    clock_t tFim = clock();
    temp = (tFim - tInicial) / (double)CLOCKS_PER_SEC;
    this->tempo = temp;
    system("cls");
    cout << "The Program Has Ended" << endl;
    return *this;
}

Quicksort& Quicksort::funcOrdenaMediana(int low, int high){
    system("cls");
    cout << "The Algorithm is working..." << endl;
    double temp;
    clock_t tInicial = clock();
    int esquerda = low;
    int direita = high;
    if(esquerda < direita){
        int pi = particiona3(esquerda, direita);
        funcOrdenaMediana(esquerda, pi - 1);
        funcOrdenaMediana(pi + 1, direita);
    };

    clock_t tFim = clock();
    temp = (tFim - tInicial) / (double)CLOCKS_PER_SEC;
    this->tempo = temp;
    system("cls");
    cout << "The Program Has Ended" << endl;
    return *this;
}
