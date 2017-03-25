#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>
#include <QString>
#include <QVector>

class Question
{

public:
    QString questionText;
    Question(QString text);
    Question();
    ~Question();
    void addAnswer(QString text, bool correct);
    QVector<QString> answers;
    int rightIndex;
};

#endif // QUESTION_H
