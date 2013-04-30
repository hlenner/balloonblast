#ifndef Cloud_H
#define Cloud_H
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

class Cloud : public Abstract
{
 public:
  Cloud();
  Cloud(int x, int y, QPixmap* image, MainWindow *t, QGraphicsScene *scene);
  void moveright();
  void moveleft();
  /** Destructor */
  ~Cloud();
  QGraphicsScene *scene2;

  //bool win();
  

 private:
  
  
};

#endif
