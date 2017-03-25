#include "city.h"
#include "ui_city.h"
#include "question.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>

City::City(int x, int y, QString name, const QVector<Question> &questions, QWidget *parent) :
    QDialog(parent), questions(questions)
{
    Ui::Dialog ui;
    ui.setupUi(this);
    QImage image(":/SUx182.jpg");
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    rect = QRect(x-30, y-30, 60, 60);

    ui.label->setText(name);
    ui.label_2->setText(questions[0].questionText);
    int checkId;
    ui.radioButton->setText(questions[0].answers[0]);
    if(ui.radioButton->isChecked()){
        checkId = 0;
    }
    ui.radioButton_2->setText(questions[0].answers[1]);
    if(ui.radioButton_2->isChecked()){
        checkId = 1;
    }
    ui.radioButton_3->setText(questions[0].answers[2]);
    if(ui.radioButton_3->isChecked()){
        checkId = 2;
    }
    ui.radioButton_4->setText(questions[0].answers[3]);
    if(ui.radioButton_4->isChecked()){
        checkId = 3;
    }

    if(questions[0].rightIndex == checkId) {

    }
    for (int i = 0; i<questions.size(); i++){
        qDebug() << questions[i].answers;
    }
}



City::~City()
{
    //delete uiC;
}

bool City::checkPoint(QPoint p)
{
    return rect.contains(p);
}
