#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "SelectionSort.h"
#include "Quicksort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "HeapMin.h"
#include "HeapExtMin.h"
#include "HeapIncre.h"
#include "maxHeap.h"
#include <filesystem>

using namespace std;

void imprimeMenuAlgoritmo(){

    cout << " --------------------------------------- " << endl;
    cout << "|                  MENU                 |" << endl;
    cout << "|Choose between the folling options:    |" << endl;
    cout << "|                                       |" << endl;
    cout << "|1 - Insertion Sort                     |" << endl;
    cout << "|2 - Selection Sort                     |" << endl;
    cout << "|3 - Shell Sort                         |" << endl;
    cout << "|4 - Bubble Sort                        |" << endl;
    cout << "|5 - Quick Sort(Randon)                 |" << endl;
    cout << "|6 - Quick Sort(Primeiro elemento)      |" << endl;
    cout << "|7 - Quick Sort(Media)                  |" << endl;
    cout << "|8 - Quick Sort(Mediana)                |" << endl;
    cout << "|9 - Merge Sort                         |" << endl;
    cout << "|10 - Heap Sort                         |" << endl;
    cout << "|11 - Heap Minimum                      |" << endl;
    cout << "|12 - Heap Extract Min                  |" << endl;
    cout << "|13 - Heap Increase Key                 |" << endl;
    cout << "|                                       |" << endl;
    cout << "|Which option would like ?              |" << endl;
    cout << " --------------------------------------- " << endl;        ;

}

void imprimeMenuTipo(){

    system("cls");
    cout << " --------------------------------------- " << endl;
    cout << "|                  MENU                 |" << endl;
    cout << "|Choose between the folling options:    |" << endl;
    cout << "|                                       |" << endl;
    cout << "|1 - R                                  |" << endl;
    cout << "|2 - C                                  |" << endl;
    cout << "|3 - D                                  |" << endl;
    cout << "|Which option would like ?              |" << endl;
    cout << " --------------------------------------- " << endl;

}

void imprimeMenuTamanho(){

    system("cls");
    cout << " --------------------------------------- " << endl;
    cout << "|                  MENU                 |" << endl;
    cout << "|Choose between the folling options:    |" << endl;
    cout << "|                                       |" << endl;
    cout << "|10                                     |" << endl;
    cout << "|100                                    |" << endl;
    cout << "|1.000                                  |" << endl;
    cout << "|10.000                                 |" << endl;
    cout << "|100.000                                |" << endl;
    cout << "|1.000.000                              |" << endl;
    cout << "|Which option would like ?              |" << endl;
    cout << " --------------------------------------- " << endl;

}


using namespace std;

int main(){

    int decisaoAlgo = 0;
    int decisaoTipo = 0;
    int Tam = 0;

    imprimeMenuAlgoritmo();
    cin >> decisaoAlgo;

    switch(decisaoAlgo){

        case 1:

            Insertion a;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:


                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    a.funcOrdenaArquivos(Tam, 1);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    a.funcOrdenaArquivos(Tam, 2);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    a.funcOrdenaArquivos(Tam, 3);
                    break;

            }
            break;

        case 2:

            SelectionSort b;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    b.funcOrdenaArquivos(Tam, 1);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    b.funcOrdenaArquivos(Tam, 2);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    b.funcOrdenaArquivos(Tam, 3);
                    break;
            }
            break;

        case 3:

            ShellSort c;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    c.funcOrdenaArquivos(Tam, 1);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    c.funcOrdenaArquivos(Tam, 2);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    c.funcOrdenaArquivos(Tam, 3);
                    break;

            }
            break;

        case 4:

            BubbleSort d;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    d.funcOrdenaArquivos(Tam, 1);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    d.funcOrdenaArquivos(Tam, 2);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    d.funcOrdenaArquivos(Tam, 3);
                    break;

            }
            break;

        case 5:

            Quicksort e;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    e.funcOrdenaArquivos(Tam, 1, 1);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    e.funcOrdenaArquivos(Tam, 2, 1);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    e.funcOrdenaArquivos(Tam, 3, 1);
                    break;
            }
            break;

        case 6:

            Quicksort f;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    f.funcOrdenaArquivos(Tam, 1, 2);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    f.funcOrdenaArquivos(Tam, 2, 2);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    f.funcOrdenaArquivos(Tam, 3, 2);
                    break;
            }
            break;

        case 7:

            Quicksort g;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    g.funcOrdenaArquivos(Tam, 1, 3);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    g.funcOrdenaArquivos(Tam, 2, 3);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    g.funcOrdenaArquivos(Tam, 3, 3);
                    break;

            }
            break;

        case 8:

            Quicksort h;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    h.funcOrdenaArquivos(Tam, 1, 4);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    h.funcOrdenaArquivos(Tam, 2, 4);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    h.funcOrdenaArquivos(Tam, 3, 4);
                    break;

            }
            break;

        case 9:

            MergeSort i;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    i.funcOrdenaArquivos(Tam, 1);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    i.funcOrdenaArquivos(Tam, 2);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    i.funcOrdenaArquivos(Tam, 3);
                    break;

            }
            break;

        case 10:

            Heapsort j;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    j.funcOrdenaArquivos(Tam, 1);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    j.funcOrdenaArquivos(Tam, 2);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    j.funcOrdenaArquivos(Tam, 3);
                    break;

            }
            break;

            case 11:

            Heapmin k;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    k.funcOrdenaArquivos(Tam, 1);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    k.funcOrdenaArquivos(Tam, 2);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    k.funcOrdenaArquivos(Tam, 3);
                    break;

            }
            break;

            case 12:

            HeapExt l;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    l.funcOrdenaArquivos(Tam, 1);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    l.funcOrdenaArquivos(Tam, 2);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    l.funcOrdenaArquivos(Tam, 3);
                    break;

            }
            break;

            case 13:

            HeapIncre m;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    m.funcOrdenaArquivos(Tam, 1);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    m.funcOrdenaArquivos(Tam, 2);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    m.funcOrdenaArquivos(Tam, 3);
                    break;

            }
            break;

            case 14:

            maxHeap n;
            system("cls");
            imprimeMenuTipo();
            cin >> decisaoTipo;

            switch(decisaoTipo){

                case 1:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    n.funcOrdenaArquivos(Tam, 1);
                    break;

                case 2:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    n.funcOrdenaArquivos(Tam, 2);
                    break;

                case 3:

                    imprimeMenuTamanho();
                    cin >> Tam;
                    system("cls");
                    n.funcOrdenaArquivos(Tam, 3);
                    break;

            }
            break;
    }

    return 0;
}

