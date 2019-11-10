//
//  main.cpp
//  Lab4-Bai6
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include <math.h>
#include "OpenGL/gl.h"
#include "OpenGL/glu.h"
#include "GLUT/glut.h"
const int screenWidth = 700;
const int screenHeight = 700;

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.2, 1.2, -1.2, 1.2, 0.1, 100);
}
void setLight()
{
    GLfloat    lightIntensity[]={0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat light_position[]={10, 10, 20.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
}
void setMaterial()
{
    GLfloat    mat_ambient[]={0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat    mat_diffuse[]={1.0f, 0.0f, 0.0f, 1.0f};
    GLfloat    mat_specular[]={1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat mat_shininess[] = {50.0f};

    glMaterialfv(GL_FRONT,GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuse);
}
void setCamera()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(10, 6, 10, 0.0, 0.5, 0.0, 0.0, 1.0, 0.0);
}
void drawAxis()
{
    float    xmax = 1.5, ymax = 1.5, zmax = 1.5;
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
        glVertex3f(-xmax, 0, 0);
        glVertex3f(xmax, 0, 0);
        glVertex3f(0, -ymax, 0);
        glVertex3f(0, ymax, 0);
        glVertex3f(0, 0, -zmax);
        glVertex3f(0, 0, zmax);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glColor3f(0.0, 0.0, 0.0);

    void * font = GLUT_BITMAP_TIMES_ROMAN_24;

    glRasterPos3f(1.5, 0, 0);
    glutBitmapCharacter(font, 'X');

    glRasterPos3f(0, 1.5, 0);
    glutBitmapCharacter(font, 'Y');

    glRasterPos3f(0, 0, 1.5);
    glutBitmapCharacter(font, 'Z');
}
void display()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        
    setCamera();
    drawAxis();
    setLight();
    
    setMaterial();
    /* hình 1 */
    //glTranslated(1, 0, 0);
    // hình 2
    //glTranslated(0.5, 1, 0.9);
    /* hình 3 */
    //glTranslated(0, 0, 1);
    //glRotated(90, 0, 1, 0);

    glScaled(0.5, 0.5, 0.5);
    glTranslated(0, 1, 0);
    glRotated(60, 0, 1, 0);

    
    glutSolidTeapot(0.25);

    glFlush();
}


int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv); //initialize the tool kit
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB |GLUT_DEPTH);//set the display mode
    glutInitWindowSize(screenWidth, screenHeight); //set window size
    glutInitWindowPosition(0, 0); // set window position on screen
    glutCreateWindow("Lab 4 - Bai 5"); // open the screen window

    glutDisplayFunc(display);

    init();
    glEnable(GL_DEPTH_TEST);
    
    glutMainLoop();
    return 0;
}
