#ifndef ANSWERWINDOW_H
#define ANSWERWINDOW_H

#include <QWidget>
#include <QString>
#include "city.h"

namespace Ui {
class answerwindow;
}

class City;

class AnswerWindow : public QWidget
{
    Q_OBJECT
    Ui::answerwindow *ui;
public:
    AnswerWindow(City *city);
    ~AnswerWindow();
    void preShow(int rightIndex, int checkId);
public slots:
    void exitToMap();
   // void nextQuestion();
};

#endif // ANSWERWINDOW_H
