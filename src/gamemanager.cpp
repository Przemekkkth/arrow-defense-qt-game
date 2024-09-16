#include "gamemanager.h"
#include "pixmapmanager.h"
#include <QTimer>

GameManager::GameManager()
    : defaultArrowSpeed(10)
{
    arrowSpeed = 10;
    isGameOver = false;
    isSleepGame = false;
    pArrow = new Arrow();
    state = NONE;

    imgWrong.setPixmap(PixmapManager::Instance()->getPixmap(PixmapManager::TextureID::Wrong));
    imgDeadLine.setPixmap(PixmapManager::Instance()->getPixmap(PixmapManager::TextureID::Line));
    imgDeadLine.setPosition(0, 90);

    imgWrong.setOriginPoint(QPointF(imgWrong.width() / 2, imgWrong.height() / 2));
    imgDeadLine.setOriginPoint(QPointF(imgDeadLine.width() / 2, imgDeadLine.height() / 2));
}

void GameManager::init()
{
    arrowSpeed = defaultArrowSpeed;
    pArrow->init();
}

void GameManager::checkKey(bool left, bool right, bool up, bool down)
{
    if (pArrow->isEmpty() || isGameOver) return;

    if (pArrow->checkKey(left, right, up, down))
    {
        //correct
        arrowSpeed++;
        firstArrowPos = pArrow->getFirstArrowPos();
        pArrow->removeFirstArrow();
        state = CORRECT;
    }
    else
    {
        //wrong
        firstArrowPos = pArrow->getFirstArrowPos();
        pArrow->removeFirstArrow();
        state = WRONG;
    }
}

void GameManager::move()
{
    if (!isGameOver) {
        pArrow->arrowSetting();
        pArrow->move(arrowSpeed, isGameOver);
    }
}

void GameManager::draw(GameScene* scene)
{
    switch (state)
    {
    case WRONG:
        //game over.
        state = NONE;
        imgWrong.setPosition(firstArrowPos.x, firstArrowPos.y);
        imgWrong.draw(scene);
        isGameOver = true;
        break;
    case CORRECT:
        //score up.
        state = NONE;
        break;
    }

    pArrow->draw(scene);
    if (isGameOver) {
        int yValue = firstArrowPos.y == 0 ? 110 : firstArrowPos.y;
        imgWrong.setPosition(firstArrowPos.x, yValue);
        imgWrong.draw(scene);
    }

    imgDeadLine.draw(scene);
}
void GameManager::checkGameOver()
{
    if (isGameOver && !isSleepGame)
    {
        isSleepGame = true;
        QTimer::singleShot(1500, [this]{
            isGameOver = false;
            isSleepGame = false;
            init();
        });
    }
}
