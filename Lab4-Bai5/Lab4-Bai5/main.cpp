//
//  main.cpp
//  Lab4-Bai5
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include <fstream>
#include "OpenGL/gl.h"
#include "GLUT/glut.h"

using namespace std;

const    float picWidth = 780;
const    float picHeight = 600;

const    float    scrWidth = 1.5*picWidth;
const    float    scrHeight = 1.5*picHeight/2;

void drawPolyLineFile(char* fileName)
{
    fstream inStream;
    inStream.open(fileName, ios::in);
    if(inStream.fail())
        return;
    
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
void drawDino()
{
    glScalef(0.2, 0.2, 1);
    glTranslatef(-picWidth/2,-picHeight/2, 0);
    drawPolyLineFile("dinosaur.dat");
}
void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
}
void setWindow(float l, float r, float b, float t)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D((GLdouble)l,(GLdouble)r,(GLdouble)b,(GLdouble)t);
    glMatrixMode(GL_MODELVIEW);
}
void setViewport(int l, int r, int b, int t)
{
    glViewport(l, b, r - l, t - b);
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    setViewport(0, scrWidth/2, 0, scrHeight);
    setWindow(-picWidth/2, picWidth/2, -picHeight/2, picHeight/2);

    const int numMotifs = 12;
    float    H = picHeight / 3.0;
    for(int i = 0; i<numMotifs; i++)
    {
        glLoadIdentity();
        glRotatef(i * 360.0 / numMotifs, 0, 0, 1);
        glTranslatef(0, H, 0);
        drawDino();
    }

    setViewport( scrWidth/2, scrWidth, 0, scrHeight);
    setWindow(-picWidth/2, picWidth/2, -picHeight/2, picHeight/2);

    for(int i = 0; i<numMotifs; i++)
    {
        glLoadIdentity();
        glRotatef(i * 360.0 / numMotifs, 0, 0, 1);
        glTranslatef(0, H, 0);
        glRotatef(-i * 360.0 / numMotifs, 0, 0, 1);

        drawDino();
    }
    glFlush();
}

int main(int argc, const char * argv[])
{
    glutInit(&argc, (char**)argv); //initialize the tool kit
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB); //set the display mode
    glutInitWindowSize(scrWidth, scrHeight); //set window size
    glutInitWindowPosition(0, 0); // set window position on screen
    glutCreateWindow("LAB 4 - (Bai 4)");//open the screen window

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
