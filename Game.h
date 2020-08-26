#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "Health.h"
class Game:public QGraphicsView
{
    public:
        Game(QWidget *parent=0);//加上這個參數代表可以自己決定要不要給他parent
        QGraphicsScene *scene;
        Player *player;
        Score *score;
        Health *health;
};

#endif // GAME_H
