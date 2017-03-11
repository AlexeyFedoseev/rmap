#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QMouseEvent>

class Scene : public QGraphicsScene
{
    Q_OBJECT

    public:
    Scene(QWidget *parent = 0);
    ~Scene();
    void mousePressEvent(QMouseEvent *event);
    void openCityWindow(QMouseEvent *event);
};

#endif // SCENE_H
