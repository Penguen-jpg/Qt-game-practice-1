#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/player.png"));//畫出玩家
    bullet_sound=new QMediaPlayer();
    bullet_sound->setMedia(QUrl("qrc:/sounds/Bullet_sound.mp3"));//設定子彈音效
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left)//當按下左方向鍵時，讓Item往左移
    {
        if(pos().x()>0)//檢查是否超出左邊邊界(小於0)
        {
            setPos(x()-10,y());
        }
    }else if(event->key()==Qt::Key_Right)//當按下右方向鍵時，讓Item往右移
    {
        if(pos().x()+100<800)//檢查是否超出右邊邊界(大於800)
        {
            setPos(x()+10,y());
        }
    }
    else if(event->key()==Qt::Key_Space)//當按下空白鍵時，射出長方形
    {
        Bullet *bullet=new Bullet();//建構子彈物件
        bullet->setPos(x(),y());//設定子彈初始位置
        scene()->addItem(bullet);//將子彈添加至場景中

        if(bullet_sound->state()==QMediaPlayer::PlayingState)//如果音效已撥放過，則將狀態還原為未撥放
        {
            bullet_sound->setPosition(0);
        }else if(bullet_sound->state()==QMediaPlayer::StoppedState)//如果音效沒撥放過，則撥放
        {
            bullet_sound->play();
        }
    }
}

void Player::spawn()//生成敵人
{
    Enemy *enemy=new Enemy();
    scene()->addItem(enemy);
}
