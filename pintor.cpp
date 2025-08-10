#include "pintor.h"
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QGraphicsScene>

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

void pintor::dibujarConResaltado(const listaEnlazadaSimple &lista, int posResaltada)
{
    scene->clear();

    Nodo* it = lista.getCabeza();
    int i = 0;

    int x = 50;
    int y = 100;
    int espacio = 120;

    while(it != nullptr) {
        bool esUltimo = (it->siguiente == nullptr);
        QColor color = (i == posResaltada) ? QColorConstants::Svg::darkorange : Qt::white;
        nodeItem* nodoVisual = new nodeItem(QString::number(it->valor), esUltimo, color);
        nodoVisual->setPos(x + i * espacio, y);
        scene->addItem(nodoVisual);

        it = it->siguiente;
        i++;
    }

    scene->setSceneRect(scene->itemsBoundingRect());
}

