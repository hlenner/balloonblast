#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <qapplication.h>
#include <QGraphicsRectItem>
#include <QTimer>
#include "abstract.h"
#include "bird.h"
#include "blue.h"
#include "cloud.h"
#include "plane.h"
#include <QTimeLine>
#include <QRadioButton>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <vector>
#include <QTextEdit>
#include <QLineEdit>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>
#include <QLabel>


#define WINDOW_MAX_X 450
#define WINDOW_MAX_Y 325

using namespace std;

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
/**constructor */
    explicit MainWindow();
    ~MainWindow();/**destructor*/
    void show();/**shows everything in the view*/
    int counter;/**used to help with the timer*/
    void gameOver();
    void mainWindowloselife(Abstract *a);
    QLineEdit *size;/**size pointer*/
    int lives;
    int points;
    int objects;
    vector<Blue*> blues;
    vector<Plane*> planes;
    vector<Cloud*> clouds;
    vector<Bird*> birds; 
    QGraphicsPixmapItem *l2;
    QGraphicsPixmapItem *l3;
    QGraphicsPixmapItem *l1;
    QLabel *score;
    QLabel *showlives;
    QLabel *num;

private:
    QGraphicsScene *scene;/**scene to display GUI*/
    QGraphicsView *view;/**adds items to change display*/
    QTimer *timer;/**timer to handle animating tiles*/
    QPushButton *button;/**start button connected to newGame*/
    QPushButton *quit;/**quit button, exits out*/
    QPushButton *pause;
    QLineEdit *user;
    QPixmap *bird;
    QPixmap *cloud;
    QPixmap *blue;
    QPixmap *life;
    QPixmap *plane;
    

public slots:
 
    void newGameClicked();
    void Pause();
    void loseLife();
    void handleTimer();
};

#endif // MAINWINDOW_H
