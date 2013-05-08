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
	
	setScale(.2);
        setPos(x, y);
        _x=x;		
}
Bird::~Bird(){

}
double Bird::getX(){
	return _x;
}
void Bird::move(){
this->moveBy(0.5, 0);
	_x=_x+0.5;
     	
        
}
void Bird::level3(){
this->moveBy(3, 0);
	_x=_x+3;	
    
    
}
void Bird::movefast(){
this->moveBy(2, 0);
_x=_x+2;
    
    
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
