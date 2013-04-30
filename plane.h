#ifndef Plane_H
#define Plane_H
#include <iostream>
#include <map>
#include <functional>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QObject>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <qapplication.h>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include "abstract.h"
#include <QGraphicsScene>

/** The MainWindow class which sets up the game and handles a big part of it, the timer.
Also stores vectors of the objects and keeps track of number of lives, points, and 
collisions.
@author Haley Lenner
*/

class MainWindow;

class Plane : public Abstract
{
 public:
  Plane();
  Plane(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene);
  MainWindow *gui;
  void movefast();
  void move();
  int getX();
  int getY();
  /** Destructor */
  ~Plane();
  
 private:
  QPixmap *bd;
  QPixmap* pic;
  int _x;
  int _y;
  
  
};

#endif
