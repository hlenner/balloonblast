#ifndef Powerup_H
#define Powerup_H
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

/** The powerup class which sets up the powerup
@author Haley Lenner
*/

class MainWindow;

class Powerup : public Abstract
{
 public:
  Powerup();
  Powerup(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene);
  MainWindow *gui;
  QGraphicsPixmapItem *xx;
  /** Destructor */
  ~Powerup();

  void mousePressEvent(QGraphicsSceneMouseEvent *event);

 private:
  QPixmap *bd;
  
  
};

#endif
