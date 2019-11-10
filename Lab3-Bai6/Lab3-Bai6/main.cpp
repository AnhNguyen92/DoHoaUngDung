//
//  main.cpp
//  Lab3-Bai6
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

    void drawLine(Point2 points[], int last) {
        glBegin(GL_LINES);
        glVertex2f((GLfloat)points[last-1].getX(),(GLfloat) points[last-1].getY());
        glVertex2f((GLfloat)points[last].getX(),(GLfloat) points[last].getY());
        glEnd();
        glFlush();
    }

    void calculateAngle(Vector vectors[]) {
        float dotProduct = vectors[0].dotProduct(vectors[1]);
        float v1Length = sqrt(vectors[0].getX() * vectors[0].getX() + vectors[0].getY() * vectors[0].getY());
        float v2Length = sqrt(vectors[1].getX() * vectors[1].getX() + vectors[1].getY() * vectors[1].getY());
        float angle = acos(dotProduct / (v1Length * v2Length)) * 180 / PI;

        cout << "angle between two line segments is : " << angle;
    }

void myMouse(int button, int state, int x, int y) {
    static Vector vectors[2];
    static Point2 points[4];
    static int    last = -1;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && last < NUM-1) {
    points[++last].set(x, screenHeight - y);
    if (last % 2 == 1) {
        drawLine(points, last);
        vectors[last/2].set(points[last].getX() - points[last-1].getX(),
                            points[last].getY() - points[last-1].getY() );
        }
        if (last == NUM - 1) {
            calculateAngle(vectors);
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
    glutCreateWindow("Calculate angle of two line segments"); // open the screen window

    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    myInit();
    glutMainLoop();
    
    return 0;
}
