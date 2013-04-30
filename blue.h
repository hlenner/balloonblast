#ifndef Blue_H
#define Blue_H
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
#include <QObject>
#include "abstract.h"
/** The Blue class which sets up the balloon objects 
@author Haley Lenner
*/
class MainWindow;

class Blue : public Abstract {

 public:
  Blue();
  Blue(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene);
  MainWindow *gui;
  void move(int dir);
  void movefast(int dir);
  QGraphicsScene *scene2;
  void loseLife();
  double getX();
  double getY();
  int x;
  /** Destructor */
  ~Blue();

  //bool win();
  
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void blowup();
 private:
  QPixmap *bd;
  int _x;
  int _y;
  
  
};

#endif
