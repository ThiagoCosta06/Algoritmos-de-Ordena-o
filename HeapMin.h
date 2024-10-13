#ifndef HEAPMIN_H
#define HEAPMIN_H
#include <iostream>

using namespace std;

class Heapmin{

    public:

    void criarPastas();
    void escreverArquivo(const string&, const string&, const string&);
    Heapmin& funcOrdenaArquivos(int, int);
    int GetN(int);
    double GetT();
    int GetTam();

    Heapmin& funcEntrada(int, int);
    Heapmin& swap(int, int);
    Heapmin& Heapifymin(int); //verifica
    Heapmin& buildMinHeap(); //constroi
    Heapmin& heapMinimum(); //

    private:

    int *Vetor, Tam, Tipo;
    double tempo;

};

#endif // HEAPMIN_H
