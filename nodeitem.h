#ifndef NODEITEM_H
#define NODEITEM_H
#include <QGraphicsItem>
#include <QString>

class nodeItem: public QGraphicsItem{
public:
    nodeItem(const QString& val, bool isLast, QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
    QString value;
    bool isLast;
};


#endif // NODEITEM_H
