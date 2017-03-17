#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "city.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage image(":/karta_rossii.jpg");
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsView* view = new QGraphicsView(scene);
    graphicsItem = new GraphicsPixmapItem(QPixmap::fromImage(image));
    connect(graphicsItem, SIGNAL(pointClicked(QPoint)), this, SLOT(openCityWindow(QPoint)));
    scene->addItem(graphicsItem);
    ui->centralWidget->layout()->addWidget(view);

    City* spb = new City(372, 627, 0);
    cities.push_back(spb);
    /*City* yar = new City(448, 794);
    cities.push_back(yar);
    City* mos = new City(377, 840);
    cities.push_back(mos);
    City* tula = new City(339, 896);
    cities.push_back(tula);
    City* nnov = new City(488, 902);
    cities.push_back(nnov);
    City* ryaz = new City(403, 914);
    cities.push_back(ryaz);
    City* lip = new City(336, 954);
    cities.push_back(lip);
    City* vor = new City(318, 1001);
    cities.push_back(vor);
    City* penz = new City(449, 1006);
    cities.push_back(penz);
    City* rnd = new City(222, 1119);
    cities.push_back(rnd);
    City* volg = new City(372, 1140);
    cities.push_back(volg);
    City* sev = new City(49, 1099);
    cities.push_back(sev);
    City* krasnodar = new City(181, 1172);
    cities.push_back(krasnodar);
    City* ast = new City(382, 1266);
    cities.push_back(ast);
    City* sar = new City(463, 1094);
    cities.push_back(sar);
    City* ulyan = new City(529, 1020);
    cities.push_back(ulyan);
    City* kazan = new City(572, 981);
    cities.push_back(kazan);
    City* sam = new City(567, 1078);
    cities.push_back(sam);
    City* tol = new City(576, 1053);
    cities.push_back(tol);
    City* ncheln = new City(619, 1001);
    cities.push_back(ncheln);
    City* oren = new City(613, 1170);
    cities.push_back(oren);
    City* ijev = new City(675, 964);
    cities.push_back(ijev);
    City* ufa = new City(688, 1066);
    cities.push_back(ufa);
    City* perm = new City(755, 963);
    cities.push_back(perm);
    City* chelyab = new City(788, 1127);
    cities.push_back(chelyab);
    City* ekb = new City(821, 1032);
    cities.push_back(ekb);
    City* tyum = new City(941, 1082);
    cities.push_back(tyum);
    City* omsk = new City(1056, 1194);
    cities.push_back(omsk);
    City* novos = new City(1239, 1232);
    cities.push_back(novos);
    City* barn = new City(1242, 1321);
    cities.push_back(barn);
    City* tomsk = new City(1288, 1165);
    cities.push_back(tomsk);
    City* kemer = new City(1329, 1220);
    cities.push_back(kemer);
    City* novok = new City(1348, 1280);
    cities.push_back(novok);
    City* krasnoyarsk = new City(1474, 1218);
    cities.push_back(krasnoyarsk);
    City* irkutsk = new City(1722, 1347);
    cities.push_back(irkutsk);
    City* habar = new City(2453, 1279);
    cities.push_back(habar);
    City* vdvk = new City(2463, 1477);
    cities.push_back(vdvk);*/
}

MainWindow::~MainWindow()
{
    delete ui;
    for (QVector<City*>::iterator it = cities.begin(); it!=cities.end(); it++) {
        delete *it;
    }
}


void MainWindow::openCityWindow(QPoint p)
{
    for (QVector<City*>::iterator it = cities.begin(); it!=cities.end(); it++) {
        if ((*it)->checkPoint(p)) {
            (*it)->show();
            break;
        }
    }
}
