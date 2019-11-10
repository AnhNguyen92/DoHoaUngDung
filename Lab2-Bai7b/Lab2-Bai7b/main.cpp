//
//  main.cpp
//  Lab2-Bai7b
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//
#include "Canvas.h"
#include "math.h"
#define        PI    3.1415926

Canvas    cvs(400, 400, "Whirling Swirl");

void MakeNGon(float fRadius, int n, float startAngle){
    float    del_angle = 2.0*PI/n;
    float    angle;
    float    x, y;
    
    for(int i=0; i<=n; i++){
        angle = i*del_angle + startAngle;
        x = fRadius*cos(angle);
        y = fRadius*sin(angle);
        if(i == 0)
            cvs.moveTo(x, y);
        else
            cvs.lineTo(x, y);
    }
}

void hexSwirl() {
    for (int i = 0; i < 40; i++)
        MakeNGon(i *0.04, 6, i * PI /30);
}
void myDisplay() {
    cvs.clearScreen();
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++)
        {
            int L= 80;
            cvs.setViewport(i*L, i*L + L,j*L, j*L+L);
            if((i+j)%2 ==0)
                cvs.setWindow(0.6, -0.6, 0.6, -0.6);
            else
                cvs.setWindow(-0.6, 0.6, 0.6, -0.6);
            hexSwirl();
        }
    }
}

int main(int argc, const char * argv[]) {
    cvs.setBackgroundColor(1.0, 1.0, 1.0);
    cvs.setColor(0.0, 0.0, 0.0);
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
