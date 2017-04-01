#ifndef ANSWERWINDOW_H
#define ANSWERWINDOW_H

#include <QObject>
#include <QString>
#include <QVector>

class AnswerWindow : public QObject
{
    Q_OBJECT

public:
    AnswerWindow();
    ~AnswerWindow();
    preShow(int rightIndex, int checkId);
};

#endif // ANSWERWINDOW_H
