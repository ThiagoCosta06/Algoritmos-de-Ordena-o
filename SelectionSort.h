#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <iostream>
#include <filesystem>
#include <ctime>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

class SelectionSort{

    public:

    void criarPastas();
    void escreverArquivo(const string&, const string&, const string&);
    SelectionSort& funcOrdenaArquivos(int, int);
    int GetN(int);
    double GetT();

    SelectionSort& funcEntrada(int, int);
    SelectionSort& funcOrdena();

    private:

    int Tam, Tipo;
    double tempo;
    int *Vetor;

};

#endif
