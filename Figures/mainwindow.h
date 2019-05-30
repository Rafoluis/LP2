#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <vector>
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "circule.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_circle_clicked();

    void on_triangle_clicked();

    void on_square_clicked();

    void on_Draw_clicked();

protected:
    QPainter * painter;
    QPixmap * pixmap;
    QPen * pen;
    vector<figure*>dw;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
