//
//  main.cpp
//  Lab3-Bai8
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "OpenGL/gl.h"
#include "GLUT/glut.h"
#include <iostream>
#include <math.h>

using namespace std;

const int screenWidth    = 600;
const int screenHeight    = 600;
#define        NUM 3
#define        PI    3.1415926

class GLintPoint
{
public :
    GLint    x, y ;
};

class Vector
{
public:
    Vector() { x = y = 0.0f; } // constructor 1
    Vector(float xx, float yy) { x = xx; y = yy; } // constructor 2
    void set(float xx, float yy) { x = xx; y = yy; }
    float getX() { return x;}
    float getY() { return y;}
    float dotProduct(Vector v)
    {
        return (this->x*v.x + this->y*v.y);
    }
    Vector scale(float f)
    {
        Vector temp;
        temp.set(this->x*f, this->y*f);
        return temp;
    }
public:
    float     x, y;
};

class Point2
{
public:
    Point2() { x = y = 0.0f; } // constructor 1
    Point2(float xx, float yy) { x = xx; y = yy; } // constructor 2
    void set(float xx, float yy) { x = xx; y = yy; }
    float getX() { return x;}
    float getY() { return y;}
    void draw()
    {
        glBegin(GL_POINTS);
        glVertex2f ((GLfloat)x, (GLfloat)y);
        glEnd();
    }
    Point2 add(Vector v)
    {
        Point2    temp;
        temp.set(this->x + v.x, this->y + v.y);
        return temp;
    }
public:
    float     x, y;
};

void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
void drawCircle(Point2 p1, float r) {
    glLineWidth(1.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float theta = 2.0 * PI * i / 360;
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(x + p1.getX(), y + p1.getY());
    }
    glEnd();
    glFlush();
}
void drawTriangle(Point2 points[]) {
    glClear(GL_COLOR_BUFFER_BIT);
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++)
        glVertex2f( (GLfloat) points[i].getX(), (GLfloat) points[i].getY());
    
    glEnd();

}
void draw(Point2 points[])
{
    drawTriangle(points);
    Point2 p;
    Vector a, b, c, na, nb;
    a.set(points[1].getX() - points[0].getX(), points[1].getY() - points[0].getY());
    b.set(points[2].getX() - points[1].getX(), points[2].getY() - points[1].getY());
    c.set(points[0].getX() - points[2].getX(), points[0].getY() - points[2].getY());
    
    na.set(-a.getY(), a.getX());
    nb.set(-b.getY(), b.getX());

    float bc = b.getX() * c.getX() + b.getY() * c.getY();
    float nac = na.getX() * c.getX() + na.getY() * c.getY();
    
    p.set( points[0].getX() + 0.5 *(a.getX() +  bc / nac * na.getX() ) ,
           points[0].getY() + 0.5 *(a.getY() + bc / nac * na.getY()));
    float r = sqrt((p.getX() - points[0].getX()) * (p.getX() - points[0].getX()) + (p.getY() - points[0].getY() ) * (p.getY() - points[0].getY()) );
    drawCircle(p, r);
}

void myMouse(int button, int state, int x, int y)
{
    //static Vector vectors[2];
    static Point2 points[NUM];
    static int    last = -1;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
        && last < NUM-1)
    {
        points[++last].set(x, screenHeight - y);
        if (last == NUM - 1) {
            draw(points);
        }
    }
    else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        last = -1;
        myDisplay();
    }
}


int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv); //initialize the tool kit
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);//set the display mode
    glutInitWindowSize(screenWidth, screenHeight); //set window size
    glutInitWindowPosition(50, 75); // set window position on screen
    glutCreateWindow("Circumcircle of triangle"); // open the screen window

    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    myInit();
    glutMainLoop();
    return 0;
}
