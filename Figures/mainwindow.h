#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>

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

protected:
    QPainter * painter;
    QPixmap * pixmap;
    QPen * pen;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
