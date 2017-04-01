#include "answerwindow.h"
#include "city.h"
#include "ui_answerwindow.h"
#include <QWidget>

AnswerWindow::AnswerWindow(City* city) : ui(new Ui::answerwindow)
{
    ui->setupUi(this);
    //connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitToMap()));
    connect(ui->nextButton, SIGNAL(clicked()), city, SLOT(nextQuestion()));
}

AnswerWindow::~AnswerWindow()
{

}

void AnswerWindow::preShow(int rightIndex, int checkId)
{
    if(rightIndex == checkId){
        QImage image(":/galochka.png");
        ui->label->setText("Ты ответил на вопрос правильно");

    }
    else {
        QImage image(":/krest.jpg");
        ui->label->setText("Ты ответил на вопрос неправильно");
    }
    show();
}

void AnswerWindow::exitToMap()
{

}
