#include <iostream>
#include <stdio.h>
#include "HeapSort.h"
#include <time.h>
#include <filesystem>
#include <ctime>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

void Heapsort::criarPastas(){
    //Nome da Pasta Principal
    string pastaPrincipal = "HeapSortFiles";
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

void Heapsort::escreverArquivo(const string& pasta, const string& nomeArquivo, const string& conteudo){
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

Heapsort& Heapsort::funcOrdenaArquivos(int Tamanho, int Type){
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
    string caminhoEntrada = "HeapSortFiles/Entrada";
    string caminhoSaida = "HeapSortFiles/Saida";
    string caminhoTempo = "HeapSortFiles/Tempo";
    //Chama a função de entrada e gera o arquivo de entrada
    this->funcEntrada(this->Tam, this->Tipo);
    this->escreverArquivo(caminhoEntrada, nomeArquivoEntrada, "NUM");
    //Chama a função de ordenação
    cout << "Vetor original:" << endl;
    for(int i = 0; i < this->Tam; i++){
        cout << this->Vetor[i] << " ";
    }
    cout << endl;
    this->heapSort();
    cout << "Vetor chamando Build: " << endl;
    for(int i = 0; i < this->Tam; i++){
        cout << this->Vetor[i] << " ";
    }
    cout << endl;
    system("pause");
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

int Heapsort::GetN(int i){
    return this->Vetor[i];
}

double Heapsort::GetT(){
    return this->tempo;
}

int Heapsort::GetTam(){
    return this->Tam;
}

Heapsort& Heapsort::funcEntrada(int n, int m){
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

Heapsort& Heapsort::swap(int a, int b){
    int temp = this->Vetor[a];
    this->Vetor[a] = this->Vetor[b];
    this->Vetor[b] = temp;
    return *this;
}

Heapsort& Heapsort::Heapifymin(int i){
    int n = this->Tam;
    int menor = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    if(esquerda < n && this->Vetor[esquerda] < this->Vetor[menor]){
        menor = esquerda;
    }
    if(direita < n && this->Vetor[direita] < this->Vetor[menor]){
        menor = direita;
    }
    if(menor != i){
        swap(this->Vetor[i], this->Vetor[menor]);
        Heapifymin(menor);
    }
    return *this;
}

Heapsort& Heapsort::buildMinHeap(){
    int n = this->GetTam();
    for(int i = n / 2 - 1; i >= 0; i--){
        this->Heapifymin(i);
    }
    return *this;
}

Heapsort& Heapsort::heapSort(){
    this->buildMinHeap();
    for(int i = this->Tam - 1; i >= 0; i--){
        swap(this->Vetor[0], this->Vetor[i]);
        this->Heapifymin(0);
    }
    return *this;
}
