#include "city.h"
#include "ui_city.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>

City::City(int x, int y, QWidget *parent) :
    QDialog(parent)
{
    Ui::Dialog ui;
    ui.setupUi(this);
    //uiC->setupUi(this);
    QImage image(":/SUx182.jpg");
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsView* view = new QGraphicsView(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    //uiC->centralWidget->layout()->addWidget(view);

    rect = QRect(x-30, y-30, 60, 60);
}



City::~City()
{
    //delete uiC;
}

bool City::checkPoint(QPoint p)
{
    return rect.contains(p);
}
