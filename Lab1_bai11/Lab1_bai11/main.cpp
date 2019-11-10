//
//  main.cpp
//  Lab1_bai11
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include <math.h>
#include "OpenGL/gl.h"
#include "GLUT/glut.h"
#include <math.h>

#define        WIDTH        1400

#include <iostream>
#define     HEIGHT        800
#define        SCALE        100 /* SCALE = HEIGHT/8 */
#define        FIRST_GRAP    30 /* get approximately 1/3 SCALE */

bool isIncrease;
bool isFirstTime;
int distance;

void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}

void getDistance() {
    if (isIncrease) {
        distance += FIRST_GRAP;
        if (distance == (2 * FIRST_GRAP)) {
            isIncrease = false;
        }
    } else {
        if (distance > 0)
            distance -= FIRST_GRAP;
        else {
            if (!isFirstTime) {
                distance += FIRST_GRAP;
            } else {
                isFirstTime = false;
            }
            isIncrease = true;
        }
    }
}

void drawLines() {
    glColor3f(0.6f, 0.6f, 0.6f);
    glLineWidth(1.0);
    for (int i = 1; i <= 7; i ++) {
        glBegin(GL_LINES);
        glVertex2f((GLfloat) 0, (GLfloat) i * SCALE);
        glVertex2f((GLfloat) WIDTH, (GLfloat) i * SCALE);
        glEnd();
    }
}

void drawBlackRectangles() {
    glLineWidth(1.0);
    glColor3f(0.0, 0.0, 0.0);
    for (int j = 0; j < 8; j++) {
        getDistance();
                for (int i = 0; i < 8; i ++) {
                    glBegin(GL_QUADS);
                    glVertex2f((GLfloat) 200*i + distance, (GLfloat) HEIGHT - 100 *j);
                    glVertex2f((GLfloat) 200*i + distance + 100, (GLfloat) HEIGHT - 100 *j);
                    glVertex2f((GLfloat) 200*i + distance + 100, (GLfloat) HEIGHT - 100 *(j+1));
                    glVertex2f((GLfloat) 200*i + distance, (GLfloat) HEIGHT - 100 *(j+1));
                    glEnd();
                }
            }
        }

        void myDisplay()
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

            isIncrease = false;
            isFirstTime = true;
            distance = 0;
            drawLines();
            drawBlackRectangles();
            glFlush();
        }

int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv); //initialize the tool kit
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);//set the display mode
    glutInitWindowSize(WIDTH, HEIGHT); //set window size
    glutInitWindowPosition(0, 0); // set window position on screen
    glutCreateWindow("Psychedelic simulation"); // open the screen window

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
