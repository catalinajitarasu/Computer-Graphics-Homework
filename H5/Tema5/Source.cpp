#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "glut.h"

// the size of the window measured in pixels
#define dim 300

unsigned char prevKey;

enum EObiect { cubw, cubs, sferaw, sferas,triangle,cub3 } ob = cubw;

void DisplayAxe() {
    int X, Y, Z;
    X = Y = 200;
    Z = 200;

    glLineWidth(2);

    // Ox axis - green
    glColor3f(0, 1, 0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(0, 0, 0);
    glVertex3f(X, 0, 0);
    glEnd();

    // Oy axis - blue
    glColor3f(0, 0, 1);
    glBegin(GL_LINE_STRIP);
    glVertex3f(0, 0, 0);
    glVertex3f(0, Y, 0);
    glEnd();

    // Oz axis - red
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, Z);
    glEnd();

    glLineWidth(1);
}

// wireframe cube
void Display1() {
    glColor3f(1, 0, 0);
    //deseneaza cub doar din linii
    glutWireCube(1);
}

// solid cube
void Display2() {
    glColor3f(1, 0, 0);
    //deseneaza cub solid
    glutSolidCube(1);
}

// wireframe sphere
void Display3() {
    glColor3f(0, 0, 1);
    //deseneaza sfera din linii
    glutWireSphere(1, 10, 10);
}

// solid sphere
void Display4() {
    glColor3f(0, 0, 1);
    //deseneaza sfera solida
    glutSolidSphere(1, 10, 10);
}

void Display5() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);
    DisplayAxe();
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.0f, 5.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 1.5f, 3.0f);
    glEnd();

}

void Display6() {
    int n = 10;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    //DisplayAxe();
    glutWireCube(1);
    for (int i = 0; i <= 360; i++) {
        glMatrixMode(GL_MODELVIEW);
        glRotated(n, 0, 0, 1);
    }
}

void DisplayObiect()
{
    switch (ob)
    {
    case cubw:
        Display1();
        break;
    case cubs:
        Display2();
        break;
    case sferaw:
        Display3();
        break;
    case sferas:
        Display4();
        break;
    case triangle:
        Display5();
        break;
    case cub3:
        Display6();
        break;
    default:
        break;
    }
}

// the rotation with 10 degrees about the Ox axis
void DisplayX() {
    glMatrixMode(GL_MODELVIEW);
    //realizeaza rotatia unde primul parametru gradele, apoi xyz
    glRotated(10, 1, 0, 0);
}

// the rotation with 10 degrees about the Oy axis
void DisplayY() {
    glMatrixMode(GL_MODELVIEW);
    glRotated(10, 0, 1, 0);
}

// the rotation with 10 degrees about the Oz axis
void DisplayZ() {
    glMatrixMode(GL_MODELVIEW);
    glRotated(10, 0, 0, 1);
}

// translation by 0.2, 0.2, 0.2
void DisplayT() {
    glMatrixMode(GL_MODELVIEW);
    //translatie pe xyz 
    glTranslatef(0.2, 0.2, 0.2);
}

// scaling by 1.2, 1.2, 1.2
void DisplayS() {
    glMatrixMode(GL_MODELVIEW);
    //mareste obiect
    glScalef(1.2, 1.2, 1.2);
}

void Init(void) {
    glClearColor(1, 1, 1, 1);
    glLineWidth(2);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, 30, -30);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotated(20, 1, 0, 0);
    glRotated(-20, 0, 1, 0);
}

void Display(void) {
    switch (prevKey)
    {
    case 'a':
        DisplayAxe();
        break;
    case '0':
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotated(20, 1, 0, 0);
        glRotated(-20, 0, 1, 0);
        break;
    case '1':
        Display1();
        ob = cubw;
        break;
    case '2':
        Display2();
        ob = cubs;
        break;
    case '3':
        Display3();
        ob = sferaw;
        break;
    case '4':
        Display4();
        ob = sferas;
        break;
    case '5':
        Display5();
        ob = triangle;
        break;
    case '6':
        Display6();
        ob = cub3;
        break;
    case 'x':
        glClear(GL_COLOR_BUFFER_BIT);
        DisplayX();
        DisplayAxe();
        DisplayObiect();
        break;
    case 'y':
        glClear(GL_COLOR_BUFFER_BIT);
        DisplayY();
        DisplayAxe();
        DisplayObiect();
        break;
    case 'z':
        glClear(GL_COLOR_BUFFER_BIT);
        DisplayZ();
        DisplayAxe();
        DisplayObiect();
        break;
    case 't':
        glClear(GL_COLOR_BUFFER_BIT);
        DisplayT();
        DisplayAxe();
        DisplayObiect();
        break;
    case 's':
        glClear(GL_COLOR_BUFFER_BIT);
        DisplayS();
        DisplayAxe();
        DisplayObiect();
        break;
    default:
        break;
    }
    glutSwapBuffers();
}

void Reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void KeyboardFunc(unsigned char key, int x, int y) {
    prevKey = key;
    if (key == 27)
        exit(0);
    glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitWindowSize(dim, dim);

    glutInitWindowPosition(100, 100);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutCreateWindow(argv[0]);

    Init();

    glutReshapeFunc(Reshape);

    glutKeyboardFunc(KeyboardFunc);

    glutMouseFunc(MouseFunc);

    glutDisplayFunc(Display);

    glutMainLoop();

    return 0;
}
