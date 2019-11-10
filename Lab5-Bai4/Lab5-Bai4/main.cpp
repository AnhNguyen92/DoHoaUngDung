//
//  main.cpp
//  Lab5-Bai4
//
//  Created by ManlyHumg on 11/11/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include <math.h>
#include <iostream>
#include "supportClass.h"
#include "Mesh.h"

using namespace std;

#define        PI    3.1415926

#define        VIEWPORT_WIDTH    640
#define        VIEWPORT_HEIGHT 640

int        nChoice = 1;

Mesh    mesh1;

void axis(double length)
{
    //draw a z-axis with cone at end
    glPushMatrix();
    glBegin(GL_LINES);
        glVertex3d(0, 0, 0);
        glVertex3d(0, 0, length);
    glEnd();
    glTranslated(0, 0, length - 0.2);
    glutWireCone(0.04, 0.2, 12, 9);
    glPopMatrix();
}

void drawText(float xPos, float yPos, float zPos, char str[])
{
    glRasterPos3f(xPos, yPos, zPos); //Position
    
    void * font = GLUT_BITMAP_HELVETICA_18;
    for (int i=0; i<strlen(str);i++)
        glutBitmapCharacter(font, str[i]);
}
void DrawAxises()
{
    glDisable(GL_LIGHTING);

    glColor3f(0, 0, 1);
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(2.2, 0, 0);
        
        glVertex3f(0, 0, 0);
        glVertex3f(0, 2.2, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 2.2);
    glEnd();

    
    axis(2.2);
    glPushMatrix();
    glRotated(90,0,1,0);
    axis(2.2);
    glRotated(-90,1,0,0);
    axis(2.2);
    glPopMatrix();

    drawText(2.4, 0, 0, "X");
    drawText(0, 2.4, 0, "Y");
    drawText(0, 0, 2.4, "Z");
    }
    void setupCameraVolume()
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        float viewAngle = 10 ;
        float aspect = float(VIEWPORT_WIDTH)/VIEWPORT_HEIGHT;
        float nearDist = 0.1 ;
        float farDist = 1000.0;
        gluPerspective(viewAngle, aspect, nearDist, farDist);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //camera
        float    fR = 30;
        float    alpha = 60;
        float    beta = 45;
        Point3    lookat(0, 0, 0);
        Point3    up(0, 1, 0);

        gluLookAt(fR*sin(alpha*PI/180)*sin(beta*PI/180), fR*cos(alpha*PI/180), fR*sin(alpha*PI/180)*cos(beta*PI/180) ,
                    lookat.x, lookat.y, lookat.z,
                    up.x, up.y, up.z);
    }

    void myDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        setupCameraVolume();

        DrawAxises();

        glLineWidth(1);
        glColor3f(0, 0, 0);

        if(nChoice == 1)
            mesh1.DrawWireframe();
        
        glFlush();
        glutSwapBuffers();
    }

    void myInit()
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        glFrontFace(GL_CCW);
        glEnable(GL_DEPTH_TEST);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-3, 3, -3, 3, -1000, 1000);
        }

        void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
        {
            switch(theKey)
            {
            case '1':
                nChoice = 1;
                myDisplay();
                break;
            default:
                break;
            }
        }

        int main(int argc, const char * argv[])
        {
            glutInit(&argc, (char**)argv); //initialize the tool kit
            glutInitDisplayMode(GLUT_DOUBLE |GLUT_RGB | GLUT_DEPTH);//set the display mode
            glutInitWindowSize(VIEWPORT_WIDTH, VIEWPORT_HEIGHT); //set window size
            glutInitWindowPosition(100, 100); // set window position on screen
            glutCreateWindow("Lab 5 - Bai 4"); // open the screen window

            //mesh1.CreateYPlane();
            //mesh1.CreateCurvePlane();
            //mesh1.CreateElectrostaticPotentialEnery();
            //mesh1.Create4d();
            //mesh1.Create4e();
            mesh1.Create4f();
            myInit();
            glutKeyboardFunc(myKeyboard);
            glutDisplayFunc(myDisplay);
              
            glutMainLoop();
            return 0;
        }

