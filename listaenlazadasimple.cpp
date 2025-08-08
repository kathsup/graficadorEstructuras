#include "listaenlazadasimple.h"

listaEnlazadaSimple::listaEnlazadaSimple() {
    this->cabeza=nullptr;
}

bool listaEnlazadaSimple::insertarCola(int n, int pos){

    //si la posición esta fuera de rango no se puede
    if(pos<0 || pos>size){
        return false;
    }

    if (cabeza == nullptr && pos != 0) {
        return false;
    }

    Nodo *nuevo = new Nodo(n);

    //1er caso: si esta vacio
    if(this->cabeza == nullptr){
        this->cabeza=nuevo;
        size++;
        return true;
    }else if (pos == 0){
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        size++;
        return true;
    }else{
        Nodo *it = this->cabeza;
        int i = 0;

        while(i< pos-1 ){
            it = it->siguiente;
            i++;
        }

        nuevo->siguiente = it->siguiente;
        it->siguiente = nuevo;
        size++;
        return true;
    }

}

Nodo* listaEnlazadaSimple::getCabeza() const {
    return cabeza;
}

int listaEnlazadaSimple::getSize() const {
    return size;
}

bool listaEnlazadaSimple::borrar(int valor){


    return true;
}
