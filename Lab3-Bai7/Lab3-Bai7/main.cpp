//
//  main.cpp
//  Lab3-Bai7
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "OpenGL/gl.h"
#include "GLUT/glut.h"
#include <math.h>
#include <iostream>

using namespace std;

const int screenWidth    = 600;
const int screenHeight    = 600;
#define        NUM 4
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
            glVertex2f((GLfloat)x, (GLfloat)y);
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
void findInTersection(Point2 points[]) {
    Vector b, c, d, bPerp, dPerp;
    b.set( points[1].getX() - points[0].getX(), points[1].getY() - points[0].getY() );
    c.set( points[2].getX() - points[0].getX(), points[2].getY() - points[0].getY() );
    d.set( points[3].getX() - points[2].getX(), points[3].getY() - points[2].getY() );
    bPerp.set(-b.getY(), b.getX());
    dPerp.set(-d.getY(), d.getX());

    float t = ((dPerp.getX() * c.getX()) + dPerp.getY() * c.getY())
                / (dPerp.getX() * b.getX() + dPerp.getY() * b.getY());
    glColor3f(0.0f, 0.0f, 1.0f);
    Point2 p;
    p.set( points[0].getX() + b.getX() * t, points[0].getY() + b.getY() * t );
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2f(p.getX(), p.getY());
    glEnd();
    glFlush();
}
void drawLine(Point2 points[], int last) {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f((GLfloat)points[last-1].getX(),(GLfloat) points[last-1].getY());
    glVertex2f((GLfloat)points[last].getX(),(GLfloat) points[last].getY());
    glEnd();
    glFlush();
}

void myMouse(int button, int state, int x, int y)
{
    static Vector vectors[2];
    static Point2 points[NUM];
    static int    last = -1;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && last < NUM-1)
    {
        points[++last].set(x, screenHeight - y);
        if (last % 2 == 1) {
            drawLine(points, last);
        }
        if (last == NUM - 1) {
            findInTersection(points);
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
    glutCreateWindow("Intersection of two line segments"); // open the screen window

    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    myInit();
    glutMainLoop();
    
    return 0;
}
