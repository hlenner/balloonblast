#ifndef ABSTRACT_H
#define ABSTRACT_H
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

class MainWindow;

class Abstract : public QGraphicsPixmapItem
{
 public:
  Abstract();
  Abstract(int x, int y, QPixmap *image, MainWindow *t, QGraphicsScene *scene);
  MainWindow *gui;
  /** Destructor */
  ~Abstract();
  virtual void loseLife() = 0;
  int getX();
  int getY();
  //virtual void move(int x, int y)=0;

 protected:
  int x_;
  int y_;
  QPixmap *pic;
  
};
#endif
