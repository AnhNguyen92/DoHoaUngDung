//
//  main.cpp
//  Lab1_bai10
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include <math.h>
#include "OpenGL/gl.h"
#include "GLUT/glut.h"

#define     PI        3.1415926

#define        WIDTH        600
#define     HEIGHT        600

float        fX[15], fY[15];

struct    Point2
{
    float    x, y;
};

void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}

void drawQuad(int x0, int x1, int x2, int x3, bool isBlue) {
    glBegin(GL_QUADS);
    if (isBlue) {
        glColor3f(3.0f/255.0, 43.0f/255.0, 145.0f/255.0);
    } else {
        glColor3f(20.0f/255.0, 136.0f/255.0, 219.0f/255.0);
    }
    glVertex2f((GLfloat) fX[x0], (GLfloat) fY[x0]);
    glVertex2f((GLfloat) fX[x1], (GLfloat) fY[x1]);
    glVertex2f((GLfloat) fX[x2], (GLfloat) fY[x2]);
    glVertex2f((GLfloat) fX[x3], (GLfloat) fY[x3]);
    glEnd();
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

    radius = 100;

    alpha = PI/2.0;
    inc   = PI/3.0;

    fX[0] = centerX;
    fY[0] = centerY + radius;
    fX[6] = centerX;
    fY[6] = centerY + 2*radius;

    for (int i = 5; i >= 1; i--) {
        alpha += inc;
        fX[i] = centerX + radius*cos(alpha);
        fY[i] = centerY + radius*sin(alpha);
    }
    fX[7] = fX[1];
    fY[7] = fY[1] + radius;
    fX[14] = fX[5];
    fY[14] = fY[5] + radius;
    fX[10] = fX[2];
    fY[10] = fY[2] - radius;
    fX[11] = fX[4];
    fY[11] = fY[4] - radius;
    inc       = 2.0*PI/3.0;

    alpha = PI/2.0;
    for (int i = 12; i >= 9; i -= 3) {
        alpha += inc;
        fX[i] = centerX + 2*radius*cos(alpha);
        fY[i] = centerY + 2*radius*sin(alpha);
    }
    
    fX[13] = fX[12];
    fY[13] = fY[12] + radius;
    fX[8] = fX[9];
    fY[8] = fY[9] + radius;

}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLineWidth(3);

    glColor3f(0.0, 0.0, 0.0);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    //Viết thêm mã vào phần này
    //…………………………………………………………………
    drawQuad(14, 5, 0, 6,true);
    drawQuad(0, 6, 7, 1, false);
    drawQuad(1, 8, 9, 2, true);
    drawQuad(2, 9, 10, 3, false);
    drawQuad(3, 11, 12, 4, true);
    drawQuad(4, 12, 13, 5, false);
    
    glFlush();
}

int main(int argc, const char * argv[]) {
    calVertex();

    glutInit(&argc, (char**)argv); //initialize the tool kit
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);//set the display mode
    glutInitWindowSize(WIDTH, HEIGHT); //set window size
    glutInitWindowPosition(0, 0); // set window position on screen
    glutCreateWindow("Coloring HCMC University of Technology's Logo"); // open the screen window

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
