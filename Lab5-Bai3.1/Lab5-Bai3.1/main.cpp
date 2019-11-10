//
//  main.cpp
//  Lab5-Bai3.1
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//


#include <math.h>
#include <iostream>
#include "supportClass.h"
#include "Mesh.h"

using namespace std;

int        screenWidth = 600;
int        screenHeight= 300;


Mesh    tetrahedron;
Mesh    cube;
Mesh    cylinder;
Mesh icosahedron;
Mesh truncatedCube;
Mesh cylinderWithHole;
Mesh dedocahedron;

int        nChoice = 1;

void myKeyboard(unsigned char key, int x, int y)
{
    glutPostRedisplay();
}

void myDisplay()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 4, 2, 0, 0, 0, 0, 1, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, screenWidth/2, screenHeight);
    
    glColor3f(0, 0, 0);

    if(nChoice == 1)            tetrahedron.DrawWireframe();
    else if(nChoice == 2)        cube.DrawWireframe();
    else if(nChoice == 3)        cylinder.DrawWireframe();
    else if(nChoice == 4)        icosahedron.DrawWireframe();
    else if(nChoice == 5)        truncatedCube.DrawWireframe();
    else if(nChoice == 6)        cylinderWithHole.DrawWireframe();
    else if(nChoice == 7)        dedocahedron.DrawWireframe();

    glViewport(screenWidth/2, 0, screenWidth/2, screenHeight);

    if(nChoice == 1)            tetrahedron.DrawColor();
    else if(nChoice == 2)        cube.DrawColor();
    else if(nChoice == 3)        cylinder.DrawColor();
    else if(nChoice == 4)        icosahedron.DrawColor();
    else if(nChoice == 5)        truncatedCube.DrawColor();
    else if(nChoice == 6)        cylinderWithHole.DrawColor();
    else if(nChoice == 7)        dedocahedron.DrawColor();

    glFlush();
    glutSwapBuffers();
}

void myInit()
{
    float    fHalfSize = 3;

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glFrontFace(GL_CCW);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);
}

int main(int argc, const char * argv[]) {
    cout << "1. Tetrahedron" << endl;
        cout << "2. Cube" << endl;
        cout << "3. Cylinder" << endl;
        cout << "4. Icosshedron" << endl;
        cout << "5. TruncatedCube" << endl;
        cout << "6. Cylinder with hole" << endl;
        cout << "7. Dedocahedron" << endl;
        cout << "Input the choice: " << endl;
        cin  >> nChoice;

        glutInit(&argc, (char**)argv); //initialize the tool kit
        glutInitDisplayMode(GLUT_DOUBLE |GLUT_RGB | GLUT_DEPTH);//set the display mode
        glutInitWindowSize(screenWidth, screenHeight); //set window size
        glutInitWindowPosition(100, 100); // set window position on screen
        glutCreateWindow("Lab 5 - Bai 3"); // open the screen window

        tetrahedron.CreateTetrahedron();
        cube.CreateCube(1);
        cylinder.CreateCylinder(16, 4, 2);
        icosahedron.CreateIcosahedron();
        truncatedCube.CreateTruncatedCube(2.0);
        cylinderWithHole.CreateCylinderWithHole(16, 4.0, 2.0, 0.5);
        dedocahedron.CreateDedocahedron();
        myInit();
        glutKeyboardFunc(myKeyboard);
        glutDisplayFunc(myDisplay);
          
        glutMainLoop();
        return 0;
    }


