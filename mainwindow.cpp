#include "MainWindow.h"
#include "abstract.h"
#include "bird.h"
#include "blue.h"
#include "cloud.h"
#include "plane.h"
#include "Powerup.h"
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
#include <QMessageBox>
#include <boost/lexical_cast.hpp>


void MainWindow:: newGameClicked() {
    if (user->text()=="") {

    }
    else {
        name=new QLabel(view);
        name->setText("Player: "+user->text());
        name->setGeometry(25, 400, 100, 30 );
        timer->start();
        button->setEnabled(false);
        restart->setEnabled(true);
        points=0;
        showlives = new QLabel(view);
        showlives->setText("Lives");
        showlives->setGeometry(25, 620, 60, 30);
        score = new QLabel(view);
        score->setText("Score:");
        score->setGeometry(25, 500, 60, 30);
        string s = boost::lexical_cast<string>(points);
        QString str= QString::fromStdString(s);
        showpts = new QLabel(view);
        showpts->setGeometry(25, 540, 30, 30);
        showpts->setText(str);
        //num = new QLabel(view);
        //num->setText("100");
        //num->setGeometry(975, 650, 60, 30);
        cloud = new QPixmap("cloudfix.png");
        f = new Cloud(200, 200, cloud, this, scene);
        scene->addItem(f);
        g = new Cloud(450, 300, cloud, this, scene);
        scene->addItem(g);
        h = new Cloud(800, 200, cloud, this, scene);
        scene->addItem(h);
        i = new Cloud(650, 200, cloud, this, scene);
        scene->addItem(i);
        clouds.push_back(f);
        clouds.push_back(g);
        clouds.push_back(h);
        clouds.push_back(i);
        life = new QPixmap("balloonfix.png");
        l1= new QGraphicsPixmapItem(*life);
        l1->setScale(.1);
        l1->setX(125);
        l1->setY(730);
        scene->addItem(l1);
        l2= new QGraphicsPixmapItem(*life);
        l2->setScale(.1);
        l2->setX(150);
        l2->setY(730);
        scene->addItem(l2);
        l3= new QGraphicsPixmapItem(*life);
        l3->setScale(.1);
        l3->setX(175);
        l3->setY(730);
        scene->addItem(l3);

    }
}
void MainWindow:: changeEverything(Abstract *a, int x, int y) {
    e=new Powerup(x, y, powerup, this, scene);

}
void MainWindow:: Restart() {
    button->setEnabled(false);
    lives=3;
    birds.clear();
    clouds.clear();
    planes.clear();
    blues.clear();
    counter=0;
    timer->stop();
    scene->clear();
    timer->start();
    delete showpts;
    points=0;
    showlives = new QLabel(view);
    showlives->setText("Lives");
    showlives->setGeometry(25, 620, 60, 30);
    //cout << "one" << endl;
    score = new QLabel(view);
    score->setText("Score:");
    score->setGeometry(25, 500, 60, 30);
    string s = boost::lexical_cast<string>(points);
    QString str= QString::fromStdString(s);
    showpts = new QLabel(view);
    showpts->setGeometry(25, 540, 30, 30);
    //cout << "one" << endl;
    showpts->setText(str);
    cloud = new QPixmap("cloudfix.png");
    f = new Cloud(200, 200, cloud, this, scene);
    //cout << "one" << endl;
    scene->addItem(f);
    g = new Cloud(450, 300, cloud, this, scene);
    scene->addItem(g);
    h = new Cloud(800, 200, cloud, this, scene);
    scene->addItem(h);
    i = new Cloud(650, 200, cloud, this, scene);
    scene->addItem(i);
    clouds.push_back(f);
    cout << "one" << endl;
    clouds.push_back(g);
    clouds.push_back(h);
    clouds.push_back(i);
    life = new QPixmap("balloonfix.png");
    l1= new QGraphicsPixmapItem(*life);
    l1->setScale(.1);
    l1->setX(125);
    l1->setY(730);
    scene->addItem(l1);
    l2= new QGraphicsPixmapItem(*life);
    l2->setScale(.1);
    l2->setX(150);
    l2->setY(730);
    cout << "one" << endl;
    scene->addItem(l2);
    l3= new QGraphicsPixmapItem(*life);
    l3->setScale(.1);
    l3->setX(175);
    l3->setY(730);
    scene->addItem(l3);
    cout << "one" << endl;
}
void MainWindow:: Pause() {
    if (counter==0) {
        return;
    }

    if (timer->isActive()==true) {
        pause->setText("Resume");
        timer->stop();
    }
    else {
        pause->setText("Pause");
        timer->start();
    }
}

