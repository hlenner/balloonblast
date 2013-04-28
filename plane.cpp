#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "plane.h"
#include <QGraphicsSceneMouseEvent>
#include <string>
#include <QString>
#include "MainWindow.h"
#include <QGraphicsScene>

using namespace std;

Plane::Plane(){

}
Plane::Plane(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene, QGraphicsPixmapItem *bb) : Abstract(x, y, image, t, scene){
	bd=image;
	gui=t;
	xx=bb;
}
Plane::~Plane(){

}
void Plane::move(int x, int y){
this->moveBy(-0.5, -0.5);
    xx->moveBy(-0.5, -0.5);
}
void Plane::loseLife(){

}
void Plane::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        gui->mainWindowloselife(this);
    }
}
void Plane::blowup(){
	
}
