#include "answerwindow.h"
#include "ui_answerwindow.h"
#include <QObject>

AnswerWindow::AnswerWindow()
{
    Ui::Dialog ui;
    ui.setupUi(this);
}

AnswerWindow::~AnswerWindow()
{

}

AnswerWindow::preShow(int rightIndex, int checkId)
{
    if(rightIndex == checkId){
        QImage image("galochka.png");
        ui.label->setText("Ты ответил на вопрос правильно");

    }
    else {
        QImage image("krest.jpg");
        ui.label->setText("Ты ответил на вопрос неправильно");
    }
    ui.show();
}
