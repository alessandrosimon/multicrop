#include "imageoverlay.h"

ImageOverlay::ImageOverlay(QGraphicsItem *parent,
                           QGraphicsScene *parentScene,
                           int width, int height) :
    QGraphicsObject(parent),
    m_parentScene(parentScene),
    m_width(width),
    m_height(height)
{
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

void ImageOverlay::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    m_parentScene->removeItem(this);
}
void ImageOverlay::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
}

QRectF ImageOverlay::boundingRect() const
{
    return QRectF(0, 0, m_width, m_height);
}

QVariant ImageOverlay::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && scene()) {
            // value is the new position.
            QPointF newPos = value.toPointF();
            QRectF rect = scene()->sceneRect();
            if (!rect.contains(newPos)) {
                // Keep the item inside the scene rect.
                newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
                newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
                return newPos;
            }
        }
        return QGraphicsItem::itemChange(change, value);
}

void ImageOverlay::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget)
{
    painter->setRenderHint(QPainter::HighQualityAntialiasing, true);
    painter->setBrush(QColor(200, 0, 0, 150));
    painter->drawRect(this->boundingRect());
}
