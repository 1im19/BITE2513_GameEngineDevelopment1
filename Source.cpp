#include <iostream>
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
static GLfloat theta[] = { 0.0, 0.0, 0.0 };
static GLint axis = 2;
using namespace std;
//Called when a key is pressed
void handleKeypress1(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		exit(0);
	}
}
//Initializes 3D rendering
void initRendering1() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
}
//Called when the window is resized
void handleResize1(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
float _angle = -70.0f;
//Draws the 3D scene
void drawScene1() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -8.0f);
	//Add ambient light
	GLfloat ambientColor[] = { 1.2f, 0.2f, 0.2f, 1.0f }; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	//Add positioned light
	GLfloat lightColor0[] = { 0.5f, 0.5f, 0.5f, 1.0f }; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = { 4.0f, 0.0f, 8.0f, 1.0f }; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	//Add directed light
	GLfloat lightColor1[] = { 0.5f, 0.2f, 0.2f, 1.0f }; //Color (0.5, 0.2, 0.2)
	//Cube1
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = { -1.0f, 0.5f, 0.5f, 0.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	//Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	//Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	//Cube2
	glColor3f(2.0f, 2.0f, 1.0f);
	//Front
	glNormal3f(5.0f, 0.0f, 1.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, 1.0f, 1.5f);
	//Right
	glNormal3f(6.0f, 0.0f, 0.0f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(6.5f, -1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(6.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, -1.0f, 1.5f);
	//Back
	glNormal3f(1.0f, 0.0f, -1.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, -1.0f, -1.5f);
	//Left
	glNormal3f(5.0f, 0.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, -1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, 1.0f, -1.5f);
	//Top
	glNormal3f(5.0f, 1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, 1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, 1.0f, -1.5f);
	//Bottom
	glNormal3f(5.0f, -1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, -1.0f, -1.5f);
	//Cube3
	glColor3f(3.0f, 3.0f, 2.0f);
	//Front
	glNormal3f(-5.0f, 0.0f, 1.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, 1.0f, 1.5f);
	//Right
	glNormal3f(-5.0f, 0.0f, 0.0f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(-4.5f, -1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(-4.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, -1.0f, 1.5f);
	//Back
	glNormal3f(-5.0f, 0.0f, -1.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-6.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-6.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(-4.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(-4.5f, -1.0f, -1.5f);
	//Left
	glNormal3f(-5.0f, 0.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-6.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, -1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-6.5f, 1.0f, -1.5f);
	//Top
	glNormal3f(-5.0f, 1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, 1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, 1.0f, -1.5f);
	//Bottom
	glNormal3f(-5.0f, -1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, -1.0f, -1.5f);
	glEnd();
	glutSwapBuffers();
}
void update1(int value) {
	_angle += 1.5f;
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update1, 0);
}
int Lab1_1(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	//Create the window
	glutCreateWindow("Create Box with Lighting");
	initRendering1();
	//Set handler functions
	glutDisplayFunc(drawScene1);
	glutKeyboardFunc(handleKeypress1);
	glutReshapeFunc(handleResize1);
	glutTimerFunc(25, update1, 0); //Add a timer
	glutMainLoop();
	return 0;
}

//Called when a key is pressed
void handleKeypress2(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		exit(0);
	}
}
//Initializes 3D rendering
void initRendering2() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
}
//Called when the window is resized
void handleResize2(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

//Draws the 3D scene
void drawScene2() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -8.0f);
	//Add ambient light
	GLfloat ambientColor[] = { 1.2f, 0.2f, 0.2f, 1.0f }; //Color (0.2, 0.2,0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	//Add positioned light
	GLfloat lightColor0[] = { 0.5f, 0.5f, 0.5f, 1.0f }; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = { 4.0f, 0.0f, 8.0f, 1.0f }; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	//Add directed light
	GLfloat lightColor1[] = { 0.5f, 0.2f, 0.2f, 1.0f }; //Color (0.5, 0.2, 0.2)
	//Cube1
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = { -1.0f, 0.5f, 0.5f, 0.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	//glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	//Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	//Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	//Cube2
	glColor3f(2.0f, 2.0f, 1.0f);
	//Front
	glNormal3f(5.0f, 0.0f, 1.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, 1.0f, 1.5f);
	//Right
	glNormal3f(6.0f, 0.0f, 0.0f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(6.5f, -1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(6.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, -1.0f, 1.5f);
	//Back
	glNormal3f(1.0f, 0.0f, -1.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, -1.0f, -1.5f);
	//Left
	glNormal3f(5.0f, 0.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, -1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(4.5f, 1.0f, -1.5f);
	//Top
	glNormal3f(5.0f, 1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, 1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, 1.0f, -1.5f);
	//Bottom
	glNormal3f(5.0f, -1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(6.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(4.5f, -1.0f, -1.5f);
	//Cube3
	glColor3f(3.0f, 3.0f, 2.0f);
	//Front
	glNormal3f(-5.0f, 0.0f, 1.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, 1.0f, 1.5f);
	//Right
	glNormal3f(-5.0f, 0.0f, 0.0f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(-4.5f, -1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(-4.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, -1.0f, 1.5f);
	//Back
	glNormal3f(-5.0f, 0.0f, -1.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-6.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-6.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(-4.5f, 1.0f, -1.5f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(-4.5f, -1.0f, -1.5f);
	//Left
	glNormal3f(-5.0f, 0.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-6.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, -1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, 1.0f, 1.5f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-6.5f, 1.0f, -1.5f);
	//Top
	glNormal3f(-5.0f, 1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, 1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, 1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, 1.0f, -1.5f);
	//Bottom
	glNormal3f(-5.0f, -1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, -1.0f, 1.5f);
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-4.5f, -1.0f, -1.5f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-6.5f, -1.0f, -1.5f);
	glEnd();
	glutSwapBuffers();
}
void update2(int value) {
	_angle += 1.5f;
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update2, 0);
}
void spinCube2()
{
	/* idle callback, spin cube 2 degrees about selected axis */
	theta[axis] += 0.5;
	if (theta[axis] > 360.0) theta[axis] -= 360.0;
	/* display(); */
	glutPostRedisplay();
}
void mouse2(int btn, int state, int x, int y)
{
	/* mouse callback, selects an axis about which to rotate */
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}

int Lab1_2(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	//Create the window
	glutCreateWindow("Create Box with Lighting");
	initRendering2();
	//Set handler functions
	glutDisplayFunc(drawScene2);
	glutKeyboardFunc(handleKeypress2);
	glutReshapeFunc(handleResize2);
	glutIdleFunc(spinCube2);
	glutMouseFunc(mouse2);
	glutTimerFunc(25, update2, 0); //Add a timer
	glutMainLoop();
	return 0;
}

GLuint texture; //the array for our texture
GLfloat angle3 = 0.0;
//function to load the RAW file
GLuint LoadTexture3(const char* filename, int width, int height)
{
	GLuint texture;
	unsigned char* data;
	FILE* file;
	//The following code will read in our RAW file
	file = fopen(filename, "rb");
	if (file == NULL) return 0;
	data = (unsigned char*)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);
	glGenTextures(1, &texture); //generate the texture with the loaded data
	glBindTexture(GL_TEXTURE_2D, texture); //bind the textureto it’s array
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //set texture	environment parameters
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//Generate the texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
		GL_UNSIGNED_BYTE, data);
	free(data); //free the texture
	return texture; //return whether it was successfull
}

void FreeTexture3(GLuint texture)
{
	glDeleteTextures(1, &texture);
}

void square3(void)
{
	glBindTexture(GL_TEXTURE_2D, texture);
	glRotatef(angle3, 1.0f, 1.0f, 1.0f);
	/*
	glBegin(GL_QUADS);
	glTexCoord2d(0.0, 0.0); glVertex2d(-1.0, -1.0);
	glTexCoord2d(1.0, 0.0); glVertex2d(+1.0, -1.0);
	glTexCoord2d(1.0, 1.0); glVertex2d(+1.0, +1.0);
	glTexCoord2d(0.0, 1.0); glVertex2d(-1.0, +1.0);
	glEnd();
	*/
	//Square 1
	//Multi-colored side - FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	// P1 is red
	glColor3f(0.0, 1.0, 0.0); 
	glVertex3f(0.5, 0.5, -0.5);
	// P2 is green
	glColor3f(0.0, 0.0, 1.0); 
	glVertex3f(-0.5, 0.5, -0.5);
	// P3 is blue
	glColor3f(1.0, 0.0, 1.0); 
	glVertex3f(-0.5, -0.5, -0.5);
	// P4 is purple
	glEnd();
	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
	// Blue side - TOP
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();
	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
	//Square 2
	//Multi-colored side - FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.5, -0.5, -0.5);
	// P1 is red
	glColor3f(0.0, 1.0, 0.0); 
	glVertex3f(2.5, 0.5, -0.5);
	// P2 is green
	glColor3f(0.0, 0.0, 1.0); 
	glVertex3f(1.5, 0.5, -0.5);
	// P3 is blue
	glColor3f(1.0, 0.0, 1.0); 
	glVertex3f(1.5, -0.5, -0.5);
	// P4 is purple
	glEnd();
	// Purple side - BACK
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(2.5, -0.5, 0.5);
	glVertex3f(2.5, 0.5, 0.5);
	glVertex3f(1.5, 0.5, 0.5);
	glVertex3f(1.5, -0.5, 0.5);
	glEnd();
	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(2.5, -0.5, -0.5);
	glVertex3f(2.5, 0.5, -0.5);
	glVertex3f(2.5, 0.5, 0.5);
	glVertex3f(2.5, -0.5, 0.5);
	glEnd();
	// White side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(1.5, -0.5, 0.5);
	glVertex3f(1.5, 0.5, 0.5);
	glVertex3f(1.5, 0.5, -0.5);
	glVertex3f(1.5, -0.5, -0.5);
	glEnd();
	// Red side - TOP
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.5, 0.5, 0.5);
	glVertex3f(2.5, 0.5, -0.5);
	glVertex3f(2.5, 0.5, -0.5);
	glVertex3f(2.5, 0.5, 0.5);
	glEnd();
	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.5, -0.5, -0.5);
	glVertex3f(2.5, -0.5, 0.5);
	glVertex3f(1.5, -0.5, 0.5);
	glVertex3f(1.5, -0.5, -0.5);
	glEnd();
	//Square 3
	//Multi-colored side - FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(4.5, -0.5, -0.5);
	// P1 is red
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(4.5, 0.5, -0.5);
	// P2 is green
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(3.5, 0.5, -0.5);
	// P3 is blue
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(3.5, -0.5, -0.5);
	// P4 is purple
	glEnd();
	// Purple side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(4.5, -0.5, 0.5);
	glVertex3f(4.5, 0.5, 0.5);
	glVertex3f(3.5, 0.5, 0.5);
	glVertex3f(3.5, -0.5, 0.5);
	glEnd();
	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(4.5, -0.5, -0.5);
	glVertex3f(4.5, 0.5, -0.5);
	glVertex3f(4.5, 0.5, 0.5);
	glVertex3f(4.5, -0.5, 0.5);
	glEnd();
	// Purple side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(3.5, -0.5, 0.5);
	glVertex3f(3.5, 0.5, 0.5);
	glVertex3f(3.5, 0.5, -0.5);
	glVertex3f(3.5, -0.5, -0.5);
	glEnd();
	// Red side - TOP
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(4.5, 0.5, 0.5);
	glVertex3f(4.5, 0.5, -0.5);
	glVertex3f(4.5, 0.5, -0.5);
	glVertex3f(4.5, 0.5, 0.5);
	glEnd();
	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(4.5, -0.5, -0.5);
	glVertex3f(4.5, -0.5, 0.5);
	glVertex3f(3.5, -0.5, 0.5);
	glVertex3f(3.5, -0.5, -0.5);
	glEnd();
	//Square 4
	//Multi-colored side - FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.5, -2.5, -0.5);
	// P1 is red
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(2.5, -1.5, -0.5);
	// P2 is green
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.5, -1.5, -0.5);
	// P3 is blue
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(1.5, -2.5, -0.5);
	// P4 is purple
	glEnd();
	// Green side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(2.5, -2.5, 0.5);
	glVertex3f(2.5, -1.5, 0.5);
	glVertex3f(1.5, -1.5, 0.5);
	glVertex3f(1.5, -2.5, 0.5);
	glEnd();
	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(2.5, -2.5, -0.5);
	glVertex3f(2.5, -1.5, -0.5);
	glVertex3f(2.5, -1.5, 0.5);
	glVertex3f(2.5, -2.5, 0.5);
	glEnd();
	// Purple side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(1.5, -2.5, 0.5);
	glVertex3f(1.5, -1.5, 0.5);
	glVertex3f(1.5, -1.5, -0.5);
	glVertex3f(1.5, -2.5, -0.5);
	glEnd();
	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(2.5, -1.5, 0.5);
	glVertex3f(2.5, -1.5, -0.5);
	glVertex3f(2.5, -1.5, -0.5);
	glVertex3f(2.5, -1.5, 0.5);
	glEnd();
	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.5, -2.5, -0.5);
	glVertex3f(2.5, -2.5, 0.5);
	glVertex3f(1.5, -2.5, 0.5);
	glVertex3f(1.5, -2.5, -0.5);
	glEnd();
	//Square 5
	//Multi-colored side - FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(4.5, -2.5, -0.5);
	// P1 is red
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(4.5, -1.5, -0.5);
	// P2 is green
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(3.5, -1.5, -0.5);
	// P3 is blue
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(3.5, -2.5, -0.5);
	// P4 is purple
	glEnd();
	// Purple side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(4.5, -2.5, 0.5);
	glVertex3f(4.5, -1.5, 0.5);
	glVertex3f(3.5, -1.5, 0.5);
	glVertex3f(3.5, -2.5, 0.5);
	glEnd();
	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(4.5, -2.5, -0.5);
	glVertex3f(4.5, -1.5, -0.5);
	glVertex3f(4.5, -1.5, 0.5);
	glVertex3f(4.5, -2.5, 0.5);
	glEnd();
	// White side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(3.5, -2.5, 0.5);
	glVertex3f(3.5, -1.5, 0.5);
	glVertex3f(3.5, -1.5, -0.5);
	glVertex3f(3.5, -2.5, -0.5);
	glEnd();
	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(4.5, -1.5, 0.5);
	glVertex3f(4.5, -1.5, -0.5);
	glVertex3f(4.5, -1.5, -0.5);
	glVertex3f(4.5, -1.5, 0.5);
	glEnd();
	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(4.5, -2.5, -0.5);
	glVertex3f(4.5, -2.5, 0.5);
	glVertex3f(3.5, -2.5, 0.5);
	glVertex3f(3.5, -2.5, -0.5);
	glEnd();
}

void display3(void)
{
	// Global Variables	
	double rotate_y = 0;
	double rotate_x = 0;
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	square3();
	glutSwapBuffers();
	//angle = angle + 0.05;
	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
}
void specialKeys3(int key, int x, int y)
{
	// Global Variables	
	double rotate_y = 0;
	double rotate_x = 0;
	// Right arrow - increase rotation by 5 
	if (key == GLUT_KEY_RIGHT)
	{
		rotate_y += 5;
	}
	// Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
	{
		rotate_y -= 5;
	}
	else if (key == GLUT_KEY_UP)
	{
		rotate_x += 5;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		rotate_x -= 5;
	}
	// Request display update
	glutPostRedisplay();
}
void reshape3(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}
int Lab2_1(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("A basic OpenGL Window");
	glutDisplayFunc(display3);
	glutIdleFunc(display3);
	glutReshapeFunc(reshape3);
	//Load our texture
	texture = LoadTexture3("texture.bmp", 256, 256);
	glutMainLoop();
	//Free our texture
	FreeTexture3(texture);
	glEnable(GL_DEPTH_TEST);
	glutSpecialFunc(specialKeys3);
	return 0;
}

//angle of rotation
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle4 = 0.0;
float colorrandom4 = 0;
//positions of the cubes
float positionz[10];
float positionx[10];
void cubepositions4(void) { //set the positions of the cubes
	for (int i = 0; i < 10; i++)
	{
		positionz[i] = rand() % 5 + 5;
		positionx[i] = rand() % 5 + 5;
		colorrandom4 = rand() / (float)RAND_MAX;
		cout << colorrandom4 << endl;
		glColor3f(colorrandom4, colorrandom4, colorrandom4);
	}
}
//draw the cube
void cube4(void) {
	for (int i = 0; i < 10; i++)
	{
		glPushMatrix();
		glTranslated(-positionx[i + 1] * 10, 0, -positionz[i + 1] * 10); //translate the cube
		glutSolidCube(2); //draw the cube
		glPopMatrix();
	}
}
void init4(void) {
	cubepositions4();
}
void enable4(void) {
	glEnable(GL_DEPTH_TEST); //enable the depth testing
	glEnable(GL_LIGHTING); //enable the lighting
	glEnable(GL_LIGHT0); //enable LIGHT0, our Diffuse Light
	glShadeModel(GL_SMOOTH); //set the shader to smooth shader
}
void camera4(void) {
	glRotatef(xrot, 1.0, 0.0, 0.0); //rotate our camera on teh x - axis(left and right)
	glRotatef(yrot, 0.0, 1.0, 0.0); //rotate our camera on the y - axis(up and down)
	glTranslated(-xpos, -ypos, -zpos); //translate the screento the position of our camera
}
void display4(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0); //clear the screen to black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the color bufferand the depth buffer
	glLoadIdentity();
	camera4();
	enable4();
	cube4(); //call the cube drawing function
	glutSwapBuffers(); //swap the buffers
	angle4++; //increase the angle
}
void reshape4(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
	glMatrixMode(GL_PROJECTION); //set the matrix to projection
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 1000.0); //set the perspective(angle of sight, width, height, , depth)
	glMatrixMode(GL_MODELVIEW); //set the matrix back to model
}
void keyboard4(unsigned char key, int x, int y) {
	if (key == 'q')
	{
		xrot += 1;
		if (xrot > 360) xrot -= 360;
	}
	if (key == 'z')
	{
		xrot -= 1;
		if (xrot < -360) xrot += 360;
	}
	if (key == 'w')
	{
		float xrotrad, yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f);
		xpos += float(sin(yrotrad));
		zpos -= float(cos(yrotrad));
		ypos -= float(sin(xrotrad));
	}
	if (key == 's')
	{
		float xrotrad, yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f);
		xpos -= float(sin(yrotrad));
		zpos += float(cos(yrotrad));
		ypos += float(sin(xrotrad));
	}
	if (key == 'd')
	{
		yrot += 1;
		if (yrot > 360) yrot -= 360;
	}
	if (key == 'a')
	{
		yrot -= 1;
		if (yrot < -360)yrot += 360;
	}
	if (key == 27)
	{
		exit(0);
	}
}
void Lab2_2(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); //set the display to Double buffer, with depth
	glutInitWindowSize(500, 500); //set the window size
	glutInitWindowPosition(100, 100); //set the position of the window
	glutCreateWindow("A basic OpenGL Window"); //the captionof the window
	init4(); //call the init function
	glutDisplayFunc(display4); //use the display function to draw everything
	glutIdleFunc(display4); //update any variables in display,display can be changed to anyhing, as long as you move thevariables to be updated, in this case,
	angle4++;
	glutReshapeFunc(reshape4); //reshape the window accordingly
	glutKeyboardFunc(keyboard4); //check the keyboard
	glutMainLoop(); //call the main loop
}

