//
//  main.cpp
//  Lab2_bai3c
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "Canvas.h"

Canvas   cvs(640, 640, "Draw Figure - Hinh 4");

void drawFigure()
{
    cvs.setLineWidth(12);
    cvs.moveTo(0, 4);
    cvs.lineTo(0, 4);
    cvs.lineTo(2, 4);
    cvs.lineTo(2, 0);
    cvs.lineTo(0, 0);
    cvs.lineTo(0, 4);

}

void myDisplay()
{
    cvs.clearScreen();
    cvs.setViewport(160, 480, 0, 640);
    cvs.setWindow(0, 2, 0, 4);
    drawFigure();

    
    cvs.setViewport(0, 640, 160, 480);
    cvs.setWindow(0, 2, 4, 0);
    drawFigure();

}

int main(int argc, const char * argv[]) {
    cvs.setBackgroundColor(1.0, 1.0, 1.0);
    cvs.setColor(0.0, 0.0, 0.0);

    glutDisplayFunc(myDisplay);

    glutMainLoop();
    return 0;
}
