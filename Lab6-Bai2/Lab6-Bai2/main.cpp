//
//  main.cpp
//  Lab6-Bai2
//
//  Created by ManlyHumg on 11/11/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include <math.h>
#include "supportClass.h"

int        screenWidth = 610;
int        screenHeight= 300;

void drawPlane() {
    glColor3f(0.0, 0.0, 0.0);
    
    glBegin(GL_LINES);
    for (float i = -8.0; i <= 8; i+= 0.1) {
        glVertex3f(-8.0, 0, i);
        glVertex3f(8.0, 0 , i);
        glVertex3f(i, 0, -8.0);
        glVertex3f(i, 0 , 8.0);
    }
    glEnd();
    glFlush();
}

void myDisplay()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.5, 1.25, 0.5, 0, 0, 0, 0, 1, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(0, 0, 0);

    glViewport(0, 0, screenWidth/2-5, screenHeight);
    drawPlane();

    glViewport(screenWidth/2+5, 0, screenWidth/2, screenHeight);
    glMatrixMode(GL_PROJECTION);            // set projection matrix current matrix
    glLoadIdentity();                        // reset projection matrix
    gluPerspective(60.0f,(GLfloat)screenWidth/(GLfloat)screenHeight,1.0f,1000.0f);
    drawPlane();

    glFlush();
    glutSwapBuffers();
}


void myInit()
{
    float    fHalfSize = 2;

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glFrontFace(GL_CCW);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);
}

int main(int argc, const char * argv[])
{
    glutInit(&argc, (char**)argv); //initialize the tool kit
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_RGB | GLUT_DEPTH);//set the display mode
    glutInitWindowSize(screenWidth, screenHeight); //set window size
    glutInitWindowPosition(100, 100); // set window position on screen
    glutCreateWindow("Lab 5 - Bai 2"); // open the screen window

    myInit();
    
    glutDisplayFunc(myDisplay);
      
    glutMainLoop();
    return 0;
}
