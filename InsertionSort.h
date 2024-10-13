#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <iostream>
#include <filesystem>
#include <ctime>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

class Insertion{

    public:

    void criarPastas();
    void escreverArquivo(const string&, const string&, const string&);
    Insertion& funcOrdenaArquivos(int, int);
    int GetN(int);
    double GetT();

    Insertion& funcEntrada(int, int);
    Insertion& funcOrdena();

    private:

    int Tam;
    int Tipo;
    double tempo;
    int *Vetor;

};

#endif
