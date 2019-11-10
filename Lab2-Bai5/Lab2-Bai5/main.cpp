//
//  main.cpp
//  Lab2-Bai5
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "Canvas.h"
#define        PI    3.1415926
#define        angle -30.0
Canvas    cvs(600, 600, "Polygons");

void polyspiral(int n)
{
    float len = 5;
    cvs.turn(90.0 - angle * n);
    for(int i=1; i <= 12; i++){
        cvs.forward(len,1);
        cvs.turn(angle);
    }
}

void myDisplay(){
    cvs.clearScreen();
    for(int i = 0; i < 12; i++) {
        cvs.setWindow(-20,20,-20,20);
        cvs.moveTo(0.0,0.0);
        cvs.setCD(0.0);
        cvs.setViewport(0,600,0,600);
        polyspiral(i);
    }
}

int main(int argc, const char * argv[]) {
    cvs.setBackgroundColor(1.0, 1.0, 1.0);
    cvs.setColor(0.0, 0.0, 0.0);
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
