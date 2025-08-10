#include "listaenlazadasimple.h"

listaEnlazadaSimple::listaEnlazadaSimple() {
    this->cabeza=nullptr;
}

bool listaEnlazadaSimple::insertarCola(int n, int pos){

    //si la posición esta fuera de rango no se puede
    if(pos<0 || pos>size){
        return false;
    }

    //para evitar que se coloque en una posición distinta cuando no hay nada o en un lugar que no hay
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
        //cuando ya hay algo pero se quiere poner en la cabeza
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        size++;
        return true;
    }else{
        //para colocar en cualquier lado o al final
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

    //si esta vacio
    if (cabeza==nullptr){
        return false;
    }

    Nodo *borrar;

    //si se quiere borrar la cabeza
    if(cabeza->valor==valor){
        borrar = cabeza;
        cabeza = cabeza->siguiente;
        delete borrar;
        size--;
        return true;

    }

        //si se quiere borrar en cualquier otra pos o al final
        Nodo *it = cabeza;
        while(it->siguiente!=nullptr){
            if(it->siguiente->valor==valor){
                borrar = it->siguiente;
                it->siguiente= borrar->siguiente;
                delete borrar;
                size--;
                return true;

            }
            it = it->siguiente;
        }
    return false;
}


int listaEnlazadaSimple::buscar (int valor){
    Nodo* it = cabeza;
    int pos = 0;
    while (it != nullptr) {
        if (it->valor == valor)
            return pos;
        it = it->siguiente;
        pos++;
    }
    return -1;
}



