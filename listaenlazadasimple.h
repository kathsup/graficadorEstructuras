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
    Nodo* getCabeza() const;
    int getSize() const;
    bool borrar(int valor);
    int buscar (int valor);
};

#endif // LISTAENLAZADASIMPLE_H
