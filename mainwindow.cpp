#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "city.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage image(":/karta_rossii.jpg");
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsView* view = new QGraphicsView(scene);
    graphicsItem = new GraphicsPixmapItem(QPixmap::fromImage(image));
    connect(graphicsItem, SIGNAL(pointClicked(QPoint)), this, SLOT(openCityWindow(QPoint)));
    scene->addItem(graphicsItem);
    ui->centralWidget->layout()->addWidget(view);

    QFile file("questions.txt");
    file.open(QIODevice::ReadOnly);
    QString cityName = file.read(27);
    City* spb = new City(372, 627, cityName);
    cities.push_back(spb);
}

MainWindow::~MainWindow()
{
    delete ui;
    for (QVector<City*>::iterator it = cities.begin(); it!=cities.end(); it++) {
        delete *it;
    }
}


void MainWindow::openCityWindow(QPoint p)
{
    for (QVector<City*>::iterator it = cities.begin(); it!=cities.end(); it++) {
        if ((*it)->checkPoint(p)) {
            (*it)->show();
            break;
        }
    }
}
