
#include "Mesh.h"

#include <math.h>

#define PI			3.1415926
#define	COLORNUM		14


float	ColorArr[COLORNUM][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, { 0.0,  0.0, 1.0}, 
								{1.0, 1.0,  0.0}, { 1.0, 0.0, 1.0},{ 0.0, 1.0, 1.0}, 
								 {0.3, 0.3, 0.3}, {0.5, 0.5, 0.5}, { 0.9,  0.9, 0.9},
								{1.0, 0.5,  0.5}, { 0.5, 1.0, 0.5},{ 0.5, 0.5, 1.0},
									{0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}};





void Mesh::CreateCube(float	fSize)
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
	//red color
	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 5;
	face[0].vert[2].vertIndex = 6;
	face[0].vert[3].vertIndex = 2;
	for(i = 0; i<face[0].nVerts ; i++)
		face[0].vert[i].colorIndex = 0;
	
	//Right face
	//Green Color
	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;
	face[1].vert[1].vertIndex = 3;
	face[1].vert[2].vertIndex = 7;
	face[1].vert[3].vertIndex = 4;
	for(i = 0; i<face[1].nVerts ; i++)
		face[1].vert[i].colorIndex = 1;

	//top face
	//Blue color
	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 2;
	face[2].vert[3].vertIndex = 3;
	for(i = 0; i<face[2].nVerts ; i++)
		face[2].vert[i].colorIndex = 2;

	//bottom face
	//Yellow
	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 7;
	face[3].vert[1].vertIndex = 6;
	face[3].vert[2].vertIndex = 5;
	face[3].vert[3].vertIndex = 4;
	for(i = 0; i<face[3].nVerts ; i++)
		face[3].vert[i].colorIndex = 3;

	//near face
	//Magenta
	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 4;
	face[4].vert[1].vertIndex = 5;
	face[4].vert[2].vertIndex = 1;
	face[4].vert[3].vertIndex = 0;
	for(i = 0; i<face[4].nVerts ; i++)
		face[4].vert[i].colorIndex = 4;

	//Far face
	//Cyan
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
			int		iv = face[f].vert[v].vertIndex;

			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}

void Mesh::DrawColor()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for (int f = 0; f < numFaces; f++)
	{
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++)
		{
			int		iv = face[f].vert[v].vertIndex;
			int		ic = face[f].vert[v].colorIndex;
			
			ic = f % COLORNUM;

			glColor3f(ColorArr[ic][0], ColorArr[ic][1], ColorArr[ic][2]); 
			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}