// function to convert decimal to binary 
void decToBinary(int dectobin)
{
	// array to store binary number 
	int binaryNum[32];
	// counter for binary array 
	int i = 0;
	while (dectobin > 0) {
		// storing remainder in binary array 
		binaryNum[i] = dectobin % 2;
		dectobin = dectobin / 2;
		i++;
	}
	// printing binary array in reverse order 
	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}

// function to convert decimal to hexadecimal 
void decToHexa(int dectohex)
{
	// char array to store hexadecimal number 
	char hexaDeciNum[100];
	// counter for hexadecimal number array 
	int i = 0;
	while (dectohex != 0)
	{
		// temporary variable to store remainder 
		int temp1 = 0;
		// storing remainder in temp variable. 
		temp1 = dectohex % 16;
		// check if temp < 10 
		if (temp1 < 10)
		{
			hexaDeciNum[i] = temp1 + 48;
			i++;
		}
		else
		{
			hexaDeciNum[i] = temp1 + 55;
			i++;
		}
		dectohex = dectohex / 16;
	}
	// printing hexadecimal number array in reverse order 
	for (int j = i - 1; j >= 0; j--)
		cout << hexaDeciNum[j];
}

// function to convert 
// Hexadecimal to Binary Number 
void HexToBin(string hexbin)
{
	long int i = 0;
	while (hexbin[i]) {
		switch (hexbin[i]) {
		case '0':
			cout << "0000";
			break;
		case '1':
			cout << "0001";
			break;
		case '2':
			cout << "0010";
			break;
		case '3':
			cout << "0011";
			break;
		case '4':
			cout << "0100";
			break;
		case '5':
			cout << "0101";
			break;
		case '6':
			cout << "0110";
			break;
		case '7':
			cout << "0111";
			break;
		case '8':
			cout << "1000";
			break;
		case '9':
			cout << "1001";
			break;
		case 'A':
		case 'a':
			cout << "1010";
			break;
		case 'B':
		case 'b':
			cout << "1011";
			break;
		case 'C':
		case 'c':
			cout << "1100";
			break;
		case 'D':
		case 'd':
			cout << "1101";
			break;
		case 'E':
		case 'e':
			cout << "1110";
			break;
		case 'F':
		case 'f':
			cout << "1111";
			break;
		default:
			cout << "\nInvalid hexadecimal digit "
				<< hexbin[i];
		}
		i++;
	}
}

