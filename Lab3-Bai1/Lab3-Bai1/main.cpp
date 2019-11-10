//
//  main.cpp
//  Lab3-Bai1
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//
#include "OpenGL/gl.h"
#include "GLUT/glut.h"

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

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void myMouse(int button, int state, int x, int y)
{
    static GLintPoint List[NUM];
    static int    last = -1;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && last < NUM-1)
    {
        List[++last].x = x;
        List[  last].y = screenHeight - y;
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINE_STRIP);
        for(int i=0;i<=last;i++)
            glVertex2i(List[i].x, List[i].y);
        glEnd();
        glFlush();
    }
    else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        last = -1;
}


int main(int argc, const char * argv[])
{
    glutInit(&argc, (char**)argv); //initialize the tool kit
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);//set the display mode
    glutInitWindowSize(screenWidth, screenHeight); //set window size
    glutInitWindowPosition(100, 150); // set window position on screen
    glutCreateWindow("Create a polyline using mouse"); // open the screen window

    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    myInit();
    glutMainLoop();
    return 0;
}
