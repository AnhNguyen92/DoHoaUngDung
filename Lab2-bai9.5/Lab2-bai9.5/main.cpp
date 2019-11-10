//
//  main.cpp
//  Lab2-bai9.5
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "Canvas.h"

Canvas   cvs(640, 480, " Bai 9-Hinh 6");

void drawFigure()
{
    cvs.setColor(0, 0, 0);
    cvs.setLineWidth(1);
    float        x = sin(3.0*0.1);
    float        y = sin(4.0*0.1);
    cvs.moveTo(x, y);
    for(float t = 0.1; t <= 6.5; t+= 0.01){
        x = sin(3.0*t);
        y = sin(4.0*t);
        
        cvs.lineTo(x, y);
    }
}

void myDisplay()
{
    cvs.clearScreen();
    cvs.setViewport(0,640,0,480);
    cvs.setWindow(1.2, -1.2, -1.2, 1.2);
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