void BintoHex(string binhex)
{
	int i = 0;
	if (binhex.length() % 4 == 0)
	{
		while(binhex[i])
		{
			if (binhex[i] == '0' && binhex[i + 1] == '0' && binhex[i + 2] == '0' && binhex[i + 3] == '0')
			{
				cout << "0";
			}
			else if (binhex[i] == '0' && binhex[i + 1] == '0' && binhex[i + 2] == '0' && binhex[i + 3] == '1')
			{
				cout << "1";
			}
			else if (binhex[i] == '0' && binhex[i + 1] == '0' && binhex[i + 2] == '1' && binhex[i + 3] == '0')
			{
				cout << "2";
			}
			else if (binhex[i] == '0' && binhex[i + 1] == '0' && binhex[i + 2] == '1' && binhex[i + 3] == '1')
			{
				cout << "3";
			}
			else if (binhex[i] == '0' && binhex[i + 1] == '1' && binhex[i + 2] == '0' && binhex[i + 3] == '0')
			{
				cout << "4";
			}
			else if (binhex[i] == '0' && binhex[i + 1] == '1' && binhex[i + 2] == '0' && binhex[i + 3] == '1')
			{
				cout << "5";
			}
			else if (binhex[i] == '0' && binhex[i + 1] == '1' && binhex[i + 2] == '1' && binhex[i + 3] == '0')
			{
				cout << "6";
			}
			else if (binhex[i] == '0' && binhex[i + 1] == '1' && binhex[i + 2] == '1' && binhex[i + 3] == '1')
			{
				cout << "7";
			}
			else if (binhex[i] == '1' && binhex[i + 1] == '0' && binhex[i + 2] == '0' && binhex[i + 3] == '0')
			{
				cout << "8";
			}
			else if (binhex[i] == '1' && binhex[i + 1] == '0' && binhex[i + 2] == '0' && binhex[i + 3] == '1')
			{
				cout << "9";
			}
			else if (binhex[i] == '1' && binhex[i + 1] == '0' && binhex[i + 2] == '1' && binhex[i + 3] == '0')
			{
				cout << "A";
			}
			else if (binhex[i] == '1' && binhex[i + 1] == '0' && binhex[i + 2] == '1' && binhex[i + 3] == '1')
			{
				cout << "B";
			}
			else if (binhex[i] == '1' && binhex[i + 1] == '1' && binhex[i + 2] == '0' && binhex[i + 3] == '0')
			{
				cout << "C";
			}
			else if (binhex[i] == '1' && binhex[i + 1] == '1' && binhex[i + 2] == '0' && binhex[i + 3] == '1')
			{
				cout << "D";
			}
			else if (binhex[i] == '1' && binhex[i + 1] == '1' && binhex[i + 2] == '1' && binhex[i + 3] == '0')
			{
				cout << "E";
			}
			else if (binhex[i] == '1' && binhex[i + 1] == '1' && binhex[i + 2] == '1' && binhex[i + 3] == '1')
			{
				cout << "F";
			}

			i += 4;
		}
		cout << endl;
	}
	else
	{
		cout << "Invalid Input" << endl;
	}
}

