//
//  main.cpp
//  Lab4-Bai3
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "OpenGL/gl.h"
#include "GLUT/glut.h"
#include <fstream>

using namespace std;

float    WINDOW_LEFT;
float    WINDOW_RIGHT;
float    WINDOW_BOTTOM;
float    WINDOW_TOP;

void drawPolyLineFile(char* fileName)
{
    fstream inStream;
    inStream.open(fileName, ios::in);
    if(inStream.fail())
        return;
    glClear(GL_COLOR_BUFFER_BIT);
    GLint    numpolys, numLines;
    GLfloat x, y;
    inStream>>numpolys;

    for(int j=0;j<numpolys;j++)
    {
        inStream >> numLines;
        glBegin(GL_LINE_STRIP);
        for(int i =0; i<numLines; i++)
        {
            inStream>>x>>y;
            glVertex2d(x, y);
        }
        glEnd();
    }
    glFlush();
    inStream.close();
}

void findWindow(char* fileName)
{
    float maxX = 0, minX = 5000, maxY = 0, minY = 5000;
    fstream inStream;
    inStream.open(fileName, ios::in);
    if (inStream.fail())
        return;
    
    GLint noPolys, noLines;
    GLfloat x, y;
    inStream >> noPolys;

    for (int i = 0; i < noPolys; i++) {
        inStream >> noLines;
        for (int i = 0; i < noLines; i++) {
            inStream >> x >> y;
            if ( maxX < x)        maxX = x;
            if ( minX > x)        minX = x;
            if ( maxY < y)        maxY = y;
            if ( minY > y)        minY = y;
        }
    }
    inStream.close();

    WINDOW_LEFT = minX - 20;
    WINDOW_RIGHT = maxX + 20;
    WINDOW_TOP = maxY + 20;

        WINDOW_BOTTOM = minY - 20;
    }

    void myInit()
    {
        glClearColor(1.0,1.0,1.0,0.0);
        glColor3f(0.0,0.0,0.0);
        
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(WINDOW_LEFT, WINDOW_RIGHT, WINDOW_BOTTOM, WINDOW_TOP);
    }
    void myDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        drawPolyLineFile("rabbit.dat");
        
        glFlush();
    }

    int main(int argc, const char * argv[])
    {
        findWindow("rabbit.dat");
        
        glutInit(&argc, (char**)argv); //initialize the tool kit
        glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB); //set the display mode
        glutInitWindowSize(WINDOW_RIGHT-WINDOW_LEFT, WINDOW_TOP-WINDOW_BOTTOM);
        glutInitWindowPosition(0, 0); // set window position on screen
        glutCreateWindow("LAB 4 - (Bai 3)");//open the screen window

        glutDisplayFunc(myDisplay);
        myInit();
        glutMainLoop();
        return 0;
    }
