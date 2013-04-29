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

  //bool win();
  
 private:
  QPixmap *bd;
  QPixmap* pic;
  int _x;
  int _y;
  int _s;
  
  
};

#endif
