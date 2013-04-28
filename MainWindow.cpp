#include "MainWindow.h"
#include "abstract.h"
#include "bird.h"
#include "blue.h"
#include "cloud.h"
#include "plane.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <QFormLayout>
#include <QIntValidator>
#include <QColor>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <sstream>
#include <string>
#include <QString>

void MainWindow:: newGameClicked() {
    scene->clear();
    timer->start();
    points=0;
    //cout << "hi" << endl;
    showlives = new QLabel(view);
    showlives->setText("Lives");
    showlives->setGeometry(800, 650, 60, 30);
    score = new QLabel(view);
    score->setText("Score:");
    score->setGeometry(950, 650, 60, 30);
    //num = new QLabel(view);
    //num->setText("100");
    //num->setGeometry(975, 650, 60, 30);
    cloud = new QPixmap("cloudfix.png");
    Cloud *c = new Cloud(0, 0, cloud, this, scene);
    QGraphicsPixmapItem *cc = new QGraphicsPixmapItem(*cloud);
    cc->setX(500);
    cc->setY(200);
    cc->setScale(.25);
    scene->addItem(cc);
    Cloud *x = new Cloud(0, 0, cloud, this, scene);
    QGraphicsPixmapItem *c2= new QGraphicsPixmapItem(*cloud);
    c2->setX(700);
    c2->setY(200);
    c2->setScale(.25);
    scene->addItem(c2);
    clouds.push_back(x);
    clouds.push_back(c);
    life = new QPixmap("balloonfix.png");
    //cout << "one " << endl;
    l1= new QGraphicsPixmapItem(*life);
    l1->setScale(.1);
    l1->setX(175);
    l1->setY(750);
    scene->addItem(l1);
    l2= new QGraphicsPixmapItem(*life);
    l2->setScale(.1);
    l2->setX(200);
    l2->setY(750);
    //cout << "two " << endl;
    scene->addItem(l2);
    l3= new QGraphicsPixmapItem(*life);
    l3->setScale(.1);
    l3->setX(225);
    l3->setY(750);
    //cout << "three " << endl;
    scene->addItem(l3);
    //cout << "four" << endl;
}
void MainWindow:: Pause() {
    if (timer->isActive()==true) {
    	pause->setText("Resume");
        timer->stop();
    }
    else {
    	pause->setText("Pause");
        timer->start();
    }
}
void MainWindow:: mainWindowloselife(Abstract *a) {
     //a->loseLife();
    scene->removeItem(a);
    objects--;
    loseLife();
}
void MainWindow:: handleTimer() {
//score->show();
//item->move( WINDOW_MAX_X, WINDOW_MAX_Y );
    counter++;
    //cout << "Counter" << counter <<endl;

    for (unsigned int i=0; i<birds.size(); i++) {
    
        birds[i]->move(WINDOW_MAX_X, WINDOW_MAX_Y);
       
    }
    for (unsigned int i=0; i<blues.size(); i++) {
     blues[i]->move(WINDOW_MAX_X, WINDOW_MAX_Y);
        }
        for (unsigned int i=0; i<planes.size(); i++) {
        planes[i]->move(WINDOW_MAX_X, WINDOW_MAX_Y);
        }
    // std::cout << counter << std::endl;
    if (counter%1000==0) {
    cout << "bird" << endl;
        int x = rand() %1000 + 250;
        int y = rand() %750 + 200;
        //cout << "HI"<< endl;
        bird = new QPixmap("birdfix.png");
        //bird->setPos(50, 50);  
        QGraphicsPixmapItem *bb = new QGraphicsPixmapItem(*bird);
        Bird *b = new Bird(x, y, bird, this, scene, bb);
        bb->setScale(.15);
        bb->setPos(x, y);
        scene->addItem(bb);
        birds.push_back(b);
cout << "bird" << endl;
    }
    if (counter%500==0) {
    cout << "blue" << endl;
        int x = rand() %1000 + 250 ;
        int y = 750;
        blue = new QPixmap("balloonfix.png");
        QGraphicsPixmapItem *bb = new QGraphicsPixmapItem(*blue);
        Blue *b = new Blue(x, y, blue, this, scene, bb);
        bb->setScale(.15);
        bb->setPos(x,y);
        scene->addItem(bb);
        blues.push_back(b);
        cout << "blue" << endl;
    }
    if (counter%1000==0) {
    cout << "plane" << endl;
        int x = rand() %1000 + 250 ;
        int y = rand() %750 + 200;
        plane = new QPixmap("planefix.png");
        QGraphicsPixmapItem *bb = new QGraphicsPixmapItem(*plane);
        Plane *b = new Plane(x, y, plane, this, scene, bb);
        bb->setScale(.1);
        bb->setPos(x, y);
        scene->addItem(bb);
        planes.push_back(b);
        cout << "plane" << endl;
    }/*
    if (counter%1500==0){
    cout << "HI"<< endl;
    	bird = new QPixmap("bird.jpeg");
    //bird->setPos(50, 50);
    Bird *b = new Bird(50, 50, bird, this);
    QGraphicsPixmapItem *bb = new QGraphicsPixmapItem(*bird);
    bb->setScale(.15);
    bb->setPos(100, -100);
    //bb->setX(150);
    //bb->setY(50);
    scene->addItem(bb);
    objects.push_back(b);
    }*/
}
void MainWindow::gameOver() {

}
void MainWindow:: loseLife() {
    lives=lives-1;
    if (lives==0) {
        scene->removeItem(l1);
        gameOver();
    }
    if (lives ==1) {
        scene->removeItem(l2);
    }
    if (lives ==2) {
        scene->removeItem(l3);
    }
}
MainWindow::MainWindow() {
    lives=3;
    counter=0;
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    scene->setBackgroundBrush(QColor(173,216,250));
    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X*2.5, WINDOW_MAX_Y*2.5 );
    view->setWindowTitle( "Balloon Blast");
    scene->setSceneRect(450, 325, 450, 325);
    //view->setAlignment( Qt::AlignLeft | Qt::AlignTop );
    
    //This is how we do animation. We use a timer with an interval of 5 milliseconds
    //We connect the signal from the timer - the timeout() function to a function
    //of our own - called handleTimer - which is in this same MainWindow class

    //bird->addItem(view);
    //cloud = new QPixmap();
    // Cloud *c = new Cloud(50,100,cloud);
    //blue = new QPixmap();
    //Blue *b = new Blue(50, 150, blue);
    timer = new QTimer(this);
    timer->setInterval(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    quit = new QPushButton(view);
    quit->setText("Quit");
    quit->setGeometry(10, 170, 60, 30);
    pause = new QPushButton(view);
    pause->setText("Pause");
    pause->setGeometry(10, 130, 60, 30);
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    button = new QPushButton(view);
    button->setText("Start");
    button->setGeometry(10, 90, 60, 30);
    connect(button, SIGNAL(clicked()), this, SLOT(newGameClicked()));
    connect(pause, SIGNAL(clicked()), this, SLOT(Pause()));
    QRect rect(0, 0, 0, 0);
    QFormLayout *formlayout = new QFormLayout(view);
    formlayout->setGeometry(rect);
    user = new QLineEdit(view);
    formlayout->addRow(tr("Enter User Name: "), user);
}
void MainWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
    //This is how we get our view displayed.
    view->show();
}
/**destructor to delete appropriate values

@pre none, internally called
@post scene and view memory freed
@param none
@return none
*/
MainWindow::~MainWindow()
{
    //timer->stop();
    //delete timer;
    delete scene;
    delete view;
}
