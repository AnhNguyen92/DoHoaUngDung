//
//  Mesh.cpp
//  Lab5-Bai3.1
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include "Mesh.h"
#include "GLUT/glut.h"
#include "OpenGL/gl.h"

#define PI            3.1415926
#define    COLORNUM        14


float    ColorArr[COLORNUM][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, { 0.0,  0.0, 1.0},
                                 {1.0, 1.0,  0.0}, { 1.0, 0.0, 1.0},{ 0.0, 1.0, 1.0},
                                 {0.3, 0.3, 0.3}, {0.5, 0.5, 0.5}, { 0.9,  0.9, 0.9},
                                 {1.0, 0.5,  0.5}, { 0.5, 1.0, 0.5},{ 0.5, 0.5, 1.0},
                                 {0.0, 0.0, 0.0}, {0.5, 0.5, 0.25}};

int icosahedronVerts[20][3] = { {0,2,6}, {2,3,6}, {3,5,6}, {5,6,7}, {0,6,7},
                                {2,3,8}, {1,2,8}, {0,1,2}, {0,1,10}, {1,9,10},
                                {1,8,9}, {3,4,8}, {3,4,5}, {4,5,11}, {7,10,11},
                                {0,7,10}, {4,9,11},{4,8,9}, {5,7,11}, {9,10,11} };

int truncatedCubeVerts[6][8] = { {0,1,2,3,4,5,6,7}, {8,13,20,21,14,9,1,0},
                                 {18,19,20,21,22,23,16,17}, {2,3,10,15,23,22,14,9},
                                    {4,5,11,12,17,16,15,10}, {6,7,8,13,19,18,12,11} };

int triangleCubeVerts[8][3] = { {1,2,9}, {3,4,10}, {5,6,11}, {0,7,8},
                                {12,17,18}, {19,13,20}, {14,21,22}, {15,16,23} };
int dedocahedronVerts[12][5] = { {0,4,15,8,7}, {6,7,8,9,10}, {1,0,7,6,5},
                                {1,5,11,12,2}, { 11,12,13,16,17},{ 2,3,18,13,12},
                                {0,1,2,3,4}, {3,4,15,14,18}, {5,6,10,17,11},
                                { 17,10,9,19,16}, {8,9,19,14,15}, { 13,16,19,14,18} };

