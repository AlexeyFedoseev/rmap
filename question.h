#ifndef QUESTION_H
#define QUESTION_H

#include "answer.h"
#include <QObject>
#include <QString>

class Question : public QObject
{
    Q_OBJECT

public:
    QString questionText;
    Question(QWidget *parent = 0);
    ~Question();

private:
    QVector<Answer*> answers;
};

#endif // QUESTION_H
