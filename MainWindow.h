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
#include "Powerup.h"
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

/** The MainWindow class which sets up the game and handles a big part of it, the timer.
Also stores vectors of the objects and keeps track of number of lives, points, and 
collisions.
@author Haley Lenner
*/

#define WINDOW_MAX_X 450
#define WINDOW_MAX_Y 325

using namespace std;

class Blue;

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
/**constructor */
	
    explicit MainWindow();
    ~MainWindow();/**destructor*/
    void show();/**shows everything in the view*/
    int counter;/**used to help with the timer*/
    //void gameOver();
    void mainWindowloselife(Abstract *a);
    QLineEdit *size;/**size pointer*/
    int lives;
    void getPoints(Abstract *a);
    void getBonusPoints(Abstract *a);
    int points;
    void checkCollision();
    int objects;
    vector<Blue*> blues;
    vector<Plane*> planes;
    vector<Powerup*> powers;
    vector<Cloud*> clouds;
    vector<Bird*> birds; 
    vector<int> scores;
    vector<string> names;
    QGraphicsPixmapItem *l2;
    QGraphicsPixmapItem *l3;
    QGraphicsPixmapItem *power;
    QGraphicsPixmapItem *l1;
    QLabel *score;
    QLabel *showlives;
    QLabel *num;
    QLabel *showpts;
    QLabel *name;
    void checkCloudCollision();
    void loseLife();
    void showHighScores();
    void read();
    int numlines;
    int dir;
    string username;
    bool two;
    bool three;
    bool four;
    bool five;
    bool one;
    bool gameov;
    void gameOver();
    QTimer *timer;/**timer to handle animating tiles*/

private:
    QGraphicsScene *scene;/**scene to display GUI*/
    QGraphicsView *view;/**adds items to change display*/
    
    QPushButton *button;/**start button connected to newGame*/
    QPushButton *quit;/**quit button, exits out*/
    QPushButton *pause;
    QPushButton *restart;
    QLabel *score1;
    QLabel *score2;
    QLabel *score3;
    QLabel *score4;
    QLabel *score5;
    QLabel *name1;
    QLabel *name2;
    QLabel *name3;
    QLabel *name4;
    QLabel *name5;
    QLineEdit *user;
    QPixmap *bird;
    QPixmap *cloud;
    QPixmap *gcloud;
    QPixmap *blue;
    QPixmap *life;
    QPixmap *plane;
    QPixmap *powerup;
    Bird *b;
    Blue *c;
    Plane *d;
    Powerup *e;
    Cloud *f;
    Cloud *g;
    Cloud *h;
    Cloud *i;
    Cloud *j;
    Cloud *k;
    Cloud *l;
    Cloud *m;
    Cloud *o;
    Cloud *p;
    Cloud *q;
    Cloud *r;
    Cloud *s;
    Cloud *t;
    Cloud *u;
    Cloud *v;
    

public slots:
 
    void newGameClicked();
    void Pause();
    void handleTimer();
    void Restart();
   
    
};

#endif // MAINWINDOW_H
