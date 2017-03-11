#include "scene.h"
#include "city.h"
#include "mainwindow.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QWidget>

Scene::Scene(QWidget *parent) : QGraphicsScene(parent)
{

}

Scene::~Scene()
{

}

void Scene::mousePressEvent(QMouseEvent *event)
{
    qDebug() << event->x();
    qDebug() << event->y();
    openCityWindow(event);
}

void Scene::openCityWindow(QMouseEvent *event)
{
    City c;
    if(event->x() <= 391 && event->x() >= 375 && event->y() <= 658 && event->y() >= 645){
        c.show();
    }
}
