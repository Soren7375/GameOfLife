#ifndef GAME_CELL_H
#define GAME_CELL_H

#include <QObject>
#include <qtwidgets>

class Game_cell : public QGraphicsRectItem
{
   public:
    Game_cell(qreal x,qreal y,qreal w,qreal h,QGraphicsItem *patent =0);
    ~Game_cell();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void change_color();
};
#endif // GAME_CELL_H

