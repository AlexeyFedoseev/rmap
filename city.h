#ifndef CITY_H
#define CITY_H

#include <QDialog>

namespace CityN {
class City;
}

class City : public QDialog
{
    Q_OBJECT

public:
    City(QWidget *parent = 0);
    ~City();

private:
    CityN::City *uiC;
};

#endif // CITY_H
