//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // keep playing until game over
    double velocityx =  (drand48()*3);
    double velocityy = 1.5;
    while (lives > 0 && bricks > 0)
    {

    //move and hit
    move(ball, velocityx, velocityy);
    
    int t = 5;
    if (bricks < 40)
    {
    t=3;
    }
    
    else if (bricks < 20)
    {
    t=1;
    }
    pause (t);
    if (getX(ball) + getWidth(ball) >= getWidth(window)|| getX(ball) < 0)
    {
        velocityx = -velocityx;  
    }
    
    else if ( getY(ball) < 0 || (getY(ball)+getHeight(ball)) >= getHeight(window))
    {
        velocityy = -velocityy; 
    }
    
    //
    updateScoreboard(window, label, bricks);
    
    if ((getY(ball)+getHeight(ball)) >= getHeight(window))
    {
    lives--;
    setLocation(ball, 190, 300);
    velocityx = +velocityx;
    waitForClick();
    }
    
    
    //hits rect
    GObject object = detectCollision(window, ball);
    if ((object != NULL) && strcmp(getType(object), "GRect") == 0)
    {
    velocityy = -velocityy;
    if (object != paddle)
    {
    removeGWindow(window, object);
    bricks--;
    }
    
    }
    //mouse
    GEvent event = getNextEvent(MOUSE_EVENT);
    
    if(event != NULL)
    {
     if(getEventType(event) == MOUSE_MOVED )
     {
            double x = getX(event) - getWidth(paddle) / 2;
            setLocation (paddle, x, 570);
     }
     }
     
     //
    }
    

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
    int k = 3;
    int l = 0;
    int m = 5;
    while (l < ROWS){
    char* n[] = {"RED","YELLOW","GREEN","BLUE","PINK" };
    for (int i=0; i<COLS; i++)
    {
        GRect brick = newGRect(k, m , 35 , 20);
        setFilled(brick, true);
        setColor(brick, n[l]);
        add (window, brick);
        k = k+ 40;
        

    }
    l++;
    m = m + 25;
    k = 3;
    }

}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval ball = newGOval (190, 300, 15, 15);
    setFilled(ball, true);
    setColor(ball, "BLACK");
    add (window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    GRect paddle = newGRect(155, 550, 90, 10);
    setFilled(paddle, true);
    setColor(paddle, "BLUE");
    add (window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel score = newGLabel("0");
    setColor(score, "LIGHT_GRAY");
    setFont(score, "SansSerif-50");
    setLocation(score, 200, 400);
    add (window, score);
    return score;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
