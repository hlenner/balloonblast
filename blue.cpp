#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "blue.h"
#include <QGraphicsSceneMouseEvent>
#include <string>
#include <QGraphicsScene>
#include <QString>
#include "MainWindow.h"

using namespace std;

Blue::Blue(){

}
Blue::Blue(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene) : Abstract(x, y, image, t, scene){
	bd=image;
	gui=t;
	scene2=scene;
	setScale(.15);
        setPos(x,y);
        _x=x;
        _y=y;
        
}
Blue::~Blue(){

}

void Blue::movefast(int dir){
	int h = rand() %2+ 1;
	int l = rand() %2+ 1*dir;
	this->moveBy(l, -h);
	_x=_x+l;
	_y=_y+h;
}
void Blue::move(int dir){
	int h = rand() %2 +.1 ;
	int l = rand() %2+.1*dir;
	this->moveBy(l, -h);
	_x=_x+l;
	_y=_y+h;
}

void Blue::loseLife(){

}
double Blue::getX(){
return _x;
}
double Blue::getY(){
return _y;
}
void Blue::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
    gui->getPoints(this);
    }
}
void Blue::blowup(){
	
}
