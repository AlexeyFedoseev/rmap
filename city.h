#ifndef CITY_H
#define CITY_H

#include "question.h"
#include <QDialog>
#include <QRect>
#include <QPoint>

namespace CityN {
class City;
}

class City : public QDialog
{
    Q_OBJECT

public:
    City(int x, int y, QString name, const QVector<Question>& questions, QWidget *parent = 0);
    ~City();
    bool checkPoint(QPoint p);

private:
    CityN::City *uiC;
    QRect rect;
    QVector<Question> questions;
};

#endif // CITY_H
