#ifndef SPRITE_H
#define SPRITE_H

#include <QPixmap>
class GameScene;
class Sprite
{
public:
    Sprite();
    void setPosition(float x, float y);
    void setRotation(qreal angle);
    void setOriginPoint(QPointF point);
    QPointF position() const;
    void setPixmap(QPixmap pixmap);
    void draw(GameScene* gs);
    float height() const;
    float width() const;
    QPixmap pixmap() const;
    void move(float offsetX, float offsetY);
private:
    QPointF m_position;
    QPixmap m_pixmap;
    qreal m_angle;
    QPointF m_originPoint;
};


#endif // SPRITE_H