void BintoDec(string bintodec)
{
	int digitlength = bintodec.length();
	int digit[100] = {};
	int answer = 0;
	int i = 0;

	while (bintodec[i])
	{

		if (bintodec[i] == '1')
		{
			digit[i] = 1;
		}
		else if (bintodec[i] == '0')
		{
			digit[i] = 0;
		}
		else
		{
			cout << "Invalid Input" << endl;
			break;
		}

		answer += digit[i] * pow (2, digitlength - 1);
		i++;
		digitlength--;
	}

	cout << answer << endl;
}

void HextoDec(string hexdec)
{
	int digitlength = hexdec.length();
	int answer = 0;
	int i = 0;
	while (hexdec[i]) {
		switch (hexdec[i]) {
		case '0':
			answer += 0 * pow (16, digitlength - 1);
			break;
		case '1':
			answer += 1 * pow (16, digitlength - 1);
			break;
		case '2':
			answer += 2 * pow (16, digitlength - 1);
			break;
		case '3':
			answer += 3 * pow (16, digitlength - 1);
			break;
		case '4':
			answer += 4 * pow (16, digitlength - 1);
			break;
		case '5':
			answer += 5 * pow (16, digitlength - 1);
			break;
		case '6':
			answer += 6 * pow (16, digitlength - 1);
			break;
		case '7':
			answer += 7 * pow (16, digitlength - 1);
			break;
		case '8':
			answer += 8 * pow (16, digitlength - 1);
			break;
		case '9':
			answer += 9 * pow (16, digitlength - 1);
			break;
		case 'A':
		case 'a':
			answer += 10 * pow (16, digitlength - 1);
			break;
		case 'B':
		case 'b':
			answer += 11 * pow (16, digitlength - 1);
			break;
		case 'C':
		case 'c':
			answer += 12 * pow (16, digitlength - 1);
			break;
		case 'D':
		case 'd':
			answer += 13 * pow (16, digitlength - 1);
			break;
		case 'E':
		case 'e':
			answer += 14 * pow (16, digitlength - 1);
			break;
		case 'F':
		case 'f':
			answer += 15 * pow (16, digitlength - 1);
			break;
		default:
			cout << "\nInvalid hexadecimal digit "
				<< hexdec[i];
		}
		digitlength--;
		i++;
	}
	cout << answer << endl;
}

