#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iostream>

using namespace std;

class Heapsort{

    public:

    void criarPastas();
    void escreverArquivo(const string&, const string&, const string&);
    Heapsort& funcOrdenaArquivos(int, int);
    int GetN(int);
    double GetT();
    int GetTam();

    Heapsort& funcEntrada(int, int);
    Heapsort& swap(int, int);
    Heapsort& Heapifymin(int); //verifica
    Heapsort& buildMinHeap(); //constroi
    Heapsort& heapSort(); //

    private:

    int *Vetor, Tam, Tipo;
    double tempo;

};

#endif
