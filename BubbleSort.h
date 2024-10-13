#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <iostream>
#include <filesystem>
#include <ctime>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

class BubbleSort{

public:

    void criarPastas();
    void escreverArquivo(const string&, const string&, const string&);
    BubbleSort& funcOrdenaArquivos(int, int);
    int GetN(int);
    double GetT();

    BubbleSort& funcEntrada(int, int);
    BubbleSort& funcOrdena();


private:

    int Tam;
    int Tipo;
    double tempo;
    int *Vetor;

};

#endif
