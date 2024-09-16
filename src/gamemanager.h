#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <QObject>
#include "arrow.h"
#include "sprite.h"

class GameScene;
class GameManager
{
private:
    enum GameState
    {
        NONE,
        CORRECT,
        WRONG,
    };
    int arrowSpeed;
    const int defaultArrowSpeed;
    bool isGameOver;
    bool isSleepGame;
    Arrow* pArrow;


    Sprite imgWrong;
    Sprite imgDeadLine;
    GameState state;
    ArrowShape firstArrowPos;
public:
    GameManager();

    void init();

    void checkKey(bool left, bool right, bool up, bool down);

    void move();

    void draw(GameScene* scene);
    void checkGameOver();
};

#endif // GAMEMANAGER_H
