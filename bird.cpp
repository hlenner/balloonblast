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
Bird::Bird(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene, QGraphicsPixmapItem *bb) : Abstract(x, y, image, t, scene){
	bd=image;
	gui=t;
	xx=bb;
}
Bird::~Bird(){

}


void Bird::move(int x, int y ){
    this->moveBy(0.5, 0);
    xx->moveBy(0.5,0);
    
}
void Bird::loseLife(){

}
void Bird::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        gui->mainWindowloselife(this);
    }
}
void Bird::blowup(){
	
}
