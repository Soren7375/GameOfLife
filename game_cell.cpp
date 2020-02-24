#include "game_cell.h"

Game_cell::Game_cell(qreal x,qreal y,qreal w,qreal h,QGraphicsItem *patent):QGraphicsRectItem(x,y,w,h,patent)
{
    this->setBrush(QBrush(Qt::white));
}

Game_cell::~Game_cell()
{}

void Game_cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    change_color();
}

void Game_cell::change_color()
{
    if(this->brush().color() == Qt::white)
    {
        this->setBrush(QBrush(Qt::black));
    }
    else
    {
        this->setBrush(QBrush(Qt::white));
    }
}
