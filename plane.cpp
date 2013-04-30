#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "plane.h"
#include <QGraphicsSceneMouseEvent>
#include <string>
#include <QKeyEvent>
#include <QWidget>
#include <QString>
#include "MainWindow.h"
#include <QGraphicsScene>
#include <QPixmap>

using namespace std;

Plane::Plane(){

}
Plane::Plane(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene) : Abstract(x, y, image, t){
	bd=image;
	gui=t;
	setScale(.15);
        setPos(x, y);
        _x=x;
        _y=y;
}
Plane::~Plane(){

}
void Plane::move(){
	this->moveBy(-1, -1);
	_x=_x-1;
	_y=_y-1;
}
void Plane::movefast(){
	this->moveBy(-2, -2); 
	_x=_x-2;
	_y=_y-2;    
}

int Plane::getX(){
return _x;
}
int Plane::getY(){
return _y;
}

