#ifndef HEAPMAX_H
#define HEAPMAX_H
#include <iostream>
#include <vector>

using namespace std;

class maxHeap{

    public:

    void criarPastas();
    void escreverArquivo(const string&, const string&, const string&);
    maxHeap& funcOrdenaArquivos(int, int);
    int GetN(int);
    double GetT();
    int GetTam();

    maxHeap& funcEntrada(int, int);
    maxHeap& swap(int, int);
    maxHeap& Heapifymin(int); //verifica
    maxHeap& buildMinHeap(); //constroi
    maxHeap& maxInsert(); //

    private:

    int *Vetor, Tam, Tipo;
    double tempo;

};

#endif
