#ifndef ARROW_H
#define ARROW_H
#include <QQueue>
#include "sprite.h"
#include "arrowshape.h"

class GameScene;
class Arrow
{
public:
    Arrow();
    ~Arrow() {}
    void init();
private:
    enum Dir
    {
        UP = 0,
        DOWN,
        LEFT,
        RIGHT,
    };

    //Texture t;
    //Sprite s;
    //deque<ArrowShape> questions;

    Sprite m_sprite;
    QQueue<ArrowShape> m_questions;

    float m_frame;
    float m_frameSpeed;
    int m_frameLimit;
    int m_dir[4];// = { -90, 90, 180, 0 };

    bool checkArrow(int idx);
public:
    bool checkKey(bool left, bool right, bool up, bool down);
    void arrowSetting();
    void move(const int& speed, bool& isGameOver);
    void draw(GameScene* scene);
    ArrowShape getFirstArrowPos();
    void removeFirstArrow();
    bool isEmpty() const;
};

#endif // ARROW_H
