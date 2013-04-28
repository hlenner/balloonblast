#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "cloud.h"
#include <QGraphicsSceneMouseEvent>
#include <string>
#include <QString>
#include <QGraphicsScene>

using namespace std;

Cloud::Cloud(){

}
Cloud::Cloud(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene) : Abstract(x, y, image, t, scene){
	
}
Cloud::~Cloud(){

}
void Cloud:: loseLife(){

}
void Cloud::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        //timer->start();
        //gui->MainWindowmoveTile(number, this);
    }
}