void MainWindow:: getPoints(Abstract *a) {
    delete showpts;
    scene->removeItem(a);
    points=points+10;
    string s = boost::lexical_cast<string>(points);
    QString str= QString::fromStdString(s);
    showpts = new QLabel(view);
    showpts->setGeometry(25, 540, 30, 30);
    showpts->setText(str);
}
void MainWindow:: getBonusPoints(Abstract *a) {
    delete showpts;
    scene->removeItem(a);
    //delete a;
    points=points+100;
    string s = boost::lexical_cast<string>(points);
    QString str= QString::fromStdString(s);
    showpts = new QLabel(view);
    showpts->setGeometry(25, 540, 30, 30);
    showpts->setText(str);
}
void MainWindow:: checkCollision() {
//cout << "bird size: " << birds.size() << endl;
//cout << "balloon size: " << blues.size() << endl;
    for (unsigned int i=0; i<blues.size(); i++) {
        for (unsigned int j=0; j<birds.size(); j++) {    
            if (blues[i]->collidesWithItem(birds[j], Qt::IntersectsItemShape) && blues[i]->getY()>0) {
            //cout << "i: "<<i << endl;
            //cout << "j: "<<j << endl;
                //scene->removeItem(blues[i]);
                loseLife(blues[i]);
                delete blues[i];
                blues.erase(blues.begin()+i); 
                //cout << "collision" << endl;
                
                return;
            }
        }
    }
}

void MainWindow:: level2() {
    scene->clear();

}
void MainWindow:: handleTimer() {	
   
    counter++;
    name->show();
    score->show();
    showlives->show();
//cout << "one" << endl;
    showpts->show();
    checkCollision();
    if (lives==3 && counter % 100 == 0) {
        f->moveright();
        g->moveright();
        h->moveright();
        i->moveright();
    }
    if (lives==3 && counter % 151 == 0) {
        f->moveleft();
        g->moveleft();
        h->moveleft();
        i->moveleft();
    }
    if (lives==2 && counter % 100 == 0) {
        j->moveright();
        k->moveright();
        l->moveright();
        m->moveright();
    }
    if (lives==2 && counter % 151 == 0) {
        j->moveleft();
        k->moveleft();
        l->moveleft();
        m->moveleft();
    }
    if (lives==1 && counter % 100 == 0) {
        r->moveright();
        o->moveright();
        p->moveright();
        q->moveright();
    }
    if (lives==1 && counter % 151 == 0) {
        r->moveleft();
        o->moveleft();
        p->moveleft();
        q->moveleft();
    }
    
    if (points>=50)
    {   
        for (unsigned int i=0; i<birds.size(); i++) {
            if (birds[i]->getX()>1200){
            	//scene->removeItem(birds[i]);
            	delete birds[i];
            	birds.erase(birds.begin()+i);
            }
            else{
            birds[i]->movefast(WINDOW_MAX_X, WINDOW_MAX_Y);
            }
        }
        for (unsigned int i=0; i<blues.size(); i++) {
           if (blues[i]->getX()>1200 || blues[i]->getY()<0){
           	delete blues[i];
            	 blues.erase(blues.begin()+i);
            	}
            	else{
            blues[i]->movefast(WINDOW_MAX_X, WINDOW_MAX_Y, dir);
            }
        }
	
        for (unsigned int i=0; i<planes.size(); i++) {
         if (planes[i]->getX()<0 || planes[i]->getY()<0){
           	delete planes[i];
          	 dir=dir*-1;
            	 planes.erase(planes.begin()+i);
            	}
            	else{
            planes[i]->movefast(WINDOW_MAX_X, WINDOW_MAX_Y);
            }
        }
        if (counter% 50==0) {
            int x = rand() %500 + 250;
            int y = rand() %500 + 150;
            b = new Bird(x, y, bird, this, scene);
            scene->addItem(b);
            birds.push_back(b);
        }

        if (counter%400==0) {
            int x = rand() %1000 + 250 ;
            int y = 750;
            c = new Blue(x, y, blue, this, scene);
            c->setTransformOriginPoint(0,0);
            scene->addItem(c);
            blues.push_back(c);
        }

        if (counter%1000==0) {
            int x = rand() %1000 + 250 ;
            int y = rand() %750 + 200;
            d = new Plane(x, y, plane, this, scene);
            scene->addItem(d);
            planes.push_back(d);
        }
        if (counter%8000==0) {
            int x = rand() %1000 + 250 ;
            int y = rand() %750 + 200;
            e = new Powerup(x, y, powerup, this, scene);
            scene->addItem(e);
        }
        if (counter %8300 == 0) {
            scene->removeItem(power);
        }
    }
    else {
	
        for (unsigned int i=0; i<birds.size(); i++) {
            if (birds[i]->getX()>1200){
            	//scene->removeItem(birds[i]);
            	delete birds[i];
            	birds.erase(birds.begin()+i);
            }
            else{
            birds[i]->move(WINDOW_MAX_X, WINDOW_MAX_Y);
            }
        }
        for (unsigned int i=0; i<blues.size(); i++) {
           if (blues[i]->getX()>1200 || blues[i]->getY()<0){
           //scene->removeItem(blues[i]);
           	delete blues[i];
            	 blues.erase(blues.begin()+i);
            	}
            	else{
            blues[i]->move(WINDOW_MAX_X, WINDOW_MAX_Y, dir);
            }
        }
	
        for (unsigned int i=0; i<planes.size(); i++) {
         if (planes[i]->getX()<0 || planes[i]->getY()<0){
         	//scene->removeItem(planes[i]);
           	delete planes[i];
          	 dir=dir*-1;
            	 planes.erase(planes.begin()+i);
            	}
            	else{
            planes[i]->move(WINDOW_MAX_X, WINDOW_MAX_Y);
            }
        }
        if (counter% 150==0) {
            int x = rand() %500 + 250;
            int y = rand() %500 + 150;
            b = new Bird(x, y, bird, this, scene);
            scene->addItem(b);
            birds.push_back(b);
        }
        if (counter%400==0) {
            int x = rand() %1000 + 250 ;
            int y = 750;
            c = new Blue(x, y, blue, this, scene);
            c->setTransformOriginPoint(0,0);
            scene->addItem(c);
            blues.push_back(c);
        }
        if (counter% 700==0) {
            int x = rand() %1000 + 250 ;
            int y = rand() %750 + 200;
            d = new Plane(x, y, plane, this, scene);
            scene->addItem(d);
            planes.push_back(d);
        }
        if (counter%1000==0) {
            int x = rand() %1000 + 250 ;
            int y = rand() %750 + 200;
            e = new Powerup(x, y, powerup, this, scene);
            scene->addItem(e);
        }
        if (counter %1200 == 0) {
            scene->removeItem(e);
        }
    }
}

