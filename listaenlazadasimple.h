#ifndef LISTAENLAZADASIMPLE_H
#define LISTAENLAZADASIMPLE_H
#include "nodo.h"

class listaEnlazadaSimple
{
public:
    Nodo *cabeza;
    int size;
    listaEnlazadaSimple();

    bool insertarCola(int n, int pos);

};

#endif // LISTAENLAZADASIMPLE_H