void Mesh::CreateCylinderWithHole(int nSegment, float fHeight, float fORadius, float fIRadius)
{
    int i;
    float x, y, z;
    y = fHeight/2;
    float angle = 2.0 * PI / nSegment;

    numVerts = nSegment * 4;
    pt = new Point3[numVerts];
    for(i = 0; i < nSegment; i++)
    {
        x = fORadius*cos(i*angle);
        z = fORadius*sin(i*angle);
        pt[i].set(x, y, z);
        pt[i+nSegment].set(x, -y, z);

        x = fIRadius*cos(i*angle);
        z = fIRadius*sin(i*angle);
        pt[i+2*nSegment].set(x, y, z);
        pt[i+3*nSegment].set(x, -y, z);
    }

    numFaces= 4 * nSegment;
    face = new Face[numFaces];

    for(i = 0; i < nSegment; i++)
    {
        // mat tren cung
        face[i].nVerts = 4;
        face[i].vert = new VertexID[face[i].nVerts];
        face[i].vert[0].vertIndex = i;
        face[i].vert[1].vertIndex = i+nSegment;
        if (i + 1 < nSegment) {
            face[i].vert[3].vertIndex = i+1;
            face[i].vert[2].vertIndex = i+nSegment + 1;
        }
        else {
            face[i].vert[3].vertIndex = 0;
            face[i].vert[2].vertIndex = nSegment;
        }
        // mat ngoai cung
        face[i+nSegment].nVerts = 4;
        face[i+nSegment].vert = new VertexID[face[i+nSegment].nVerts];
        face[i+nSegment].vert[0].vertIndex = i;
        face[i+nSegment].vert[1].vertIndex = i+2*nSegment;
        if (i + 1 < nSegment) {
            face[i+nSegment].vert[3].vertIndex = i+1;
            face[i+nSegment].vert[2].vertIndex = i+2*nSegment + 1;
        }
        else {
            face[i+nSegment].vert[3].vertIndex = 0;
            face[i+nSegment].vert[2].vertIndex = 2*nSegment;
        }

        // mat trong cung
        face[i+2*nSegment].nVerts = 4;
        face[i+2*nSegment].vert = new VertexID[face[i+2*nSegment].nVerts];
        face[i+2*nSegment].vert[0].vertIndex = i+nSegment;
        face[i+2*nSegment].vert[1].vertIndex = i+3*nSegment;
        if (i + 1 < nSegment) {
            face[i+2*nSegment].vert[3].vertIndex = i+nSegment+1;
            face[i+2*nSegment].vert[2].vertIndex = i+3*nSegment + 1;
        }
        else {
            face[i+2*nSegment].vert[3].vertIndex = nSegment;
            face[i+2*nSegment].vert[2].vertIndex = 3*nSegment;
        }

        // mat duoi cung
        face[i+3*nSegment].nVerts = 4;
        face[i+3*nSegment].vert = new VertexID[face[i+3*nSegment].nVerts];
        face[i+3*nSegment].vert[0].vertIndex = i+2*nSegment;
        face[i+3*nSegment].vert[1].vertIndex = i+3*nSegment;
        if (i + 1 < nSegment) {
            face[i+3*nSegment].vert[3].vertIndex = i+2*nSegment+1;
            face[i+3*nSegment].vert[2].vertIndex = i+3*nSegment + 1;
        }
        else {
            face[i+3*nSegment].vert[2].vertIndex = 2*nSegment;
            face[i+3*nSegment].vert[3].vertIndex = 3*nSegment;
        }
        for (int j = 0; j < 4; j++) {
            face[i].vert[j].colorIndex = i % COLORNUM;
            face[i+nSegment].vert[j].colorIndex = (i) % COLORNUM;
            face[i+2*nSegment].vert[j].colorIndex = (i) % COLORNUM;
            face[i+3*nSegment].vert[j].colorIndex = (i) % COLORNUM;
        }
    }

}

void Mesh::CreateCylinder(int nSegment, float fHeight, float fRadius)

{
    int i;
    float x, y, z;
    float angle = 2*PI/nSegment;

    numVerts=nSegment*2+2;
    pt = new Point3[numVerts];
    for(i = 0; i<nSegment; i++)
    {
        y = fHeight/2;
        x = fRadius*cos(i*angle);
        z = fRadius*sin(i*angle);
        pt[i].set(x, y, z);
        pt[i+nSegment].set(x, -y, z);
    }

    pt[2*nSegment].set(0, fHeight/2, 0);
    pt[2*nSegment+1].set(0, -fHeight/2, 0);

    numFaces= 3 * nSegment;
    face = new Face[numFaces];

    for(i = 0; i<nSegment; i++)
    {
        face[i].nVerts = 4;
        face[i].vert = new VertexID[face[i].nVerts];
        face[i].vert[0].vertIndex = i;
        face[i].vert[1].vertIndex = i+nSegment;

        face[i+nSegment].nVerts = 3;
        face[i+nSegment].vert = new VertexID[face[i+nSegment].nVerts];
        face[i+nSegment].vert[0].vertIndex = nSegment*2;
        face[i+nSegment].vert[1].vertIndex = i;

        face[i+2*nSegment].nVerts = 3;
        face[i+2*nSegment].vert = new VertexID[face[i+2*nSegment].nVerts];

        face[i+2*nSegment].vert[0].vertIndex = nSegment*2+1;
        face[i+2*nSegment].vert[1].vertIndex = i+nSegment;

        if(i==nSegment-1) {
            face[i].vert[2].vertIndex = nSegment;
            face[i+nSegment].vert[2].vertIndex = 0;
            face[i+2*nSegment].vert[2].vertIndex = 0+nSegment;
        }
        else {
            face[i].vert[2].vertIndex = i+nSegment+1;
            face[i+nSegment].vert[2].vertIndex = i+1;
            face[i+2*nSegment].vert[2].vertIndex = i+1+nSegment;
        }
        if(i==nSegment-1)
            face[i].vert[3].vertIndex = 0;
        else
            face[i].vert[3].vertIndex = i+1;
        for(int j = 0; j<face[i].nVerts ; j++)
            face[i].vert[j].colorIndex = i % COLORNUM;

        for(int j = 0; j<face[i+nSegment].nVerts ; j++)
            face[i+nSegment].vert[j].colorIndex = i % COLORNUM;

        for(int j = 0; j<face[i+2*nSegment].nVerts ; j++)
            face[i+2*nSegment].vert[j].colorIndex = i % COLORNUM;
    }

}

