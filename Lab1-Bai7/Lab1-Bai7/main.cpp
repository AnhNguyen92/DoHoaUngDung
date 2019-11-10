//
//  main.cpp
//  Lab1-Bai7
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//
#include <math.h>
#include "OpenGL/gl.h"
#include "GLUT/glut.h"
#include <math.h>

#define     PI        3.1415926
#define    WIDTH        900
#define     HEIGHT        600

float    fX[10], fY[10];

struct    Point2
{
    float    x, y;
};

void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLineWidth(3);

    glColor3f(0.0, 0.0, 0.0);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    //Viết thêm mã vào phần này
    //…………………………………………………………………
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 10; i += 1) {
            glVertex2f((GLfloat) fX[i], (GLfloat) fY[i]);
        }
    glEnd();
    glFlush();

}

Point2 lineIntersection(Point2 p1, Point2 p2, Point2 p3, Point2 p4)
{
    Point2 t;

    float    A1, B1, A2, B2;

    A1 = (p2.y - p1.y)/(p2.x-p1.x);
    B1 = p1.y - A1*p1.x;

    A2 = (p4.y - p3.y)/(p4.x-p3.x);
    B2 = p3.y - A2*p3.x;

    t.x = (B2 - B1)/(A1-A2);
    t.y = A1*t.x + B1;

    return t;
}

float calculateRadius(float centerX, float centerY) {
    float radius;
    Point2 p0, p8, p6, p2;

    p0.x = fX[0];
    p0.y = fY[0];
    p2.x = fX[2];
    p2.y = fY[2];
    p6.x = fX[6];
    p6.y = fY[6];
    p8.x = fX[8];
    p8.y = fY[8];

    Point2 p9 = lineIntersection(p0, p6, p8, p2);
    radius = sqrt((p9.x - centerX) * (p9.x - centerX) + (p9.y-centerY) * (p9.y-centerY));

    return radius;
}

void calVertex()
{
    //Viết thêm mã vào phần này
    //…………………………………………………………………
    float    centerX, centerY;
    float    radius;
    float    alpha;
    float    inc;

    centerX = WIDTH/2.0;
    centerY = HEIGHT/2.0;

radius = 200;

    alpha = PI/2.0;
    inc   = 2.0*PI/5.0;

    fX[0] = centerX;
    fY[0] = centerY + radius;
    for (int i = 8; i >= 2; i -= 2) {
        alpha += inc;
        fX[i] = centerX + radius*cos(alpha);
        fY[i] = centerY + radius*sin(alpha);
    }
    
    radius = calculateRadius(centerX, centerY);
    alpha += inc/2.0;
    for(int i = 9; i >= 1; i-= 2) {
        alpha += inc;
        fX[i] = centerX + radius*cos(alpha);
        fY[i] = centerY + radius*sin(alpha);
    }
}

int main(int argc, const char * argv[]) {
    calVertex();

    glutInit(&argc, (char**)argv); //initialize the tool kit
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);//set the display mode
    glutInitWindowSize(WIDTH, HEIGHT); //set window size
    glutInitWindowPosition(0, 0); // set window position on screen
    glutCreateWindow("National Flag"); // open the screen window

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
