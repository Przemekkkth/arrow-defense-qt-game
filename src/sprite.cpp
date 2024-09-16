#include "sprite.h"
#include "gamescene.h"

Sprite::Sprite() {}

void Sprite::setPosition(float x, float y)
{
    m_position.setX(x);
    m_position.setY(y);
}

void Sprite::setRotation(qreal angle)
{
    m_angle = angle;
}

void Sprite::setOriginPoint(QPointF point)
{
    m_originPoint = point;
}

QPointF Sprite::position() const
{
    return m_position;
}

void Sprite::setPixmap(QPixmap pixmap)
{
    m_pixmap = pixmap;
}

void Sprite::draw(GameScene *gs)
{
    QGraphicsPixmapItem *pItem = new QGraphicsPixmapItem();
    pItem->setPixmap(m_pixmap);
    pItem->setTransformOriginPoint(m_originPoint);
    pItem->setPos(m_position);
    pItem->setRotation(m_angle);
    gs->addItem(pItem);
}

float Sprite::height() const
{
    return m_pixmap.height();
}

float Sprite::width() const
{
    return m_pixmap.width();
}

QPixmap Sprite::pixmap() const
{
    return m_pixmap;
}

void Sprite::move(float offsetX, float offsetY)
{
    setPosition(position().x() + offsetX, position().y() + offsetY);
}
