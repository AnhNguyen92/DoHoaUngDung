//
//  Mesh.hpp
//  Lab5-Bai3.1
//
//  Created by ManlyHumg on 11/10/19.
//  Copyright © 2019 ManlyHumg. All rights reserved.
//

#include <stdio.h>

#endif /* Mesh_hpp */
#if !defined (_MESH_CLASS)
#define _MESH_CLASS

#include "supportClass.h"


class VertexID
{
public:
    int        vertIndex;
    int        colorIndex;
};

class Face
{
public:
    int        nVerts;
    VertexID*    vert;
    
    Face()
    {
        nVerts    = 0;
        vert    = NULL;
    }
    ~Face()
    {
        if(vert !=NULL)
        {
            delete[] vert;
            vert = NULL;
        }
        nVerts = 0;
    }
};

class Mesh
{
public:
    int        numVerts;
    Point3*        pt;
    
    int        numFaces;
    Face*        face;
public:
    Mesh()
    {
        numVerts    = 0;
        pt        = NULL;
        numFaces    = 0;
        face        = NULL;
    }
    ~Mesh()
    {
        if (pt != NULL)
        {
            delete[] pt;
        }
        if(face != NULL)
        {
            delete[] face;
        }
        numVerts = 0;
        numFaces = 0;
    }
    void DrawWireframe();
    void DrawColor();
    void DrawPoint();
    void CreateIcosahedron();
    void CreateTetrahedron();
    void CreateDedocahedron();
    void CreateTruncatedCube(float fRadius);
    void CreateCube(float    fSize);
    void CreateCylinder(int nSegment, float fHeight, float fRadius);
    void CreateCylinderWithHole(int nSegment, float fHeight, float fORadius, float fIRadius);
    
};
