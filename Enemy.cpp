#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "Game.h"
extern Game *game;

Enemy::Enemy(QGraphicsItem *parent):QGraphicsPixmapItem(parent)//建構子
{
    int random=rand()%700;//敵人的x座標(隨機生成)
    setPos(random,0);//設定敵人生成位置
    setPixmap(QPixmap(":/images/enemy.png"));//畫出敵人
    QTimer *timer=new QTimer();//建構QTimer物件(用來控制子彈移動的時間間隔)
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));//連結timer跟move
    timer->start(50);//每隔50ms啟動timeout
}

void Enemy::move()//移動子彈
{
    setPos(x(),y()+5);//移動敵人
    if(pos().y()>600)//當敵人超出視窗範圍，則刪除該敵人物件
    {
        game->health->decrease();//扣血
        scene()->removeItem(this);//從場景中移除物件
        delete this;//刪除該敵人物件
    }
}
