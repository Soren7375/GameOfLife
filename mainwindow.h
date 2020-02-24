#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>
#include "game_cell.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int x,int y);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_Timeout();

private:
    Ui::MainWindow *ui;
    int x;
    int y;
    int iterations;
    QTimer *timer;
    QVector< QVector<Game_cell*>>fills;
    QGraphicsScene * scene;
    void new_game();
    void start_game();
    int count(int pos_x,int pos_y);
    bool start_g = false;
};

#endif // MAINWINDOW_H
