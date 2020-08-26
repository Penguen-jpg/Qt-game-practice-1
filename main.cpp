#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include "Player.h"
#include <QTimer>
#include <QGraphicsView>
#include "Game.h"
Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game=new Game();//開始遊戲
    return a.exec();
}
