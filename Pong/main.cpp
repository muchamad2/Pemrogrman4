#include <windows.h>
#include <GL/glut.h>
#include "OpenWindow.h"
#include "Racket.h"
#include "Ball.h"
#include "UIText.h"
//variable for declare each player position
float racket_left_x = 10.0f;//for player 1
float racket_left_y = 50.0f;//
float racket_right_x = WIDTH - 20;//for player 2
float racket_right_y = 50.0f;//

int main(int argc,char *argv[])
{
    //init game object
    Racket *player1 = new Racket();
    Racket *player2 = new Racket();
    Ball *ball = new Ball();
    UIText *Ui = new UIText();
    //set player position in game
    player1->setPosition(racket_left_x,racket_left_y);
    player2->setPosition(racket_right_x,racket_right_y);
    //set current player
    player2->setPlayer(2);
    player1->setPlayer(1);
    //add player for check collision with ball
    ball->setPlayer(player1,player2);
    //add ball for check goal and getscore condition for redraw
    Ui->setBall(ball);
    //attach all object to give update and draw for each object
    OpenWindow::Instance()->attach(player1);
    OpenWindow::Instance()->attach(player2);
    OpenWindow::Instance()->attach(ball);
    OpenWindow::Instance()->attach(Ui);
    //init opengl
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Pong");
    //function opengl for give update and draw for window
    glutDisplayFunc(OpenWindow::render);
    glutTimerFunc(Interval,OpenWindow::update,0);
    //to set coordinate of window with center point in buttom left
    OpenWindow::Instance()->view2D();
    //opengl main loop function
    glutMainLoop();
    return EXIT_SUCCESS;
}
