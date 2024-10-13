#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>

using namespace std;

class Quicksort{

public:

    int GetN(int);
    double GetT();
    int GetTam();

    void criarPastas();
    void escreverArquivo(const string&, const string&, const string&);
    Quicksort& funcOrdenaArquivos(int, int, int);
    Quicksort& swap(int, int);
    int pivoRandon(int, int);
    int particiona(int, int); //para o Quicksort com pivo randomico
    int particiona2(int, int); //para o Quicksort com o primeiro elemento como pivo
    int encontrarMedia(int, int); //para o Quicksort com a media dos tres elementos para melhorar a escolha do pivo
    int particiona3(int, int); // para o Quicksort com a media dos tres elementos para melhorar a escolha do pivo
    Quicksort& funcEntrada(int, int);
    Quicksort& funcOrdenaRandon(int, int);
    Quicksort& funcOrdenaFirst(int, int);
    Quicksort& funcOrdenaMediana(int, int);

private:

    int *Vetor, Tam, Tipo;
    double tempo;

};

#endif
