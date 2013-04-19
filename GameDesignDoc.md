# Game Design Doc
## Balloon Blast
### Haley Lenner
#### CSCI102 T/Th 12-150

**Objects**
##### Character 1- main character
>the main character will be the mouse. It will be controlled by the user and act as 
>a completely normal mouse with clicking capabilities.

##### Character 2- background
>the background will be my one non-moving object. It will be light blue with clouds, mirroring the sky.

![alt text](http://www.psdgraphics.com/file/cloudy-sky-cartoon.jpg "Background sky")

##### Character 3- enemy #1 birds
>Level one will have birds flying in the sky as well. They must be avoided because if you click them then you lose
a life. It will move by using the qt timer and in prewritten patterns that coordinate with the location of balloons for that level.

![alt text](http://c85c7a.medialib.glogster.com/media/32/32c5232676493d154dc608b27fa601850f0d695d6d0096166901c149707aa1e3/how-to-draw-a-cartoon-bird.jpg "enemy bird")

##### Character 4- enemy #2 airplanes
>Level two will have a different enemy, an airplane that will also make you lose a life if clicked on **or** if the mouse scrolls over it.
The mouse must manuever around the airplane because coming in contact with it at all will lose a life. 

![alt text](http://www.myprivateramblings.com/wp-content/uploads/2008/12/bigstockphoto_cartoon_airplane_774922.jpg "Background sky")


##### Character 5- balloon
>the balloons are the main target, the goal is to clear the field and get rid of all balloons within the view as quickly
as possible. They will randomly pop up on the screen and continue to do so, getting harder and harder until you beat the level. 

![alt text](http://vector.us/files/images/1/9/196602/helium_blue_balloon_clip_art.jpg "balloon")

##### Character 6- powerup
>there will be one or two blinking special colored balloons per level that appear and leave the view very quickly and if you click on one of those, you get more points.
They might also make you gain a life, depending on how often I decide to make them appear.

![alt text](http://www.chicoparty.com/images/products/detail/RedandOrangeAgateBalloon.jpg "powerup balloon")

**How to play**

>It will be an extremely fast paced reaction/clear the field type of game. You have balloons moving
around slowly on the screen and want to pop them by clicking them with the mouse. Because there is a timer and the goal is 
to be as fast as possible, there is possibility of clicking the birds accidentally which will make you lose a life.
 
**Score**

>There will be a score image on the screen, and next to that, a number with the user's score.
The score will never be negative, and the faster you finish a level, the more extra points you get.
Time will be kept. You also get extra points for clicking the small balloons that appear because they are 
hard to get to in time.

**Lives**

>There will be two lives that will be kept track of by little images in the corner. Three
small images of balloons will show the lives, and when a life is lost, one of the
images will be deleted. When there are 0 images, the user has lost and the game is over.

**Layout of User Interface**

>The layout will be similar to the one we used for PA4. There will be a start button, stop button,
I will add a pause button, and there will also be a place to add the name of the user before the 
game is started for customization and high score purposes. Additionally, there will be a score that
increments when balloons are popped and lives will be displayed on the interface as well and will
decrement appropriately

The things I will use(not everything, but as of right now these are the buttons/input):

| Object        | For what?           |
|:-------------:|:-------------------:|
| QLineEdit     | enter user's name   |
| QPushButton   | start game          |
| QPushButton   | pause game          |
| QPushButton   | quit  game          |

Example layout:

![lenner](layout.jpeg "layout")


