#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>
#include <QString>

class Question : public QObject
{
    Q_OBJECT

public:
    QString questionText;
    Question(QObject *parent = 0);
    ~Question();

private:
    QVector<QString*> answers;
};

#endif // QUESTION_H