void Mesh::CreateCuboid(float fSizeX, float fSizeY, float fSizeZ) {
	int i;

	numVerts = 8;
	pt = new Point3[numVerts];
	
	pt[0].set(-fSizeX, fSizeY, fSizeZ);
	pt[1].set(fSizeX, fSizeY, fSizeZ);
	pt[2].set(fSizeX, fSizeY, -fSizeZ);
	pt[3].set(-fSizeX, fSizeY, -fSizeZ);
	pt[4].set(-fSizeX, -fSizeY, fSizeZ);
	pt[5].set(fSizeX, -fSizeY, fSizeZ);
	pt[6].set(fSizeX, -fSizeY, -fSizeZ);
	pt[7].set(-fSizeX, -fSizeY, -fSizeZ);
	

	numFaces = 6;
	face = new Face[numFaces];

	//Left face
	//red color
	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 0;
	face[0].vert[1].vertIndex = 1;
	face[0].vert[2].vertIndex = 2;
	face[0].vert[3].vertIndex = 3;
	for (i = 0; i<face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 0;

	//Right face
	//Green Color
	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 4;
	face[1].vert[1].vertIndex = 5;
	face[1].vert[2].vertIndex = 6;
	face[1].vert[3].vertIndex = 7;
	for (i = 0; i<face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 1;
	
	//top face
	//Blue color
	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 5;
	face[2].vert[3].vertIndex = 4;
	for (i = 0; i<face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 2;
	/**/
	//bottom face
	//Yellow
	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 7;
	face[3].vert[1].vertIndex = 6;
	face[3].vert[2].vertIndex = 2;
	face[3].vert[3].vertIndex = 5;
	for (i = 0; i<face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 3;

	//near face
	//Magenta
	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 4;
	face[4].vert[1].vertIndex = 5;
	face[4].vert[2].vertIndex = 1;
	face[4].vert[3].vertIndex = 0;
	for (i = 0; i<face[4].nVerts; i++)
		face[4].vert[i].colorIndex = 4;

	//Far face
	//Cyan
	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 3;
	face[5].vert[1].vertIndex = 2;
	face[5].vert[2].vertIndex = 6;
	face[5].vert[3].vertIndex = 7;
	for (i = 0; i<face[5].nVerts; i++)
		face[5].vert[i].colorIndex = 5;
		
}
void Mesh :: Pyramid(float fSizeX, float fSizeY, float fSizeZ, float hole)
{
	int i;

	numVerts = 16;
	pt = new Point3[numVerts];

	pt[0].set(fSizeX, -fSizeY, fSizeZ);
	pt[1].set(fSizeX, -fSizeY, -fSizeZ);
	pt[2].set(fSizeX, fSizeY, -fSizeZ);
	pt[3].set(fSizeX, fSizeY, fSizeZ);
	pt[4].set(fSizeX/3*2, -fSizeY/3*2, fSizeZ/3*2);
	pt[5].set(fSizeX/3*2, -fSizeY/3*2, -fSizeZ/3*2);
	pt[6].set(fSizeX/3*2, fSizeY/3*2, -fSizeZ/3*2);
	pt[7].set(fSizeX/3*2, fSizeY/3*2, fSizeZ/3*2);
	pt[12].set(-fSizeX, -fSizeY, fSizeZ);
	pt[13].set(-fSizeX, -fSizeY, -fSizeZ);
	pt[14].set(-fSizeX, fSizeY, -fSizeZ);
	pt[15].set(-fSizeX, fSizeY, fSizeZ);
	pt[8].set(-fSizeX/3*2, -fSizeY/3*2, fSizeZ/3*2);
	pt[9].set(-fSizeX/3*2, -fSizeY/3*2, -fSizeZ/3*2);
	pt[10].set(-fSizeX/3*2, fSizeY/3*2, -fSizeZ/3*2);
	pt[11].set(-fSizeX/3*2, fSizeY/3*2, fSizeZ/3*2);


	numFaces = 18;
	face = new Face[numFaces];

	//Left face
	//red color
	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 0;
	face[0].vert[1].vertIndex =	1;// da doi
	face[0].vert[2].vertIndex = 2;
	face[0].vert[3].vertIndex = 3;
	for (i = 0; i<face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 0;

	//Right face
	//Green Color
	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 4;
	face[1].vert[1].vertIndex = 5;
	face[1].vert[2].vertIndex = 6;//
	face[1].vert[3].vertIndex = 7;
	for (i = 0; i<face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 1;

	//top face
	//Blue color
	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 5;
	face[2].vert[3].vertIndex = 4;
	for (i = 0; i<face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 2;

	//bottom face
	//Yellow
	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 1;//
	face[3].vert[1].vertIndex = 2;
	face[3].vert[2].vertIndex = 6;//
	face[3].vert[3].vertIndex = 5;
	for (i = 0; i<face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 3;

	//near face
	//Magenta
	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 2;
	face[4].vert[1].vertIndex = 3;//
	face[4].vert[2].vertIndex = 7;
	face[4].vert[3].vertIndex = 6;
	for (i = 0; i<face[4].nVerts; i++)
		face[4].vert[i].colorIndex = 4;

	//Far face
	//Cyan
	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 3;
	face[5].vert[1].vertIndex = 0;
	face[5].vert[2].vertIndex = 4;
	face[5].vert[3].vertIndex = 7;//
	for (i = 0; i<face[5].nVerts; i++)
		face[5].vert[i].colorIndex = 5;

	//Left face
	//red color
	face[6].nVerts = 4;
	face[6].vert = new VertexID[face[0].nVerts];
	face[6].vert[0].vertIndex = 12;
	face[6].vert[1].vertIndex = 13;// da doi
	face[6].vert[2].vertIndex = 14;
	face[6].vert[3].vertIndex = 15;
	for (i = 0; i<face[0].nVerts; i++)
		face[6].vert[i].colorIndex = 6;

	//Right face
	//Green Color
	face[7].nVerts = 4;
	face[7].vert = new VertexID[face[1].nVerts];
	face[7].vert[0].vertIndex = 8;
	face[7].vert[1].vertIndex = 9;
	face[7].vert[2].vertIndex = 10;//
	face[7].vert[3].vertIndex = 11;
	for (i = 0; i<face[1].nVerts; i++)
		face[7].vert[i].colorIndex = 7;

	//top face
	//Blue color
	face[8].nVerts = 4;
	face[8].vert = new VertexID[face[2].nVerts];
	face[8].vert[0].vertIndex = 12;
	face[8].vert[1].vertIndex = 13;
	face[8].vert[2].vertIndex = 9;
	face[8].vert[3].vertIndex = 8;
	for (i = 0; i<face[2].nVerts; i++)
		face[8].vert[i].colorIndex = 8;

	//bottom face
	//Yellow
	face[9].nVerts = 4;
	face[9].vert = new VertexID[face[3].nVerts];
	face[9].vert[0].vertIndex = 13;//
	face[9].vert[1].vertIndex = 14;
	face[9].vert[2].vertIndex = 10;//
	face[9].vert[3].vertIndex = 9;
	for (i = 0; i<face[3].nVerts; i++)
		face[9].vert[i].colorIndex = 9;

	//near face
	//Magenta
	face[10].nVerts = 4;
	face[10].vert = new VertexID[face[4].nVerts];
	face[10].vert[0].vertIndex = 14;
	face[10].vert[1].vertIndex = 10;//
	face[10].vert[2].vertIndex = 11;
	face[10].vert[3].vertIndex = 15;
	for (i = 0; i<face[4].nVerts; i++)
		face[10].vert[i].colorIndex = 0;

	//Far face
	//Cyan
	face[11].nVerts = 4;
	face[11].vert = new VertexID[face[5].nVerts];
	face[11].vert[0].vertIndex = 15;
	face[11].vert[1].vertIndex = 12;
	face[11].vert[2].vertIndex = 8;
	face[11].vert[3].vertIndex = 11;//
	for (i = 0; i<face[5].nVerts; i++)
		face[11].vert[i].colorIndex = 5;

	face[13].nVerts = 4;
	face[13].vert = new VertexID[face[5].nVerts];
	face[13].vert[0].vertIndex = 13;
	face[13].vert[1].vertIndex = 14;
	face[13].vert[2].vertIndex = 2;
	face[13].vert[3].vertIndex = 1;//
	for (i = 0; i<face[5].nVerts; i++)
		face[13].vert[i].colorIndex = 6;

	face[12].nVerts = 4;
	face[12].vert = new VertexID[face[5].nVerts];
	face[12].vert[0].vertIndex = 12;
	face[12].vert[1].vertIndex = 0;
	face[12].vert[2].vertIndex = 3;
	face[12].vert[3].vertIndex = 15;//
	for (i = 0; i<face[5].nVerts; i++)
		face[12].vert[i].colorIndex = 7;

	face[14].nVerts = 4;
	face[14].vert = new VertexID[face[5].nVerts];
	face[14].vert[0].vertIndex = 15;
	face[14].vert[1].vertIndex = 3;
	face[14].vert[2].vertIndex = 7;
	face[14].vert[3].vertIndex = 11;//
	for (i = 0; i<face[5].nVerts; i++)
		face[14].vert[i].colorIndex = 1;

	face[15].nVerts = 4;
	face[15].vert = new VertexID[face[5].nVerts];
	face[15].vert[0].vertIndex = 8;
	face[15].vert[1].vertIndex = 11;
	face[15].vert[2].vertIndex = 7;
	face[15].vert[3].vertIndex = 4;//
	for (i = 0; i<face[5].nVerts; i++)
		face[15].vert[i].colorIndex = 2;

	face[16].nVerts = 4;
	face[16].vert = new VertexID[face[5].nVerts];
	face[16].vert[0].vertIndex = 10;
	face[16].vert[1].vertIndex = 6;
	face[16].vert[2].vertIndex = 2;
	face[16].vert[3].vertIndex = 14;//
	for (i = 0; i<face[5].nVerts; i++)
		face[16].vert[i].colorIndex = 3;

	

	face[17].nVerts = 4;
	face[17].vert = new VertexID[face[5].nVerts];
	face[17].vert[0].vertIndex = 9;
	face[17].vert[1].vertIndex = 10;
	face[17].vert[2].vertIndex = 6;
	face[17].vert[3].vertIndex = 5;//
	for (i = 0; i<face[5].nVerts; i++)
		face[17].vert[i].colorIndex = 5;

}

void Mesh::Cylinder(float fSizeX, float fSizeY, float fsizeZ, float R, float len) {

}
