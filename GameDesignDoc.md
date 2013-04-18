<<<<<<< HEAD
# Game Design Doc
## 
### Haley Lenner
#### CSCI102 T/Th 12-150

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.
**Objects**
##### Character 1- main character

##### Character 2- background

##### Character 3- enemy #1

##### Character 4- enemy #2

##### Character 5- powerup

##### Character 6- 

**How to play**

**Score**
>There will be a score image on the screen, and next to that, a number with the user's score.
>The score will never be negative.

**Lives**
>There will be three lives that will be kept track of by little images in the corner. Three
>small images of the main character will show the lives, and when a life is lost, one of the
> images will be deleted. When there are 0 images, the user has lost and the game is over.

**Layout of User Interface**
>The layout will be similar to the one we used for PA4. There will be a start button, stop button,
> I will add a pause button, and there will also be a place to add the name of the user before the 
>game is started for customization and high score purposes. 

The things I will use:

| Object        | For what?     |
|:-------------:|:-------------:|
| QLineEdit     | user's name   |
| QPushButton   | start game    |
| QPushButton   | pause game    |
| QPushButton   | quit  game    |



=======
# Game Design Document
This is a place holder for your game design document. You are advised to write your document in [Markdown](http://daringfireball.net/projects/markdown/) and the following section will show you how to write a document using Markdown markup.

Alternativley, you can write your document in plain text if you wish.

----

## Markdown
Markdown is a human-readable structured plain text format that is used to convert text into HTML. GitHub automatically renders Markdown into HTML.

This is a crash course on how to use Markdown. The following section will show you the plain text used to generate the document shown in the rendering section.

### Code

```
# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")
```

----

### Rendering
This section shows the rendering of the plain text above.

# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.
>>>>>>> 0e801df47c846986c3b3f851ba7674816ca6c77b

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

<<<<<<< HEAD

Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")
=======
Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")

>>>>>>> 0e801df47c846986c3b3f851ba7674816ca6c77b
