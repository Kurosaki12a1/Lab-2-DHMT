// Bai3.cpp : Defines the entry point for the console application.
//

#include "tchar.h"

#include <math.h>
#include <iostream>
#include "supportClass.h"
#include "Mesh.h"
#define DEG2RAD 3.14159f/180.0f

using namespace std;

int		screenWidth = 600;
int		screenHeight = 300;
int angle = 0;
Mesh	tetrahedron;
Mesh	cube;
Mesh	cuboid;
Mesh	holecuboid;
Mesh	pillar;
Mesh	oval;
Mesh	holeoval;
int		nChoice = 1;
//class Circle {
//public:
//	float radius;
//	Point** point;
//	int numPoint;
//	Point* center;
//	Circle(float x, float y, float z, int degree, float radius) {
//		numPoint = 360 / degree;
//		this->radius = radius;
//		point = new Point*[numPoint];
//		center = new Point(x, y, z);
//		for (int i = 0; i < numPoint; i++) {
//			float x = center->x + sin(DEG2RAD * i * degree)*radius;
//			float y = center->y;
//			float z = center->z + cos(DEG2RAD * i * degree)*radius;
//			point[i] = new Point(x, y, z);
//		}
//	}
void setface(Face *face, int nVerts, int faceindex,int vertindex[]) {
	face[faceindex].nVerts = nVerts;
	face[faceindex].vert = new VertexID[face[0].nVerts];
	face[faceindex].vert[0].vertIndex = 1;
	face[faceindex].vert[1].vertIndex = 5;
	face[faceindex].vert[2].vertIndex = 6;
	face[faceindex].vert[3].vertIndex = 2;
	for (int i = 0; i < face[faceindex].nVerts; i++) {
		face[faceindex].vert[i].vertIndex = vertindex[i];
		face[faceindex].vert[i].colorIndex = faceindex;
	}
}
void setrecface(Face *face, int faceindex,int vertindex, int offset) {
	face[faceindex].nVerts = 4;
	face[faceindex].vert = new VertexID[face[faceindex].nVerts];
	face[faceindex].vert[0].vertIndex = vertindex;
	face[faceindex].vert[1].vertIndex = vertindex + 1;
	face[faceindex].vert[2].vertIndex = vertindex + 1 + offset;
	face[faceindex].vert[3].vertIndex = vertindex + offset;
	for (int j = 0; j<face[faceindex].nVerts; j++)
		face[faceindex].vert[j].colorIndex = faceindex;
}
void iterativeSetRecFace(Face *face, int &faceindex, int vertindex, int offset, int iterative) {
	for (int i = 0; i < iterative; i++) {
		setrecface(face, faceindex, vertindex, offset);
		faceindex++;
		vertindex++;
	}
}

