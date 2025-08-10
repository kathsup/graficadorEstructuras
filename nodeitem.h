#ifndef NODEITEM_H
#define NODEITEM_H
#include <QGraphicsItem>
#include <QString>
#include <QColor>

class nodeItem: public QGraphicsItem{
public:
    nodeItem(const QString& val, bool isLast,QColor bgColor = Qt::white, QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
    QString value;
    bool isLast;
    QColor backgroundColor = Qt::white;
};


#endif // NODEITEM_H