void Lab1(int argc, char** argv)
{
	int exercisechoice1;
	do
	{
		cout << "\t\t\tLab 1 - C++ Programming with OpenGL\t\t\t" << endl << endl;
		cout << "\n Please insert an exercise ranging from 1 to 2, or other number to cancel: ";
		cin >> exercisechoice1;
		if (exercisechoice1 == 1)
		{
			cout << "\n";
			Lab1_1(argc, argv);
			cout << "\n";
		}
		else if (exercisechoice1 == 2)
		{
			cout << "\n";
			Lab1_2(argc, argv);
			cout << "\n";
		}
	} while (exercisechoice1 >= 1 && exercisechoice1 <= 2);
}

void Lab2(int argc, char** argv)
{
	int exercisechoice2;
	do
	{
		cout << "\t\t\tLab 2 - OpenGL Coding\t\t\t" << endl << endl;
		cout << "\n Please insert an exercise ranging from 1 to 2, or other number to cancel: ";
		cin >> exercisechoice2;
		if (exercisechoice2 == 1)
		{
			cout << "\n";
			Lab2_1(argc, argv);
			cout << "\n";
		}
		else if (exercisechoice2 == 2)
		{
			cout << "\n";
			Lab2_2(argc, argv);
			cout << "\n";
		}
	} while (exercisechoice2 >= 1 && exercisechoice2 <= 2);
}

