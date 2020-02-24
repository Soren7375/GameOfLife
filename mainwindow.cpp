#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int x,int y) : x(x),y(y),iterations(0),scene(NULL),
    QMainWindow(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(on_Timeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    new_game();
}

void MainWindow::new_game()
{
    if(scene == NULL)
    {

        scene = new QGraphicsScene(0,0,ui->graphicsView->viewport()->width(),ui->graphicsView->viewport()->height());
    fills.resize((x));
    for(int i = 0; i < x; i++)
    {
        fills[i].resize(y);
        for(int j = 0; j < y; j++)
        {
            Game_cell * rec = new Game_cell(0,0,scene->sceneRect().width()/(x),scene->sceneRect().height()/(y));
            scene->addItem(rec);
            rec->setPos(0 + i*scene->width()/(x),0+ j*scene->height()/(y));
            fills[i][j] = rec;
        }
    }
    }
    else
    {
        iterations = 0;
        timer->stop();
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
            {
                fills[i][j]->setBrush(QBrush(Qt::white));
            }
    }
    ui->graphicsView->setScene(scene);
    start_g = false;
    ui->pushButton_3->setText("Start");
}



void MainWindow::start_game()
{
        int neb = 0;
        QVector<Game_cell*> fill_temp;
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
            {

                neb=count(i,j);

                       if(fills[i][j]->brush().color() == Qt::white && neb == 3)
                        {

                            fill_temp.push_back(fills[i][j]);
                        }
                       if(fills[i][j]->brush().color() == Qt::black && (neb > 3 || neb < 2))
                        {

                            fill_temp.push_back(fills[i][j]);
                        }

            }
        QVector< Game_cell* >::iterator it = fill_temp.begin();
        for(;it != fill_temp.end();it++)
            (*it)->change_color();
            iterations++;
        if(fill_temp.count() != 0)
            ui->statusBar->showMessage(QString().setNum(iterations));
}


int MainWindow::count(int pos_x,int pos_y)
{
    int i,j,temp_i,temp_j;
    int result = 0;
    for(i = pos_x-1; i<=pos_x+1; i++)
    {
        temp_i = i;
        if(i == -1)
            temp_i = x-1;
        else if(i==x)
            temp_i =0;
        for(j = pos_y -1;j<= pos_y+1;j++)
        {
            temp_j = j;
            if(j == -1)
                temp_j = y-1;
            else if(j==y)
                temp_j =0;
            if(fills[temp_i][temp_j]->brush().color() == Qt::black && !(temp_i == pos_x && temp_j == pos_y))
               result++;
       }
    }


    return result;
}

void MainWindow::on_pushButton_2_clicked()
{
    start_game();
}

void MainWindow::on_Timeout()
{
    start_game();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(!start_g)
    {
        start_g = true;
        ui->pushButton_3->setText("Stop");
        timer->start(350);
    }
    else
    {
        start_g = false;
        ui->pushButton_3->setText("Start");
    timer->stop();
    }
}
