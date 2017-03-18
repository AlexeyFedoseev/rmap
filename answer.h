#ifndef ANSWER_H
#define ANSWER_H

#include <QObject>
#include <QString>

class Answer : public QObject
{
    Q_OBJECT

public:
    QString answerText;
    QString rightAnswerText;
    Answer(QWidget *parent = 0);
    ~Answer();

};
#endif // ANSWER_H
