#include "pintor.h"

pintor::pintor(QGraphicsScene* scene) {
    this->scene = scene;
}

void pintor::dibujar(const listaEnlazadaSimple& lista) {
    scene->clear();

    int x = 50;
    int y = 100;
    int espacio = 120;

    Nodo* actual = lista.getCabeza();
    int i = 0;

    while (actual != nullptr) {
        bool esUltimo = (actual->siguiente == nullptr);
        nodeItem* nodoVisual = new nodeItem(QString::number(actual->valor), esUltimo);
        nodoVisual->setPos(x + i * espacio, y);
        scene->addItem(nodoVisual);

        actual = actual->siguiente;
        i++;
    }

    scene->setSceneRect(scene->itemsBoundingRect());
}
