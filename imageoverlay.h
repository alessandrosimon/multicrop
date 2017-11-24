#ifndef IMAGEOVERLAY_H
#define IMAGEOVERLAY_H

#include <QGraphicsObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtGui>
#include <QPointF>
#include <QGraphicsSceneDragDropEvent>
#include "mainwindow.h"

class ImageOverlay : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit ImageOverlay(QGraphicsItem *parent = 0, QGraphicsScene *parentScene = 0,
                          int width = 100, int height = 100);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;


private:
    QVariant itemChange(GraphicsItemChange change,
                            const QVariant &value);

    QPointF m_lastPos;
    int m_width;
    int m_height;
    QGraphicsScene* m_parentScene;

public slots:

};

#endif // IMAGEOVERLAY_H