void Lab3()
{
	int dectobin;
	int dectohex;
	char hexbin[100];
	char binhex[100];
	char bintodec[100];
	char hexdec[100];

	int inputformat;

	do
	{
		cout << "\t\t\tLab3 - Number Conversion\t\t\t" << endl << endl;
		cout << "1 - Decimal to Binary" << endl;
		cout << "2 - Decimal to Hexadecimal" << endl;
		cout << "3 - Hexadecimal to Binary" << endl;
		cout << "4 - Binary to Hexadecimal" << endl;
		cout << "5 - Binary to Decimal" << endl;
		cout << "6 - Hexadecimal to Decimal" << endl;
		cout << "\nSelect number format for input: ";
		cin >> inputformat;
		if (inputformat == 1)
		{
			cout << "\n";
			cout << "Put in a decimal number: ";
			cin >> dectobin;
			decToBinary(dectobin);
			cout << "\n";
		}
		else if (inputformat == 2)
		{
			cout << "\n";
			cout << "Put in a decimal number: ";
			cin >> dectohex;
			decToHexa(dectohex);
			cout << "\n";
		}
		else if (inputformat == 3)
		{
			cout << "\n";
			cout << "Put in a hexadecimal number: ";
			cin >> hexbin;
			HexToBin(hexbin);
			cout << "\n";
		}
		else if (inputformat == 4)
		{
			cout << "\n";
			cout << "Put in a binary number (digit must be divisible by 4): ";
			cin >> binhex;
			BintoHex(binhex);
			cout << "\n";
		}
		else if (inputformat == 5)
		{
			cout << "\n";
			cout << "Put in a binary number: ";
			cin >> bintodec;
			BintoDec(bintodec);
			cout << "\n";
		}
		else if (inputformat == 6)
		{
			cout << "\n";
			cout << "Put in a hexadecimal number: ";
			cin >> hexdec;
			HextoDec(hexdec);
			cout << "\n";
		}
	} while (inputformat >= 1 && inputformat <= 6);
}

int main(int argc, char** argv)
{
	int topicchoice1;

	do
	{
		cout << "\t\t\tBITE 2513 - Game Engine Development I Lab Exercises\t\t\t" << endl << endl;
		cout << "1 - C++ Programming with OpenGL" << endl;
		cout << "2 - OpenGL Coding" << endl;
		cout << "3 - Number Conversion" << endl;
		cout << "\n Please insert a topic ranging from 1 to 3: ";
		cin >> topicchoice1;
		if (topicchoice1 == 1)
		{
			cout << "\n";
			Lab1(argc, argv);
			cout << "\n";
		}
		else if (topicchoice1 == 2)
		{
			cout << "\n";
			Lab2(argc, argv);
			cout << "\n";
		}
		else if (topicchoice1 == 3)
		{
			cout << "\n";
			Lab3();
			cout << "\n";
		}
	} while (topicchoice1 == 1);
}


