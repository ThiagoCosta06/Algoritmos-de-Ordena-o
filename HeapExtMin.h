#ifndef HEAPEXTMIN_H
#define HEAPEXTMIN_H
#include <iostream>

using namespace std;

class HeapExt{

    public:

    void criarPastas();
    void escreverArquivo(const string&, const string&, const string&);
    HeapExt& funcOrdenaArquivos(int, int);
    int GetN(int);
    double GetT();
    int GetTam();

    HeapExt& funcEntrada(int, int);
    HeapExt& swap(int, int);
    HeapExt& Heapifymin(int); //verifica
    HeapExt& buildMinHeap(); //constroi
    HeapExt& extractMin();

    private:

    int *Vetor, Tam, Tipo;
    double tempo;

};

#endif