void Mesh::CreateCube(float    fSize)
{
    int i;

    numVerts=8;
    pt = new Point3[numVerts];
    pt[0].set(-fSize, fSize, fSize);
    pt[1].set( fSize, fSize, fSize);
    pt[2].set( fSize, fSize, -fSize);
    pt[3].set(-fSize, fSize, -fSize);
    pt[4].set(-fSize, -fSize, fSize);
    pt[5].set( fSize, -fSize, fSize);
    pt[6].set( fSize, -fSize, -fSize);
    pt[7].set(-fSize, -fSize, -fSize);


    numFaces= 6;
    face = new Face[numFaces];

    //Left face
    face[0].nVerts = 4;
    face[0].vert = new VertexID[face[0].nVerts];
    face[0].vert[0].vertIndex = 1;
    face[0].vert[1].vertIndex = 5;
    face[0].vert[2].vertIndex = 6;
    face[0].vert[3].vertIndex = 2;
    for(i = 0; i<face[0].nVerts ; i++)
        face[0].vert[i].colorIndex = 0;

    //Right face
    face[1].nVerts = 4;
    face[1].vert = new VertexID[face[1].nVerts];
    face[1].vert[0].vertIndex = 0;
    face[1].vert[1].vertIndex = 3;
    face[1].vert[2].vertIndex = 7;
    face[1].vert[3].vertIndex = 4;
    for(i = 0; i<face[1].nVerts ; i++)
        face[1].vert[i].colorIndex = 1;

    //top face
    face[2].nVerts = 4;
    face[2].vert = new VertexID[face[2].nVerts];
    face[2].vert[0].vertIndex = 0;
    face[2].vert[1].vertIndex = 1;
    face[2].vert[2].vertIndex = 2;
    face[2].vert[3].vertIndex = 3;
    for(i = 0; i<face[2].nVerts ; i++)
        face[2].vert[i].colorIndex = 2;

    //bottom face
    face[3].nVerts = 4;
    face[3].vert = new VertexID[face[3].nVerts];
    face[3].vert[0].vertIndex = 7;
    face[3].vert[1].vertIndex = 6;
    face[3].vert[2].vertIndex = 5;
    face[3].vert[3].vertIndex = 4;
    for(i = 0; i<face[3].nVerts ; i++)
        face[3].vert[i].colorIndex = 3;

    //near face
    face[4].nVerts = 4;
    face[4].vert = new VertexID[face[4].nVerts];
    face[4].vert[0].vertIndex = 4;
    face[4].vert[1].vertIndex = 5;
    face[4].vert[2].vertIndex = 1;
    face[4].vert[3].vertIndex = 0;
    for(i = 0; i<face[4].nVerts ; i++)
        face[4].vert[i].colorIndex = 4;

    //Far face
    face[5].nVerts = 4;
    face[5].vert = new VertexID[face[5].nVerts];
    face[5].vert[0].vertIndex = 3;
    face[5].vert[1].vertIndex = 2;
    face[5].vert[2].vertIndex = 6;
    face[5].vert[3].vertIndex = 7;
    for(i = 0; i<face[5].nVerts ; i++)
        face[5].vert[i].colorIndex = 5;

}
void Mesh::CreateTetrahedron()
{
    int i;
    numVerts=4;
    pt = new Point3[numVerts];
    pt[0].set(0, 0, 0);
    pt[1].set(1, 0, 0);
    pt[2].set(0, 1, 0);
    pt[3].set(0, 0, 1);

    numFaces= 4;
    face = new Face[numFaces];

    face[0].nVerts = 3;
    face[0].vert = new VertexID[face[0].nVerts];
    face[0].vert[0].vertIndex = 1;
    face[0].vert[1].vertIndex = 2;
    face[0].vert[2].vertIndex = 3;
    for(i = 0; i<face[0].nVerts ; i++)
        face[0].vert[i].colorIndex = 0;


    face[1].nVerts = 3;
    face[1].vert = new VertexID[face[1].nVerts];
    face[1].vert[0].vertIndex = 0;
    face[1].vert[1].vertIndex = 2;
    face[1].vert[2].vertIndex = 1;
    for(i = 0; i<face[1].nVerts ; i++)
        face[1].vert[i].colorIndex = 1;


    face[2].nVerts = 3;
    face[2].vert = new VertexID[face[2].nVerts];
    face[2].vert[0].vertIndex = 0;
    face[2].vert[1].vertIndex = 3;
    face[2].vert[2].vertIndex = 2;
    for(i = 0; i<face[2].nVerts ; i++)
        face[2].vert[i].colorIndex = 2;


    face[3].nVerts = 3;
    face[3].vert = new VertexID[face[3].nVerts];
    face[3].vert[0].vertIndex = 1;
    face[3].vert[1].vertIndex = 3;
    face[3].vert[2].vertIndex = 0;
    for(i = 0; i<face[3].nVerts ; i++)
        face[3].vert[i].colorIndex = 3;
}

