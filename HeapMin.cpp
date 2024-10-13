#include <iostream>
#include <stdio.h>
#include "HeapMin.h"
#include <time.h>
#include <filesystem>
#include <ctime>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

void Heapmin::criarPastas(){
    //Nome da Pasta Principal
    string pastaPrincipal = "HeapMinFiles";
    //Cria��o da Pasta Principal
    fs::create_directory(pastaPrincipal);

    //Nomes das Subpastas
    string pastaEntrada = pastaPrincipal + "/Entrada";
    string pastaSaida = pastaPrincipal + "/Saida";
    string pastaTempo = pastaPrincipal + "/Tempo";

    //Cria��o das subpastas
    fs::create_directory(pastaEntrada);
    fs::create_directory(pastaSaida);
    fs::create_directory(pastaTempo);
}

void Heapmin::escreverArquivo(const string& pasta, const string& nomeArquivo, const string& conteudo){
    //Caminho completo do arquivo
    string caminhoCompleto = pasta + "/" + nomeArquivo;
    //cria��o do arquivo
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

Heapmin& Heapmin::funcOrdenaArquivos(int Tamanho, int Type){
    this->Tam = Tamanho;
    this->Tipo = Type;
    //Cria��o das Pastas
    this->criarPastas();
    cout << "Criou as pastas";
    string nomeArquivoEntrada, nomeArquivoSaida, nomeArquivoTempo;
    switch(this->Tipo){

        case 1:
            //Gera��o de nome unico para os arquivos baseado no tipo e tamanho
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
    string caminhoEntrada = "HeapMinFiles/Entrada";
    string caminhoSaida = "HeapMinFiles/Saida";
    string caminhoTempo = "HeapMinFiles/Tempo";
    //Chama a fun��o de entrada e gera o arquivo de entrada
    this->funcEntrada(this->Tam, this->Tipo);
    this->escreverArquivo(caminhoEntrada, nomeArquivoEntrada, "NUM");
    //Chama a fun��o de ordena��o
    cout << "Vetor original:" << endl;
    for(int i = 0; i < this->Tam; i++){
        cout << this->Vetor[i] << " ";
    }
    cout << endl;
    this->heapMinimum();
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

int Heapmin::GetN(int i){
    return this->Vetor[i];
}

double Heapmin::GetT(){
    return this->tempo;
}

int Heapmin::GetTam(){
    return this->Tam;
}

Heapmin& Heapmin::funcEntrada(int n, int m){
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

Heapmin& Heapmin::swap(int a, int b){
    int temp = this->Vetor[a];
    this->Vetor[a] = this->Vetor[b];
    this->Vetor[b] = temp;
    return *this;
}

Heapmin& Heapmin::Heapifymin(int i){
    int n = this->GetTam();
    int menor = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    if(esquerda <= n && this->Vetor[esquerda] < this->Vetor[menor]){
        menor = esquerda;
    }
    if(direita <= n && this->Vetor[direita] < this->Vetor[menor]){
        menor = direita;
    }
    if(menor != i){
        swap(this->Vetor[i], this->Vetor[menor]);
        Heapifymin(menor);
    }
    return *this;
}

Heapmin& Heapmin::buildMinHeap(){
    int n = this->GetTam();
    for(int i = n / 2 - 1; i >= 1; i--){
        this->Heapifymin(i);
    }
    return *this;
}

Heapmin& Heapmin::heapMinimum(){
    this->buildMinHeap();
    int menor = this->Vetor[0];
    cout << "Vetor chamando Build: " << endl;
    for(int i = 0; i < this->Tam; i++){
        cout << this->Vetor[i] << " ";
    }
    cout << endl;
    cout << "Elemento minimo: " << menor;
    return *this;
}
