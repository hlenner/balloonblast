#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "Powerup.h"
#include <QGraphicsSceneMouseEvent>
#include <string>
#include <QString>
#include "MainWindow.h"
#include <QGraphicsScene>

using namespace std;

Powerup::Powerup(){

}
Powerup::Powerup(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene) : Abstract(x, y, image, t, scene){
	bd=image;
	gui=t;
	setScale(.08);
        setPos(x, y);
}
Powerup::~Powerup(){

}
void Powerup::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        gui->getBonusPoints(this);
    }
}