/*
void Mesh::CreateHoleCuboid(float	fSizeX, float fSizeY, float	fSizeZ, float thick) {
	int i;
	float x = fSizeX / 2, y = fSizeY / 2, z = fSizeZ / 2;
	float holeX = x +thick, holeY = y, holeZ = z +thick;
	numVerts = 16;
	int outerleftvertindex[4] = { 1,5,6,2 };
	int topleftvertindex[4] = {1,2,10,9};
	int bottomleftvertindex[4] = {5,6,14,13};
	int innerleftvertindex[4] = {9,13,14,10};

	int outerrightvertindex[4] = {0,3,7,4};
	int toprightvertindex[4] = {0,3,11,8};
	int bottomrightvertindex[4] = {4,7,15,12};
	int innerrightvertindex[4] = {8,11,15,12};

	int outernearvertindex[4] = {0,4,5,1};
	int topnearvertindex[4] = {0,1,9,8};
	int bottomnearvertindex[4] = {4,5,13,12};
	int innernearvertindex[4] = {8,9,13,12};

	int outerfarvertindex[4] = {2,3,7,6};
	int topfarvertindex[4] = { 2,3,11,10 };
	int bottomfarvertindex[4] = { 6,7,15,14 };
	int innerfarvertindex[4] = { 10,11,15,14 };
	pt = new Point3[numVerts];
	pt[0].set(-x, y, z);
	pt[1].set(x, y, z);
	pt[2].set(x, y, -z);
	pt[3].set(-x, y, -z);
	pt[4].set(-x, -y, z);
	pt[5].set(x, -y, z);
	pt[6].set(x, -y, -z);
	pt[7].set(-x, -y, -z);
	
	pt[8].set(-holeX, holeY, holeZ);
	pt[9].set(holeX, holeY, holeZ);
	pt[10].set(holeX, holeY, -holeZ);
	pt[11].set(-holeX, holeY, -holeZ);
	pt[12].set(-holeX, -holeY, holeZ);
	pt[13].set(holeX, -holeY, holeZ);
	pt[14].set(holeX, -holeY, -holeZ);
	pt[15].set(-holeX, -holeY, -holeZ);

	numFaces = 16;
	face = new Face[numFaces];

	//Outer Left face
	setface(face, 4, 0, outerleftvertindex);
	//Top Left face
	setface(face, 4, 1, topleftvertindex);
	//Bottom Left face
	setface(face, 4, 2, bottomleftvertindex);
	//Inner Left face
	setface(face, 4, 3, innerleftvertindex);

	//Outer Right face
	setface(face, 4, 4, outerrightvertindex);
	//Top Right face
	setface(face, 4, 5, toprightvertindex);
	//Bottom Right face
	setface(face, 4, 6, bottomrightvertindex);
	//Inner Right face
	setface(face, 4, 7, innerrightvertindex);

	//Outer Near face
	setface(face, 4, 8, outernearvertindex);
	//Top Near face
	setface(face, 4, 9, topnearvertindex);
	//Bottom Near face
	setface(face, 4, 10, bottomnearvertindex);
	//Inner Near face
	setface(face, 4, 11, innernearvertindex);


	//Outer Far face
	setface(face, 4, 12, outerfarvertindex);
	//Top Far face
	setface(face, 4, 13, topfarvertindex);
	//Bottom Far face
	setface(face, 4, 14, bottomfarvertindex);
	//Inner Far face
	setface(face, 4, 15, innerfarvertindex);
}
*/
void Mesh::CreatePillar(float	radius, float height, float degree) {
	numVerts = (360 / degree) * 2 + 2;
	int numVertsSurround = (360 / degree) * 2;
	int bottom_center_index = numVerts - 2;
	int top_center_index = numVerts - 1;
	pt = new Point3[numVerts];
	numFaces = (360 / degree) * 3;
	face = new Face[numFaces];
	//set 2 center points
	pt[bottom_center_index].set(0,-height/2,0);
	pt[top_center_index].set(0, height/2, 0);
	
	//set bottom points
	for (int i = 0; i < numVertsSurround/2; i++) {
		float x = pt[bottom_center_index].x + sin(DEG2RAD * i * degree)*radius;
		float y = pt[bottom_center_index].y;
		float z = pt[bottom_center_index].z + cos(DEG2RAD * i * degree)*radius;
		pt[i].set(x, y, z);
	}
	//set top points
	for (int i = numVertsSurround / 2; i < numVertsSurround; i++) {
		float x = pt[top_center_index].x + sin(DEG2RAD * i * degree)*radius;
		float y = pt[top_center_index].y;
		float z = pt[top_center_index].z + cos(DEG2RAD * i * degree)*radius;
		pt[i].set(x, y, z);
	}

	//set bottom face 
	for (int i = 0; i < numFaces/3; i++) {
		face[i].nVerts = 3;
		face[i].vert = new VertexID[face[i].nVerts];
		if (i == numFaces / 3 - 1) {
			face[i].vert[0].vertIndex = bottom_center_index;
			face[i].vert[1].vertIndex = i;
			face[i].vert[2].vertIndex = 0;
		}
		else {
			face[i].vert[0].vertIndex = bottom_center_index;
			face[i].vert[1].vertIndex = i;
			face[i].vert[2].vertIndex = i + 1;
		}
		for (int j = 0; j<face[i].nVerts; j++)
			face[i].vert[j].colorIndex = i;
	}
	
	//set top face
	for (int i = numFaces/3; i < numFaces * 2 / 3; i++) {
		face[i].nVerts = 3;
		face[i].vert = new VertexID[face[i].nVerts];
		if (i == numFaces * 2 / 3 - 1) {
			face[i].vert[0].vertIndex = top_center_index;
			face[i].vert[1].vertIndex = i;
			face[i].vert[2].vertIndex = numVertsSurround/2;
		}
		else {
			face[i].vert[0].vertIndex = top_center_index;
			face[i].vert[1].vertIndex = i;
			face[i].vert[2].vertIndex = i + 1;
		}
		for (int j = 0; j<face[i].nVerts; j++)
			face[i].vert[j].colorIndex = i;
	}
	//set surround face
	int j;
	j = 0;
	for (int i = numFaces * 2 / 3; i < numFaces; i++) {
		int offset_top_bottom = numVertsSurround / 2;
		face[i].nVerts = 4;
		face[i].vert = new VertexID[face[i].nVerts];
		if (i == numFaces - 1) {
			face[i].vert[0].vertIndex = j;
			face[i].vert[1].vertIndex = 0;
			face[i].vert[2].vertIndex = offset_top_bottom;
			face[i].vert[3].vertIndex = j + offset_top_bottom;
		}
		else {
			face[i].vert[0].vertIndex = j;
			face[i].vert[1].vertIndex = j + 1;
			face[i].vert[2].vertIndex = j + 1 + offset_top_bottom;
			face[i].vert[3].vertIndex = j + offset_top_bottom;
		}
		for (int k = 0; k<face[i].nVerts; k++)
			face[i].vert[k].colorIndex = i;
		j++;
	}
}
void Mesh::CreateOval(float R, float len, float height) {
	int degree = 5;
	numVerts = ((360 / degree)/2 +1)*2*2;
	pt = new Point3[numVerts];
	numFaces = (360 / degree)+4;
	face = new Face[numFaces];
	int counter = 0;
	//set bottom near points
	for (int i = 0; i < numVerts / 4; i++) {
		float x = sin(DEG2RAD * (i * degree - 90))*R;
		float y = -height/2;
		float z = len/2 + cos(DEG2RAD *(i * degree - 90))*R;
		pt[counter].set(z, y, x);
		counter++;
	}
	//set top near points
	for (int i = 0; i < numVerts / 4; i++) {
		float x = sin(DEG2RAD *(i * degree - 90))*R;
		float y = height / 2;
		float z = len / 2 + cos(DEG2RAD *(i * degree -90))*R;
		pt[counter].set(z, y, x);
		counter++;
	}
	//set bottom far points
	for (int i = 0; i < numVerts / 4; i++) {
		float x = sin(DEG2RAD * (i * degree+90))*R;
		float y = -height / 2;
		float z = -len / 2 + cos(DEG2RAD * (i * degree +90))*R;
		pt[counter].set(z, y, x);
		counter++;
	}
	//set top far points
	for (int i = 0; i < numVerts / 4; i++) {
		float x = sin(DEG2RAD * (i * degree +90))*R;
		float y = height / 2;
		float z = -len / 2 + cos(DEG2RAD *(i * degree +90))*R;
		pt[counter].set(z, y, x);
		counter++;
	}
	int offset_top_bottom = numVerts / 4;
	int offset_near_far = numVerts / 2;
	int nearvertindex = 0;
	for (int i = 0; i < (numFaces-4)/2; i++) {
		face[i].nVerts = 4;
		face[i].vert = new VertexID[face[i].nVerts];
		face[i].vert[0].vertIndex = nearvertindex;
		face[i].vert[1].vertIndex = nearvertindex + 1;
		face[i].vert[2].vertIndex = nearvertindex + 1 + offset_top_bottom;
		face[i].vert[3].vertIndex = nearvertindex + offset_top_bottom;
		nearvertindex++;
		for (int j = 0; j<face[i].nVerts; j++)
			face[i].vert[j].colorIndex = i;
	}
	int farvertindex = numVerts / 2;
	for (int i = (numFaces - 4) / 2; i < (numFaces - 4); i++) {
		face[i].nVerts = 4;
		face[i].vert = new VertexID[face[i].nVerts];
		face[i].vert[0].vertIndex = farvertindex;
		face[i].vert[1].vertIndex = farvertindex + 1;
		face[i].vert[2].vertIndex = farvertindex + 1 + offset_top_bottom;
		face[i].vert[3].vertIndex = farvertindex + offset_top_bottom;
		farvertindex++;
		for (int j = 0; j<face[i].nVerts; j++)
			face[i].vert[j].colorIndex = i;
	}
	int rightfacevertindex[4] = { 0,numVerts/4,numVerts-1,numVerts*3/4-1 };
	int leftfacevertindex[4] = { numVerts/4-1,numVerts/2-1,numVerts * 3 / 4 ,numVerts/2};
	setface(face, 4, numFaces - 4, rightfacevertindex);
	setface(face, 4, numFaces - 3, leftfacevertindex);

	//bottom face
	face[numFaces - 2].nVerts = numVerts / 2;
	face[numFaces - 2].vert = new VertexID[face[numFaces - 2].nVerts];
	for (int j = 0; j<numVerts/4; j++) {
		face[numFaces - 2].vert[j].vertIndex = j;
		face[numFaces - 2].vert[j+numVerts/4].vertIndex = j + offset_near_far;
	}
	for (int j = 0; j<face[numFaces - 2].nVerts; j++)
		face[numFaces - 2].vert[j].colorIndex = numFaces - 2;
	//top face
	face[numFaces - 1].nVerts = numVerts / 2;
	face[numFaces - 1].vert = new VertexID[face[numFaces - 1].nVerts];
	for (int j = 0; j<numVerts/4; j++) {
		face[numFaces - 1].vert[j].vertIndex = j+numVerts/4;
		face[numFaces - 1].vert[j + numVerts / 4].vertIndex = j + offset_near_far+numVerts/4;
	}
	for (int j = 0; j<face[numFaces - 1].nVerts; j++)
		face[numFaces - 1].vert[j].colorIndex = numFaces - 1;
}
void Mesh::CreateHoleOval(float outerRadius, float innerRadius, float len, float height) {
	int degree = 5;
	numVerts = ((360 / degree) / 2 + 1) * 2 * 2 * 2;
	pt = new Point3[numVerts];
	numFaces = (360 / degree)*4 + 4*2;
	face = new Face[numFaces];
	int counter = 0;
	int offset_top_bottom = numVerts / 8;
	int offset_near_far = numVerts / 4;
	int offset_outer_inner = numVerts / 2;
	//set bottom near outer points
	for (int i = 0; i < numVerts / 8; i++) {
		float x = sin(DEG2RAD * (i * degree - 90))*outerRadius;
		float y = -height / 2;
		float z = len / 2 + cos(DEG2RAD *(i * degree - 90))*outerRadius;
		pt[counter].set(z, y, x);
		counter++;
	}
	//set top near outer points
	for (int i = 0; i < numVerts / 8; i++) {
		float x = sin(DEG2RAD *(i * degree - 90))*outerRadius;
		float y = height / 2;
		float z = len / 2 + cos(DEG2RAD *(i * degree - 90))*outerRadius;
		pt[counter].set(z, y, x);
		counter++;
	}
	//set bottom far outer points
	for (int i = 0; i < numVerts / 8; i++) {
		float x = sin(DEG2RAD * (i * degree + 90))*outerRadius;
		float y = -height / 2;
		float z = -len / 2 + cos(DEG2RAD * (i * degree + 90))*outerRadius;
		pt[counter].set(z, y, x);
		counter++;
	}
	//set top far outer points
	for (int i = 0; i < numVerts / 8; i++) {
		float x = sin(DEG2RAD * (i * degree + 90))*outerRadius;
		float y = height / 2;
		float z = -len / 2 + cos(DEG2RAD *(i * degree + 90))*outerRadius;
		pt[counter].set(z, y, x);
		counter++;
	}


	//set bottom near inner points
	for (int i = 0; i < numVerts / 8; i++) {
		float x = sin(DEG2RAD * (i * degree - 90))*innerRadius;
		float y = -height / 2;
		float z = len / 2 + cos(DEG2RAD *(i * degree - 90))*innerRadius;
		pt[counter].set(z, y, x);
		counter++;
	}
	//set top near inner points
	for (int i = 0; i < numVerts / 8; i++) {
		float x = sin(DEG2RAD *(i * degree - 90))*innerRadius;
		float y = height / 2;
		float z = len / 2 + cos(DEG2RAD *(i * degree - 90))*innerRadius;
		pt[counter].set(z, y, x);
		counter++;
	}
	//set bottom far inner points
	for (int i = 0; i < numVerts / 8; i++) {
		float x = sin(DEG2RAD * (i * degree + 90))*innerRadius;
		float y = -height / 2;
		float z = -len / 2 + cos(DEG2RAD * (i * degree + 90))*innerRadius;
		pt[counter].set(z, y, x);
		counter++;
	}
	//set top far inner points
	for (int i = 0; i < numVerts / 8; i++) {
		float x = sin(DEG2RAD * (i * degree + 90))*innerRadius;
		float y = height / 2;
		float z = -len / 2 + cos(DEG2RAD *(i * degree + 90))*innerRadius;
		pt[counter].set(z, y, x);
		counter++;
	}
	int facecounter = 0;
	//set surround outer near face
	iterativeSetRecFace(face, facecounter, 0, offset_top_bottom,(numFaces-4*2)/8);

	//set surround outer far face
	iterativeSetRecFace(face, facecounter, offset_near_far, offset_top_bottom, (numFaces - 4 * 2) / 8);

	//set surround inner near face
	iterativeSetRecFace(face, facecounter, offset_outer_inner, offset_top_bottom, (numFaces - 4 * 2) / 8);

	//set surround inner far face
	iterativeSetRecFace(face, facecounter, offset_outer_inner + offset_near_far, offset_top_bottom, (numFaces - 4 * 2) / 8);

	//set bottom surround near face
	iterativeSetRecFace(face, facecounter, 0, offset_outer_inner,(numFaces - 4 * 2) / 8);
	
	//set bottom surround far face
	iterativeSetRecFace(face, facecounter, offset_near_far, offset_outer_inner, (numFaces - 4 * 2) / 8);

	//set top surround near face
	iterativeSetRecFace(face, facecounter, offset_top_bottom, offset_outer_inner, (numFaces - 4 * 2) / 8);

	//set top surround far face
	iterativeSetRecFace(face, facecounter, offset_top_bottom + offset_near_far, offset_outer_inner, (numFaces - 4 * 2) / 8);

	//set top left long face
	int offset_first_last = numVerts/8-1;
	int rightouterfacevertindex[4] = { 0,numVerts / 8,numVerts/2 - 1,numVerts * 3 / 8 - 1 };
	int leftouterfacevertindex[4] = { numVerts / 8 - 1,numVerts / 4 - 1,numVerts * 3 / 8 ,numVerts / 4 };
	int rightinnerfacevertindex[4] = { offset_outer_inner,offset_outer_inner + numVerts / 8,offset_outer_inner + numVerts / 2 - 1,offset_outer_inner + numVerts * 3 / 8 - 1 };
	int leftinnerfacevertindex[4] = { offset_outer_inner + numVerts / 8 - 1,offset_outer_inner + numVerts / 4 - 1,offset_outer_inner + numVerts * 3 / 8 ,offset_outer_inner + numVerts / 4 };
	int bottomrightfacevertindex[4] = { 0,offset_outer_inner,offset_near_far + offset_outer_inner + offset_first_last,offset_near_far+ offset_first_last };
	int bottomleftfacevertindex[4] = { offset_first_last,offset_outer_inner + offset_first_last,offset_near_far + offset_outer_inner,offset_near_far };
	int toprightfacevertindex[4] = { offset_top_bottom,offset_outer_inner + offset_top_bottom,offset_top_bottom+offset_near_far + offset_outer_inner + offset_first_last,offset_top_bottom+offset_near_far + offset_first_last };
	int topleftfacevertindex[4] = { offset_top_bottom + offset_first_last,offset_outer_inner + offset_top_bottom + offset_first_last,offset_top_bottom + offset_near_far + offset_outer_inner,offset_top_bottom + offset_near_far };
	setface(face, 4, facecounter, rightouterfacevertindex);
	facecounter++;
	setface(face, 4, facecounter, leftouterfacevertindex);
	facecounter++;
	setface(face, 4, facecounter, rightinnerfacevertindex);
	facecounter++;
	setface(face, 4, facecounter, leftinnerfacevertindex);
	facecounter++;
	setface(face, 4, facecounter, bottomrightfacevertindex);
	facecounter++;
	setface(face, 4, facecounter, bottomleftfacevertindex);
	facecounter++;
	setface(face, 4, facecounter, toprightfacevertindex);
	facecounter++;
	setface(face, 4, facecounter, topleftfacevertindex);
	facecounter++;
}


