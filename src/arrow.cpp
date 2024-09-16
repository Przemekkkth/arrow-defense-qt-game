#include "arrow.h"
#include "utils.h"
#include "pixmapmanager.h"
#include <QDebug>

Arrow::Arrow() {
    //m_dir[4] = { -90, 90, 180, 0 };
    m_dir[0] = -90;
    m_dir[1] = 90;
    m_dir[2] = 180;
    m_dir[3] = 0;

    srand(static_cast<unsigned int>(time(nullptr)));

    m_sprite.setPixmap(PixmapManager::Instance()->getPixmap(PixmapManager::Arrow));
    m_sprite.setOriginPoint(QPointF(m_sprite.width() / 2.0, m_sprite.height() / 2.0));

    m_frame = 20.f;
    m_frameSpeed = 0.6f;
    m_frameLimit = 20;
}

void Arrow::init()
{
    m_questions.clear();
}

bool Arrow::checkArrow(int idx)
{
    if (m_questions.empty()) {
        return false;
    }

    if (idx == m_questions[0].direction) {
        qDebug() << "correct ";
        return true;
    }

    return false;
}

bool Arrow::checkKey(bool left, bool right, bool up, bool down)
{
    if (up) {
        return checkArrow(Dir::UP);
    }
    if (down) {
        return checkArrow(Dir::DOWN);
    }
    if (left) {
        return checkArrow(Dir::LEFT);
    }
    if (right) {
        return checkArrow(Dir::RIGHT);
    }
    return false;
}

void Arrow::arrowSetting()
{
    //check frame
    m_frame += m_frameSpeed;
    if (m_frame <= m_frameLimit) {
        return;
    }
    m_frame -= m_frameLimit;

    //check arrow number
    if (m_questions.size() > 10) {
        return;
    }

    ArrowShape as;

    int dirIdx = rand() % 4;
    as.direction = dirIdx;
    as.x = SCREEN::PHYSICAL_SIZE.width();
    as.y = 110;
    m_sprite.setPosition(as.x, as.y);

    m_questions.push_back(as);
}

void Arrow::move(const int& speed, bool& isGameOver)
{
    QQueue<ArrowShape>::iterator iter;
    for (iter = m_questions.begin(); iter != m_questions.end(); ++iter)
    {
        iter->x -= speed;
        if (iter->x <= 0)
        {
            //gameover;
            isGameOver = true;
            break;
        }
    }
}

void Arrow::draw(GameScene *scene)
{
    for (auto iter = m_questions.begin(); iter != m_questions.end(); ++iter)
    {
        m_sprite.setRotation(m_dir[iter->direction]);
        m_sprite.setPosition(iter->x, iter->y);
        m_sprite.draw(scene);
    }
}

ArrowShape Arrow::getFirstArrowPos()
{
    return m_questions[0];
}

void Arrow::removeFirstArrow()
{
    if (m_questions.empty()) {
        return;
    }
    m_questions.pop_front();
}

bool Arrow::isEmpty() const
{
    return m_questions.empty();
}
