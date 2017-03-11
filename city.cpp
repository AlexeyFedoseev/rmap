#include "city.h"
#include "ui_city.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>

City::City(QWidget *parent) :
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
}

City::~City()
{
    //delete uiC;
}
