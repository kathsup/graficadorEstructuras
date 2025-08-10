#include "nodeitem.h"
#include <QPainter>

nodeItem::nodeItem(const QString& val, bool isLast,QColor bgColor, QGraphicsItem* parent)
    :QGraphicsItem(parent), value(val), isLast(isLast),backgroundColor(bgColor) {}

QRectF nodeItem::boundingRect() const {
    return QRectF(0, 0, 120, 60); // área donde se puede dibujar
}

void nodeItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    // círculo
    painter->setBrush(backgroundColor);
    painter->setPen(QPen(Qt::black, 2));
    painter->drawEllipse(0, 0, 40, 40);

    // valor
    painter->setPen(Qt::black);
    painter->drawText(QRectF(0, 0, 40, 40), Qt::AlignCenter, value);

    // flecha
    if (!isLast) {
        QLineF line(40, 20, 100, 20);
        painter->drawLine(line);

        // cabeza de flecha
        QPointF arrowP1 = line.p2() - QPointF(10, 5);
        QPointF arrowP2 = line.p2() - QPointF(10, -5);
        QPolygonF arrowHead;
        arrowHead << line.p2() << arrowP1 << arrowP2;
        painter->setBrush(Qt::black);
        painter->drawPolygon(arrowHead);
    } else {
        painter->drawText(QPointF(100, 15), "null");
    }
}
