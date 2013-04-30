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
Cloud::Cloud(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene) : Abstract(x, y, image, t){
	setX(x);
        setY(y);
        scene2=scene;
}
Cloud::~Cloud(){

}
void Cloud:: moveleft(){
this->moveBy(-2, 0);

}
void Cloud:: moveright(){
this->moveBy(2, 0);

}


