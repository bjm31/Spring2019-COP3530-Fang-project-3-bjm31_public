# COP 3530 - Data Structures and Algorithms I

# Due: 

# Project 3 - Racko

## Objective:

This project is meant to help you familiarize yourself with sequential data structures. You will be recreating the card game of 'Racko,' which is a game that involves rearranging your hand of cards in order to have an increasing sequence. Each card just has a number. We will be making a four player version of the game, where some players can be computer controller. A user's moves are decided by the user's input, while the computer's moves will be decided by you (you determine the strategy!). You will be using a combination of linked lists and arrays for doing this assignment.

## Learning Outcomes:

Developer a program that uses:

- Multiple modules
- Linked Lists
- Arrays

## Preparation:

To complete this project, you need to make sure that you have read the following (notice that topics between projects build upon each other):

- Chapter 3 - Strings
- Chapter 4 - Array and Vector Basics
- Chapter 7 - Objects and Classes Basics
- Chapter 9 - Modular Design and Makefiles
- Chapter 10 - Memory Management
- The Arrays Handout on Canvas
- Chapters 13 & 14 - Linked Lists

## Problem Description:

A Racko deck is composed of 60 cards, each numbered 1 to 60. The objective is to be the first player to arrange all of the cards in their rack from lowest to highest.

The start of a game of Racko will begin with the deck of cards being shuffled (please read the section on data structure requirements). Each player will be dealt 10 cards. The hands dealt to each player form the player's hand, called a "rack". A rack is special in that each card in the hand has a fixed position (from 1 to 10). As a player receives each card, they must place it in the highest available slot in their rack starting at slot 10, without rearranging any of the cards. The goal of each hand is to create a sequence of numbers in ascending order, starting at slot 1 and going all the way through slot 10.

The top card of the deck is turned over to start the discard pile. A player takes a turn by taking the top card from either the deck or the discard pile, then discarding one from their rack and inserting the new card in its place. A player may choose to discard the card if they wish (note that pulling from the discard pile and then discarding would be equivalent to a skipped turn). The first player to get their 10 cards in ascending order calls ”Rack-O!” and wins the hand.

## Overview of the Interface:

When the program first loads, it should prompt a user to enter the number of players that will be in the game (including computer players): 

```
Get ready to play Racko
How many players (including computer, max 4):
```

The program will then prompt for each player's name one by one and whether the player is a computer player. 

```
Get ready to play Racko
How many players (including computer, max 4): 2
Enter player number 1's name: brian
Is this a computer? Enter 1 for yes, 0 for no: 0
```

After the information is entered, it shows the hand for the first player. If the player is the first human player in the round, then it should print the round number. Either way, it should print the current player's turn, the player's hand\rack, the top of the discard pile, and the options to pull from the discard pile or the top of the deck. A rack is arranged from the slot 1 at the top to slot 10 at the bottom. Each number should be moved over the number of spaces represented by the card. This means that the 38 has been spaced over 38 spaces from the left hand side. You should note that 10 has an extra digit from other numbers so to account for the 0, lines with other numbers should have an additional space. 

```
###########################################################################
Round 0
brian's turn
HAND:
1:                                      38
2:                                               47
3:                                          42
4:                                         41
5:                16
6:                                            44
7:                                              46
8:           11
9:                 17
10:                         25
Available card in discard pile: 13
Enter 'p' to get the card from the discard pile, or 'd' to draw the unknown card from the top of the deck:
```

For each player's turn, they will need to select whether they want the card from the discard or the unseen deck. Then, they can select to replace one of the cards in a slot or to discard the card by entering a number less than 1:

```
Enter 'p' to get the card from the discard pile, or 'd' to draw the unknown card from the top of the deck: d
Enter the slot number from the left edge of the display that you want to replace with 32. Less than 1 simply discards the card: 4
```

The given selection will result in the following rack:

