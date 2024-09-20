Exercise 4 LEVELS EDITOR
The names of the presenters:
Harut Partner 205741333
Nicole Kazantsev 208258095
The exercise is about building a levels editor for the cat and mouse game.
The purpose of the exercise is to practice inheritance and using the sfml library.

The files we created:
Controller.h : runs the program and links all the elements.  
Controller.cpp : public run function implementation. and the other relevant functions as privacy.

Toolbar.h : class responsible for the button menu. 
Toolbar.cpp : implementing the appropriate relevant functions.   

Board.h : is a class responsible for printing the board of the rectangles and updating it.   
Board.cpp : implementing the relevant functions. and loading textures.  
GameObject.h : A button class whose function is to contain information about the buttons found in the button menu.

GameObject.cpp : Implementation of relevant functions. Mainly those that initialize the information with each button and those that return the information written in it.

Main data structure:
A one-dimensional vector of char : from which row's come out by request == m_matrixVector
rectangleshape : Draws the rectangles with relevant textures.

secondary:
The controller class is a connecting class between the objects. It contains members from every created class (except GameObject which is a toolbar member)
It is responsible for calling relevant functions found in the other classes and updating the information after the user clicks on the character matrix.
After the update it will draw the updated board.

Notes:
The format of the resulting text file is in the upper row the length and width of the board.
and then the related characters.
