#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "figure.h"
#include "circule.h"
#include "square.h"
#include "triangle.h"

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

void circule::draw(QPainter * painter)
{
    int r = rand() % 100 + 1;
    painter->drawEllipse({rand()%pixmap->width(), rand()%pixmap->height()}, r, r);
}

void square::draw(QPainter * painter)
{
    int r = rand() % 100 + 1;
    painter->drawRect(rand()%pixmap->width(), rand()%pixmap->height(), r, r);
}

void triangle::draw(QPainter * painter)
{
    int r = rand() % pixmap->width();
    int s = rand() % pixmap->height();
    QPolygon tri;
    tri << QPoint(r,r);
    tri << QPoint(r-s,r+s);
    tri << QPoint(r+s,r+s);
    painter->drawPolygon(tri);

}
MainWindow::~MainWindow()
{
    delete pixmap;
    delete pen;
    delete ui;
}

void MainWindow::on_circle_clicked()
{
    circule a;
    pixmap->fill();
    a.draw(painter);
    ui->label_draw_area->setPixmap(*pixmap);
}

void MainWindow::on_triangle_clicked()
{
    triangle b;
    pixmap->fill();
    b.draw(painter);
    ui->label_draw_area->setPixmap(*pixmap);
}

void MainWindow::on_square_clicked()
{
    square c;
    pixmap->fill();
    c.draw(painter);
    ui->label_draw_area->setPixmap(*pixmap);

}
