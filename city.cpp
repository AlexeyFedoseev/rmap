#include "city.h"
#include "ui_city.h"
#include "question.h"
#include "answerwindow.h"
#include "endquestions.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QPushButton>

City::City(int x, int y, QString name, const QVector<Question> &questions, QWidget *parent) :
    QDialog(parent), questions(questions), ui(new Ui::Dialog)
{
    //Ui::Dialog ui;
    ui->setupUi(this);
    QImage image(":/SUx182.jpg");
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    rect = QRect(x-10, y-10, 20, 20);

    ui->cityName->setText(name);
    ui->quest->setText(questions[questionNumber].questionText);
    ui->var1->setText(questions[questionNumber].answers[0]);
    ui->var2->setText(questions[questionNumber].answers[1]);
    ui->var3->setText(questions[questionNumber].answers[2]);
    ui->var4->setText(questions[questionNumber].answers[3]);

    eq = new EndQuestions(this);
    aw = new AnswerWindow(this);
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(showAnswer()));

    for (int i = 0; i<questions.size(); i++){
        qDebug() << questions[i].answers;
    }
}



City::~City()
{
    delete aw;
}

bool City::checkPoint(QPoint p)
{
    return rect.contains(p);
}

void City::showAnswer()
{
    int checkId = 5;
    if(ui->var1->isChecked()){
        checkId = 0;
    }
    if(ui->var2->isChecked()){
        checkId = 1;
    }
    if(ui->var3->isChecked()){
        checkId = 2;
    }
    if(ui->var4->isChecked()){
        checkId = 3;
    }
    aw->preShow(questions[questionNumber].rightIndex, checkId);
}

void City::nextQuestion()
{
    aw->hide();
    questionNumber++;
    if(questionNumber < questions.size()){
        ui->quest->setText(questions[questionNumber].questionText);
        ui->var1->setText(questions[questionNumber].answers[0]);
        ui->var2->setText(questions[questionNumber].answers[1]);
        ui->var3->setText(questions[questionNumber].answers[2]);
        ui->var4->setText(questions[questionNumber].answers[3]);
    }
    else{
        complete = true;
        eq->show();
        hide();
    }
}

void City::exitToMap()
{
    questionNumber++;
    hide();
}