void Mesh::DrawWireframe()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    for (int f = 0; f < numFaces; f++)
    {
        glBegin(GL_POLYGON);
        for (int v = 0; v < face[f].nVerts; v++)
        {
            int        iv = face[f].vert[v].vertIndex;

            glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
        }
        glEnd();
    }
}
void Mesh::DrawPoint()
{
    glPointSize(5);
    glBegin(GL_POINTS);
    for (int v = 0; v < numVerts; v++)
        glVertex3f(pt[v].x, pt[v].y, pt[v].z);

    glEnd();
}

void Mesh::DrawColor()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    for (int f = 0; f < numFaces; f++)
    {
        glBegin(GL_POLYGON);
        for (int v = 0; v < face[f].nVerts; v++)
        {
            int        iv = face[f].vert[v].vertIndex;
            int        ic = face[f].vert[v].colorIndex;

            ic = f % COLORNUM;

            glColor3f(ColorArr[ic][0], ColorArr[ic][1], ColorArr[ic][2]);
            glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
        }
        glEnd();
    }
}

void Mesh::CreateIcosahedron() {
    float t = (sqrt(5.0) - 1) /2.0;
    numVerts = 12;
    pt = new Point3[numVerts];
    pt[0].set(0, 1, t);
    pt[1].set(0, 1, -t);
    pt[2].set(1, t, 0);
    pt[3].set(1, -t, 0);
    pt[4].set(0, -1, -t);
    pt[5].set(0, -1, t);
    pt[6].set(t, 0, 1);
    pt[7].set(-t, 0, 1);
    pt[8].set(t, 0, -1);
    pt[9].set(-t, 0, -1);
    pt[10].set(-1, t, 0);
    pt[11].set(-1, -t, 0);

    numFaces= 20;
    face = new Face[numFaces];
    for (int i = 0; i < numFaces; i++) {
        face[i].nVerts = 3;
    face[i].vert = new VertexID[face[i].nVerts];

        for (int j = 0; j < 3; j++)
            face[i].vert[j].vertIndex = icosahedronVerts[i][j];

        for(int k = 0; k < face[i].nVerts ; k++)
            face[i].vert[k].colorIndex = i % 14;
    }
}

