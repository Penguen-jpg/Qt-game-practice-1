#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
class Bullet:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT;//要讓自訂的class能夠使用slot/signal，就要繼承QObject(宣告完記得重新建置，否則會編譯失敗)
    public:
        Bullet(QGraphicsItem *parent=0);
    public slots:
        void move();
};

#endif // BULLET_H
