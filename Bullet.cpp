#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
extern Game *game;//有個全域Game物件

Bullet::Bullet(QGraphicsItem *parent):QGraphicsPixmapItem(parent)//建構子
{
    setPixmap(QPixmap(":/images/bullet.png"));//畫出子彈
    QTimer *timer=new QTimer();//建構QTimer物件(用來控制子彈移動的時間間隔)
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));//連結timer跟move
    timer->start(50);//每隔50ms啟動timeout
}

void Bullet::move()//移動子彈
{
    //當子彈打到敵人時，同時刪除子彈跟敵人
    QList<QGraphicsItem *> colliding_items=collidingItems();//所有碰撞物品形成的list
    for(int n=0;n<colliding_items.size();n++)//檢查是否有打到的敵人
    {
        if(typeid(*colliding_items[n])==typeid(Enemy))//當碰撞到的物品跟是敵人時，則刪除子彈和敵人
        {
            game->score->increase();//加分
            //從場景中刪除
            scene()->removeItem(colliding_items[n]);//敵人
            scene()->removeItem(this);//子彈
            //從記憶體中刪除
            delete colliding_items[n];
            delete this;
            return;//做完就終止，避免被下方的程式碼再刪除第二次(因為動到已經被刪除的記憶體會讓程式當掉)
        }
    }
    setPos(x(),y()-10);//移動射出的子彈
    if(pos().y()<0)//當射出的子彈超出視窗範圍，則刪除該子彈物件
    {
        scene()->removeItem(this);//從場景中移除物件
        delete this;//刪除該子彈物件
    }
}
