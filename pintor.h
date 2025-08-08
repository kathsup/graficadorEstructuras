#ifndef PINTOR_H
#define PINTOR_H
#include <QGraphicsScene>
#include "listaenlazadasimple.h"
#include "nodeitem.h"

class pintor
{
public:
    pintor(QGraphicsScene* scene);
    void dibujar(const listaEnlazadaSimple& lista);

private:
    QGraphicsScene* scene;
};

#endif // PINTOR_H
