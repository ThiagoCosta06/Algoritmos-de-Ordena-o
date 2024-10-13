#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>
#include <filesystem>
#include <ctime>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

class MergeSort{

public:

    void criarPastas();
    void escreverArquivo(const string&, const string&, const string&);
    MergeSort& funcOrdenaArquivos(int, int);
    int GetN(int);
    double GetT();
    int GetTam();

    MergeSort& funcEntrada(int, int);
    MergeSort& merge(int, int, int);
    MergeSort& funcOrdena(int, int);

private:

    int *Vetor, Tam, Tipo;
    double tempo;

};

#endif