void drawAxis()
{
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(4, 0, 0);

	glVertex3f(0, 0, 0);
	glVertex3f(0, 4, 0);

	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 4);
	glEnd();
}
void myDisplay()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(4.5, 4, 2, 0, 0, 0, 0, 1, 0);
	gluLookAt(
		4.5 * cos(DEG2RAD*angle), //eyeX
		4, //eyeY
		4.5 * sin(DEG2RAD*angle), //eyeZ
		0.0, //reference point X
		0, //reference point Y
		0, //reference point Z
		0.0, //up vector X
		1.0, //up vector Y
		0.0 //up vector Z
	);
	//glClearColor(0.1f, 0.7f, 0.7f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, screenWidth / 2, screenHeight);

	drawAxis();

	glColor3f(0, 0, 0);
	if (nChoice == 1)
		tetrahedron.DrawWireframe();
	else if (nChoice == 2)
		cube.DrawWireframe();
	else if (nChoice == 3)
		cuboid.DrawWireframe();
	else if (nChoice == 4)
		holecuboid.DrawWireframe();
	else if (nChoice == 5)
		pillar.DrawWireframe();
	else if (nChoice == 6)
		oval.DrawWireframe();
	else if (nChoice == 7)
		holeoval.DrawWireframe();
	glViewport(screenWidth / 2, 0, screenWidth / 2, screenHeight);

	drawAxis();
	if (nChoice == 1)
		tetrahedron.DrawColor();
	else if (nChoice == 2)
		cube.DrawColor();
	else if (nChoice == 3)
		cuboid.DrawColor();
	else if (nChoice == 4)
		holecuboid.DrawColor();
	else if (nChoice == 5)
		pillar.DrawColor();
	else if (nChoice == 6)
		oval.DrawColor();
	else if (nChoice == 7)
		holeoval.DrawColor();
	glFlush();
	glutSwapBuffers();
}

void myInit()
{
	float	fHalfSize = 4;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);
}
void processTimer(int value) {
	angle += (GLfloat)value;
	if (angle > 360.0f) angle -= 360.0f;
	glutTimerFunc(25, processTimer, value);
	glutPostRedisplay();
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "1. Tetrahedron" << endl;
	cout << "2. Cube" << endl;
	cout << "3. Cuboid" << endl;
	cout << "4. Holecuboid" << endl;
	cout << "5. Pillar" << endl;
	cout << "6. Oval" << endl;
	cout << "7. Holeoval" << endl;
	cout << "Input the choice: " << endl;
	cin >> nChoice;

	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Lab 2"); // open the screen window

	tetrahedron.CreateTetrahedron();
	cube.CreateCube(1);
	cuboid.CreateCuboid(3, 2, 1);
//	holecuboid.CreateHoleCuboid(3, 2, 1, 0.7);
	pillar.CreatePillar(1, 2, 18);
	oval.CreateOval(1, 2, 1);
	holeoval.CreateHoleOval(2, 1, 3, 1);
	myInit();
	glutDisplayFunc(myDisplay);
	glutTimerFunc(25, processTimer, 1);
	glutMainLoop();
	return 0;
}

