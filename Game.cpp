#include "Game.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>

Game::Game(QWidget *parent)//開始遊戲
{
    QGraphicsScene *scene=new QGraphicsScene();//建立QGraphicsScene物件(場景)
    scene->setSceneRect(0,0,800,600);//設定scene的左上角座標及寬高
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));//設定背景(轉成QImage後，利用QBrush把背景塗上去)

    //讓scene視覺化
    setScene(scene);//將scene設定為可被看見的scene
    //避免畫面無限延伸，所以停用捲動功能(只是其中一種方法)
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);//設定畫面大小

    //要讓Item可以接受Key event，就要讓Item具有Active focus
    Player *player=new Player();//建立玩家物件
    player->setPos(400,500);//設定玩家起始位置
    player->setFlag(QGraphicsItem::ItemIsFocusable);//讓Item可具有active focus
    player->setFocus();//啟動focus

    scene->addItem(player);//將長方形加到場景內

    score=new Score();//建立分數物件
    scene->addItem(score);//將score加入場景
    health=new Health();//建立血量物件
    health->setPos(health->x(),health->y()+25);//調整血量顯示位置(避免與分數重疊)
    scene->addItem(health);//將health加入場景

    //生成敵人
    QTimer *timer=new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));//連結timer和生成敵人的slot
    timer->start(2000);//每兩秒生成一次

    //設定音樂
    QMediaPlayer *music=new QMediaPlayer();//建立QMediaPlayer物件(用來撥放音效)
    music->setMedia(QUrl("qrc:/sounds/Maple Story Music - Lith Harbor.mp3"));//設定背景音樂
    music->play();//撥放音樂

    show();//顯示視窗
}
