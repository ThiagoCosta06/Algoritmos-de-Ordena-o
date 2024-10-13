#ifndef SHELLSORT_H
#define SHELLSORT_H
#include <iostream>
#include <filesystem>
#include <ctime>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

class ShellSort{

public:

    void criarPastas();
    void escreverArquivo(const string&, const string&, const string&);
    ShellSort& funcOrdenaArquivos(int, int);
    int GetN(int);
    double GetT();

    ShellSort& funcEntrada(int, int);
    ShellSort& funcOrdena();

private:

    int Tam, Tipo;
    double tempo;
    int *Vetor;

};

#endif

