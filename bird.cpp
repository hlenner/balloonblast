#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "bird.h"
#include <QGraphicsSceneMouseEvent>
#include <string>
#include <QString>
#include "MainWindow.h"
#include <QGraphicsScene>

using namespace std;

Bird::Bird(){

}
Bird::Bird(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene) : Abstract(x, y, image, t){
	bd=image;
	gui=t;
	_x=x;
	setScale(.2);
        setPos(x, y);	
	
}
Bird::~Bird(){

}
double Bird::getX(){
	return _x;
}
void Bird::move(){
	_x=_x+0.5;
	//cout << "x" << _x<<endl;
	this->moveBy(0.5, 0);
    	
    
}
void Bird::movefast(){
    this->moveBy(1.2, 0);
    _x=_x+1.2;
    
}
void Bird::loseLife(){

}
void Bird::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        gui->loseLife();
    }
}
void Bird::blowup(){
	
}
