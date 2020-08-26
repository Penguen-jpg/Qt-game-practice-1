#include "Score.h"
#include <QFont>

Score::Score(QGraphicsTextItem *parent):QGraphicsTextItem(parent)//指定QGraphicsTextItem當他的parent
{
    //初始化分數
    score=0;
    //設定分數顯示
    setPlainText(QString("Score:")+QString::number(score));
    setDefaultTextColor(Qt::blue);//設定字的顏色
    setFont(QFont("times",16));//設定字形
}

void Score::increase()//加分
{
    score++;
    setPlainText(QString("Score:")+QString::number(score));//顯示更新過後的分數
}

int Score::getScore()//取得分數
{
    return score;
}
