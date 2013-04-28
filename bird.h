#ifndef BIRD_H
#define BIRD_H
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
#include <QPointF>

class MainWindow;

class Bird : public Abstract
{
 public:
  Bird();
  Bird(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene, QGraphicsPixmapItem *bb);
  MainWindow *gui;
  void move(int x, int y);
  void loseLife();
  QGraphicsPixmapItem *xx;
  
  /** Destructor */
  ~Bird();

  //bool win();
  
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void blowup();
 private:
  QPixmap *bd;
  
};

#endif