```
##########################################################################
Round 1
a's turn
HAND:
1:                                      38
2:                                               47
3:                                          42
4:                                32
5:                16
6:                                            44
7:                                              46
8:           11
9:                 17
10:                         25
Available card in discard pile: 29
Enter 'p' to get the card from the discard pile, or 'd' to draw the unknown card from the top of the deck:
```

For computer turns, you should simply print the result of their actions (the selections are done by the computer in this case and not by user input):

```
--------------------------------------------------------------------------
computer's turn
HAND:
1:                     21
2:                                                    52
3:          10
4:                             29
5:                          26
6:                                                 49
7:      6
8:                                                   51
9:                                                       55
10:                                                            60
Available card in discard pile: 41
p
Enter the slot number from the left edge of the display that you want to replace with 41. Less than 1 simply discards the card: 4
```

A player wins when they can put their cards within an ascending sequence. A sequence does not need to be continuous (i.e., there can be gaps):

```
##########################################################################
Round 14
brian's turn
HAND:
1:  2
2:          10
3:                             29
4:                                32
5:                                          42
6:                                            44
7:                                              46
8:                                                 49
9:                                                       55
10:                         25
Available card in discard pile: 20
Enter 'p' to get the card from the discard pile, or 'd' to draw the unknown card from the top of the deck: d
Enter the slot number from the left edge of the display that you want to replace with 57. Less than 1 simply discards the card: 10
RRRRRRAAAAAAAACKO brian won!!
```

The game should print the name of the player who won, along with shouting RACKO!.

### Sample run of program

Below is an example of how your program should run.

![Sample execution of program]()

## Data Structures:

A primary goal of this course is not to only gain familiarity in programming, but also in utilizing various data structures. Therefore, we are putting some constraints on the various implementations of components that will be acceptable. 

In this program, both your decks and your hands will rely on Card objects. In terms of this project, Cards are actually doubly-linked nodes with both previous and next pointers to other Cards. You will use these Card nodes in both your hand and stack classes to create collections of Cards. In other words, both your deck and hand classes can be viewed as doubly-linked lists that provide only the necessary methods for the game. Usage of arrays are prohibited, except for a temporary array to hold hands while Cards are being dealt.

Note, be careful with your pointers. You must keep them updated as things are being added and removed. 

## Code Organization:

You will need to make sure that your code meets the following specifications.
Note that there is some room for interpretation, but a general code outline is given below.
 
### The Main File
The main file shall handle setting up the player and the game and repeatedly call DoNextTurn until the game is over and complete. 

## Additional Requirements:

Your application must function as described below:

1. Your program must adhere to the class diagrams provided in this description.
2. You program must adhere to using the given interface as specified.
3. You must implement your hand and deck classes to be linked lists, using any other data structure for these purposes will result in your project being graded as if it does not compile.

## Extra Credit Opportunity (10 points)

An extra credit opportunity is given for the computer player. Extra credit is given if your computer players can play a game to completion against one another (with random starting racks). To get this extra credit, you cannot hard code the computer player's choices. 

## Important Notes:

- Projects will be graded on whether they correctly solve the problem, and whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date. Projects received after that time will get a grade of zero.
- Do not change the test files unless told to! The results you get will be pointless as they will not align with our grading! You can change maze.txt all you want.
- Please review the academic honesty policy.
  - Note that viewing another student's solution, whether in whole or in part, is considered academic dishonesty.
  - Also note that submitting code obtained through the Internet or other sources, whether in whole or in part, is considered academic dishonesty. \* All programs submitted will be reviewed for evidence of academic dishonesty, and all violations will be handled accordingly.
  
## Breakdown of Grades:

You will find a rubric for the project in Canvas. 

## Submission Instructions:

1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted" the assignment.
   1. After pushing, with `git push origin master`, visit the web URL of your repository to verify that your code is there.
      If you don't see the code there, then we can't see it either.
3. Your code must compile and run in Travis-CI or it might not be graded.
   1. The Travis-CI build should begin automatically when you push your code to GitHub.
   2. If your program will not compile, the graders will not be responsible for trying to test it.
   3. You should get an email regarding the status of your build, if it does not pass, keep trying.
