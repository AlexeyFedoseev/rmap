#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphicspixmapitem.h"
#include "city.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void openCityWindow(QPoint p);

private:
    Ui::MainWindow *ui;
    GraphicsPixmapItem* graphicsItem;
    QVector<City*> cities;
};

#endif // MAINWINDOW_H
