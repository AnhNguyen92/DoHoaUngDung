//
//  main.cpp
//  Lab2Bai3b
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "Canvas.h"

Canvas   cvs(640, 640, "Draw Figure - Hinh 2");

void drawFigure(float x)
{
    cvs.setLineWidth(12);
    cvs.moveTo(0, 2 * x);
    cvs.lineTo(x, 2 * x);
    cvs.lineTo(x, x);
    cvs.lineTo(2 * x, x);
    cvs.lineTo(2 * x, 0);
}

void myDisplay()
{
    cvs.clearScreen();
    cvs.setViewport(320, 640, 320, 640);
    cvs.setWindow(0, 4, 0, 4);
    drawFigure(1);
    drawFigure(2);

    cvs.setViewport(320, 640, 0, 320);
    cvs.setWindow(0, 4, 4, 0);
    drawFigure(1);
    drawFigure(2);

    cvs.setViewport(0, 320, 0, 320);
    cvs.setWindow(4, 0, 4, 0);
    drawFigure(1);
    drawFigure(2);
    
    cvs.setViewport(0, 320, 320, 640);
    cvs.setWindow(4, 0, 0, 4);
    drawFigure(1);
    drawFigure(2);

}


int main(int argc, const char * argv[]) {
    cvs.setBackgroundColor(1.0, 1.0, 1.0);

    cvs.setColor(0.0, 0.0, 0.0);

    glutDisplayFunc(myDisplay);

    glutMainLoop();
    return 0;
}
