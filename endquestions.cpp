#include "endquestions.h"
#include "ui_endquestions.h"
#include <QWidget>

EndQuestions::EndQuestions(City* city) : ui(new Ui::EndQuestions)
{
    ui->setupUi(this);
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(hide()));
}

EndQuestions::~EndQuestions()
{

}
