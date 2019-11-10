//
//  main.cpp
//  Lab2-Bai9.1
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "Canvas.h"

Canvas   cvs(640, 480, " Bai 9-Hinh 1");

void drawFigure()
{
    cvs.setColor(0, 0, 0);
    cvs.setLineWidth(1);
    float        x = 0.02 + 2.0 * sin(2.0 * 0.02);
    float        y = 0.02 + 2.0 * cos(5.0 * 0.02);
    cvs.moveTo(x, y);
    for(float t = 0.02; t <= 15.5; t+= 0.01) {
        x = t + 2.0 * sin(2.0 * t);
        y = t + 2.0 * cos(5.0*t);
        
        cvs.lineTo(x, y);
    }
}

void myDisplay()
{
    cvs.clearScreen();
    cvs.setViewport(0,640,0,480);
    cvs.setWindow(-0.3, 13, -1.5, 13.0);
    drawFigure();
}

int main(int argc, const char * argv[]) {
    cvs.setBackgroundColor(1.0, 1.0, 1.0);
    cvs.setColor(0.0, 0.0, 0.0);

    glutDisplayFunc(myDisplay);

    glutMainLoop();
    return 0;
}
