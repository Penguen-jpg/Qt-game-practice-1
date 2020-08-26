#include "Health.h"
#include <QFont>
Health::Health(QGraphicsTextItem *parent):QGraphicsTextItem(parent)//指定QGraphicsTextItem當他的parent
{
    //初始化血量
    health=3;
    //設定血量顯示
    setPlainText(QString("Health:")+QString::number(health));
    setDefaultTextColor(Qt::red);//設定字的顏色
    setFont(QFont("times",16));//設定字形
}

void Health::decrease()//扣血
{
    health--;
    setPlainText(QString("Health:")+QString::number(health));//顯示更新後的血量
}

int Health::getHealth()//取得血量
{
    return health;
}