void MainWindow::gameOver() {
    message = new QMessageBox();
    message->setText("YOU LOSE!");
    message->setStandardButtons(QMessageBox::Ok);
    button->setEnabled(true);
    message->show();
    timer->stop();
}
void MainWindow:: loseLife(Abstract *a) {
    lives=lives-1;
    if (lives==0) {
        delete o;
        delete p;
        delete q;
        delete r;
        scene->removeItem(l1);
        cloud = new QPixmap("blackcloud.png");
        s= new Cloud(200, 200, cloud, this, scene);
        t = new Cloud(450, 300, cloud, this, scene);
        u= new Cloud(800, 200, cloud, this, scene);
        v= new Cloud(650, 200, cloud, this, scene);
        scene->addItem(s);
        scene->addItem(t);
        scene->addItem(u);
        scene->addItem(v);
        gameOver();
    }
    if (lives ==1) {
        delete j;
        delete k;
        delete l;
        delete m;
        scene->removeItem(l2);
        cloud = new QPixmap("greycloud2.png");
        o= new Cloud(200, 200, cloud, this, scene);
        p= new Cloud(450, 300, cloud, this, scene);
        q= new Cloud(800, 200, cloud, this, scene);
        r= new Cloud(650, 200, cloud, this, scene);
        scene->addItem(o);
        scene->addItem(p);
        scene->addItem(q);
        scene->addItem(r);
    }
    if (lives ==2) {
        delete f;
        delete g;
        delete h;
        delete i;
        scene->removeItem(l3);
        gcloud = new QPixmap("greycloud.png");
        j= new Cloud(200, 200, gcloud, this, scene);
        k = new Cloud(450, 300, gcloud, this, scene);
        l= new Cloud(800, 200, gcloud, this, scene);
        m= new Cloud(650, 200, gcloud, this, scene);
        scene->addItem(j);
        scene->addItem(k);
        scene->addItem(l);
        scene->addItem(m);
    }
}
MainWindow::MainWindow() {
	dir=1;
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
    plane = new QPixmap("planefix.png");
    powerup = new QPixmap("powerupfix.png");
    blue = new QPixmap("balloonfix.png");
    bird = new QPixmap("birdfix.png");
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
    restart = new QPushButton(view);
    restart->setText("Restart");
    restart->setGeometry(10, 210, 60, 30);
    connect(restart, SIGNAL(clicked()), this, SLOT(Restart()));
    connect(button, SIGNAL(clicked()), this, SLOT(newGameClicked()));
    connect(pause, SIGNAL(clicked()), this, SLOT(Pause()));
    restart->setEnabled(true);
    QRect rect(0, 0, 0, 0);
    QFormLayout *formlayout = new QFormLayout(view);
    formlayout->setGeometry(rect);
    user = new QLineEdit(view);
    user->setText("");
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
