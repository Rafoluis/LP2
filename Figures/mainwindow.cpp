#include "mainwindow.h"
#include "ui_mainwindow.h"

figure::~figure(){}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pixmap = new QPixmap(600, 400);
    pixmap->fill();

    pen = new QPen(QColor("black"));

    ui->label_draw_area->setPixmap(*pixmap);

    painter = new QPainter(pixmap);
    painter->setPen(*pen);
}

MainWindow::~MainWindow()
{
    delete pixmap;
    delete pen;
    delete ui;
    for(unsigned long long i=0;i<dw.size();i++){
        delete[] dw[i];
    }
}

void MainWindow::on_circle_clicked()
{
    int r = rand() % 100 + 1;
    dw.push_back(new circule(rand()%pixmap->width(), rand()%pixmap->height(),r));
}

void MainWindow::on_triangle_clicked()
{
    int a=rand()%pixmap->width();
    int b=rand()%pixmap->height();
    int c = rand()%100+1;
    dw.push_back(new triangle(a,b,c));
}

void MainWindow::on_square_clicked()
{
    int a = rand()%100+1;
    int b=rand()%pixmap->width();
    int c=rand()%pixmap->height();

    dw.push_back(new square(a,b,c));
}

void MainWindow::on_Draw_clicked()
{
    pixmap->fill();
    for(unsigned long long i=0; i<dw.size();i++){
        dw[i]->draw(painter);
    }
    ui->label_draw_area->setPixmap(*pixmap);

}