void Mesh::CreateDedocahedron () {
    Mesh icosahedron;
    icosahedron.CreateIcosahedron();

    numVerts = 20;
    pt = new Point3[numVerts];
    float x, y, z;
    for (int i = 0; i < 20; i++) {
        x = (icosahedron.pt[icosahedronVerts[i][0]].x + icosahedron.pt[icosahedronVerts[i][1]].x + icosahedron.pt[icosahedronVerts[i][2]].x)/3;
        y = (icosahedron.pt[icosahedronVerts[i][0]].y + icosahedron.pt[icosahedronVerts[i][1]].y + icosahedron.pt[icosahedronVerts[i][2]].y)/3;
        z = (icosahedron.pt[icosahedronVerts[i][0]].z + icosahedron.pt[icosahedronVerts[i][1]].z + icosahedron.pt[icosahedronVerts[i][2]].z)/3;
        pt[i].set(x, y, z);
    }

    numFaces= 12;
    face = new Face[numFaces];
    for (int i = 0; i < numFaces; i++) {
        face[i].nVerts = 5;
        face[i].vert = new VertexID[face[i].nVerts];

        for (int j = 0; j < 5; j++)
            face[i].vert[j].vertIndex = dedocahedronVerts[i][j];

        for(int k = 0; k < face[i].nVerts ; k++)
            face[i].vert[k].colorIndex = i % 14;
    }
}

void Mesh::CreateTruncatedCube(float fRadius) {
    numVerts = 24;
    pt = new Point3[numVerts];
    //verts on bottom
    pt[0].set(fRadius/2, 0, -fRadius/6);
    pt[1].set(fRadius/2, 0, fRadius/6);
    pt[2].set(fRadius/6, 0, fRadius/2);
    pt[3].set(-fRadius/6, 0, fRadius/2);
    pt[4].set(-fRadius/2, 0, fRadius/6);
    pt[5].set(-fRadius/2, 0, -fRadius/6);
    pt[6].set(-fRadius/6, 0, -fRadius/2);
    pt[7].set(fRadius/6, 0, -fRadius/2);
    // verts on firt layer
    pt[8].set(fRadius/2, fRadius/3, -fRadius/2);
    pt[9].set(fRadius/2, fRadius/3 , fRadius/2);
    pt[10].set(-fRadius/2, fRadius/3, fRadius/2);
    pt[11].set(-fRadius/2, fRadius/3, fRadius/2);
    //verts on second layer
    pt[12].set(-fRadius/2, 2*fRadius/3, -fRadius/2);
    pt[13].set(fRadius/2, 2*fRadius/3, -fRadius/2);
    pt[14].set(fRadius/2, 2*fRadius/3, fRadius/2);
    pt[15].set(-fRadius/2, 2*fRadius/3, fRadius/2);
    //verts on top
    pt[16].set(-fRadius/2, fRadius, fRadius/6);
    pt[17].set(-fRadius/2, fRadius, -fRadius/6);
    pt[18].set(-fRadius/6, fRadius, -fRadius/2);
    pt[19].set(fRadius/6, fRadius, -fRadius/2);
    pt[20].set(fRadius/2, fRadius, -fRadius/6);
    pt[21].set(fRadius/2, fRadius, fRadius/6);
    pt[22].set(fRadius/6, fRadius, fRadius/2);
    pt[23].set(-fRadius/6, fRadius, fRadius/2);

    numFaces= 14;
    face = new Face[numFaces];

    for (int i = 0; i < 6; i++) {
        face[i].nVerts = 8;
        face[i].vert = new VertexID[face[i].nVerts];

        for (int j = 0; j < 8; j++)
            face[i].vert[j].vertIndex = truncatedCubeVerts[i][j];

        for(int k = 0; k < face[i].nVerts ; k++)
            face[i].vert[k].colorIndex = i % 14;
    }

    for (int i = 0; i < 8; i++) {
        face[i+6].nVerts = 3;
        face[i+6].vert = new VertexID[face[i].nVerts];

        for (int j = 0; j < 3; j++)
            face[i+6].vert[j].vertIndex = triangleCubeVerts[i][j];

        for(int k = 0; k < face[i].nVerts ; k++)
            face[i+6].vert[k].colorIndex = (i+6) % 14;
    }
}
