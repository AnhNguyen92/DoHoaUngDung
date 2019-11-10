//
//  main.cpp
//  Lab2-Bai9.2
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "Canvas.h"

Canvas   cvs(640, 480, " Bai 9-Hinh 2");

void drawFigure()
{
    cvs.setColor(0, 0, 0);
    cvs.setLineWidth(1);
    float        x = cos(1.0) - cos(80.0*1.0) * sin(1.0);
    float        y = 2.0 * sin(1.0) - sin(80.0 * 1.0);
    cvs.moveTo(x, y);
    for(float t = 1.0; t <= 15.0; t+= 0.001) {
        x = cos(t) - cos(80.0*t) * sin(t);
        y = 2.0 * sin(t) - sin(80.0 * t);
        
        cvs.lineTo(x, y);
    }
}

void myDisplay()
{
    cvs.clearScreen();
    cvs.setViewport(0,640,0,480);
    cvs.setWindow(-1.5, 1.5, -3.0, 3.0);
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
