#ifndef HEAPINCRE_H
#define HEAPINCRE_H
#include <iostream>

using namespace std;

class HeapIncre{

    public:

    void criarPastas();
    void escreverArquivo(const string&, const string&, const string&);
    HeapIncre& funcOrdenaArquivos(int, int);
    int GetN(int);
    double GetT();
    int GetTam();

    HeapIncre& funcEntrada(int, int);
    HeapIncre& swap(int, int);
    HeapIncre& Heapifymin(int); //verifica
    HeapIncre& buildMinHeap(); //constroi
    HeapIncre& HeapIncrease();

    private:

    int *Vetor, Tam, Tipo;
    double tempo;

};

#endif
