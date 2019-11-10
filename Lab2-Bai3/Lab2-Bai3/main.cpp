//
//  main.cpp
//  Lab2-Bai3
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "Canvas.h"

Canvas   cvs(640, 640, "Draw Figure - Hinh 2");

void drawFigure()
{
    cvs.setLineWidth(12);
    cvs.moveTo(0, 2);
    cvs.lineTo(1, 2);
    cvs.lineTo(1, 1);
    cvs.lineTo(2, 1);
    cvs.lineTo(2, 0);
}

void myDisplay()
{
    cvs.clearScreen();
    cvs.setViewport(320, 640, 320, 640);
    cvs.setWindow(0, 2, 0, 2);
    drawFigure();

    cvs.setViewport(320, 640, 0, 320);
    cvs.setWindow(0, 2, 2, 0);
    drawFigure();

    cvs.setViewport(0, 320, 0, 320);
    cvs.setWindow(2, 0, 2, 0);
    drawFigure();
    
    cvs.setViewport(0, 320, 320, 640);
    cvs.setWindow(2, 0, 0, 2);
    drawFigure();

}


int main(int argc, const char * argv[])
{
    cvs.setBackgroundColor(1.0, 1.0, 1.0);
    cvs.setColor(0.0, 0.0, 0.0);
    
    glutDisplayFunc(myDisplay);

    glutMainLoop();
    return 0;
}

