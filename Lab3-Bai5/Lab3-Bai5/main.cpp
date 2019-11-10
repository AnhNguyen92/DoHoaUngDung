//
//  main.cpp
//  Lab3-Bai5
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "OpenGL/gl.h"
#include "GLUT/glut.h"
#include <math.h>
#include <ctime>
#include <cstdlib>

const int screenWidth    = 600;
const int screenHeight    = 600;
#define NUM 20

class GLintPoint
{
    public :
        GLint    x, y ;
};
    
void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
    }
void drawDot(GLint x, GLint y) {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
}

int random(int m) {
    srand(time(0));
    return rand() % m ;
}

void Sierpinski(GLintPoint corner[3]) {
    GLintPoint  T[3]={  {corner[0].x, corner[0].y},
                        {corner[1].x, corner[1].y},
                        {corner[2].x, corner[2].y}} ;
        
    int         index = random(3) ;
    GLintPoint    point = T[index] ;

    glClear(GL_COLOR_BUFFER_BIT);
    drawDot(point.x, point.y) ;
    for(int i=0; i<5000;i++) {
        index = random(3);
        point.x = (point.x + T[index].x) / 2;
        point.y = (point.y + T[index].y) / 2;
        drawDot(point.x, point.y) ;
    }
    glFlush();
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void myMouse(int button, int state, int x, int y) {
    static GLintPoint corner[3];
    static int    numCorners = 0;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        corner[numCorners].x = x;
        corner[numCorners].y = screenHeight - y;
        numCorners++;
        if(numCorners == 3) {
            Sierpinski(corner);
            numCorners = 0;
        }
    }
}

int main(int argc, const char * argv[])
{
    glutInit(&argc, (char**)argv); //initialize the tool kit
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);//set the display mode
    glutInitWindowSize(screenWidth, screenHeight); //set window size
    glutInitWindowPosition(100, 150); // set window position on screen
    glutCreateWindow("Control sierpinski gasket by using mouse"); // open the screen window
    
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    myInit();
    glutMainLoop();
    return 0;
}
