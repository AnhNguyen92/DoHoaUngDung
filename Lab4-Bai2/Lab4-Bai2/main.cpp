//
//  main.cpp
//  Lab4-Bai2
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//


#include "OpenGL/gl.h"
#include "GLUT/glut.h"

#define    WINDOW_LEFT        -10
#define    WINDOW_RIGHT         10
#define    WINDOW_BOTTOM        -10
#define    WINDOW_TOP         10

void myInit(){
    glClearColor(1.0,1.0,1.0,0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(WINDOW_LEFT, WINDOW_RIGHT, WINDOW_BOTTOM, WINDOW_TOP);
}

void drawGrid(){
    glColor3f(0.6f, 0.6f, 0.6f);
    glLineWidth(1.0);

    glBegin(GL_LINES);
        for(int i = WINDOW_LEFT; i<=WINDOW_RIGHT; i++){
            glVertex2i(i, WINDOW_BOTTOM);
            glVertex2i(i, WINDOW_TOP);
        }
        for(int i = WINDOW_BOTTOM; i<WINDOW_TOP; i++){
            glVertex2i(WINDOW_LEFT, i);
            glVertex2i(WINDOW_RIGHT, i);
        }
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(5.0);
    
    glBegin(GL_LINES);
        glVertex2i(WINDOW_LEFT, 0);
        glVertex2i(WINDOW_RIGHT, 0);
        glVertex2i(0, WINDOW_BOTTOM);
        glVertex2i(0, WINDOW_TOP);
    glEnd();
}

void drawHouse5(){
    glLineWidth(3.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2i(0, 0);
        glVertex2i(-6, 0);
        glVertex2i(-6, -3);
        glVertex2i(-3, -6);
        glVertex2i(0, -3);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.75, -3.75);
        glVertex2f(-0.75, -6);
        glVertex2f(-2.25, -6);
        glVertex2f(-2.25, -5.25);
    glEnd();
}

void drawHouse4(){
    glLineWidth(3.0);
    glColor3f(153.0/255, 217.0/255, 234.0/255);
    glBegin(GL_LINE_LOOP);
        glVertex2i(0, 2);
        glVertex2i(0, 6);
        glVertex2i(-2, 6);
        glVertex2i(-4, 4);
        glVertex2i(-2, 2);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(-2.5, 2.5);
        glVertex2f(-4, 2.5);
        glVertex2f(-4, 3.5);
        glVertex2f(-3.5, 3.5);
    glEnd();
}

void drawHouse3(){
    glLineWidth(3.0);
    glColor3f(1.0, 128.0/255, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(2, -3);
        glVertex2i(6, -3);
        glVertex2i(6, 0);
        glVertex2i(4, 3);
        glVertex2i(2, 0);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(2.5, 0.75);
        glVertex2f(2.5, 3);
        glVertex2f(3.5, 3);
        glVertex2f(3.5, 2.25);
    glEnd();
}

void drawHouse2(){
    glLineWidth(3.0);
    glColor3f(63.0/255, 72.0/255, 204.0/255);
    glBegin(GL_LINE_LOOP);
        glVertex2i(4, 3);
        glVertex2i(8, 3);
        glVertex2i(8, 5);
        glVertex2i(6, 7);
        glVertex2i(4, 5);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(4.5, 5.5);
        glVertex2f(4.5, 7);
        glVertex2f(5.5, 7);
        glVertex2f(5.5, 6.5);
    glEnd();
}

void drawHouse(){
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(0, 0);
        glVertex2i(4, 0);
        glVertex2i(4, 2);
        glVertex2i(2, 4);
        glVertex2i(0, 2);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(0.5, 2.5);
        glVertex2f(0.5, 4);
        glVertex2f(1.5, 4);
        glVertex2f(1.5, 3.5);
    glEnd();
}
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();

    glColor3f(1.0f, 0.0f, 0.0f);
    drawHouse();
    
    // hinh 2
    //glColor3f(0, 0, 1.0);
    glColor3f(63.0/255, 72.0/255, 204.0/255);
    glTranslated(4,  3,0);
    drawHouse();
    
    // hinh 3
    glColor3f(1.0, 128.0/255, 1.0);
    glScaled(1, 1.5 , 0);
    glTranslated(-2, -4, 0);
    drawHouse();

    // hinh 4
    glColor3f(153.0/255, 217.0/255, 234.0/255);
    glScaled(1, 1/1.5 , 0);
    glTranslated(-2, 5, 0);
    glRotated(90, 0, 0, 1.0);
    drawHouse();

    // hinh 5
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslated(-2, 0, 0);
    glRotated(90, 0, 0, 1.0);
    glScaled(1.5, 1.5, 0);
    
    drawHouse();

    glFlush();
}


int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv); //initialize the tool kit
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB); //set the display mode
    glutInitWindowSize(650, 650); //set window size
    glutInitWindowPosition(0, 0); // set window position on screen
    glutCreateWindow("LAB 4 - (Bai 2)");//open the screen window

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
