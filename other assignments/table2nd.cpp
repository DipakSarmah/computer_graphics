#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

GLfloat T = 0;
const int slices = 100;
const int stacks = 100;

// void spin() {
//     T = T + 0.5;

//     if (T > 360) {
//         T = 0;
//     }
//     glutPostRedisplay();
// }


void drawEllipsoid(float a, float b, float c)
{
for (int i = 0; i <= stacks; ++i)
{
float phi = M_PI * i / stacks;
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j <= slices; ++j)
    {
        float theta = 2 * M_PI * j / slices;
        float x = a * cos(theta) * sin(phi);
        float y = b * sin(theta) * sin(phi);
        float z = c * cos(phi);
        glVertex3f(x, y, z);

        x = a * cos(theta) * sin(phi + M_PI / stacks);
        y = b * sin(theta) * sin(phi + M_PI / stacks);
        z = c * cos(phi + M_PI / stacks);
        glVertex3f(x, y, z);
    }
    glEnd();
}
}
void draw() {
    GLfloat pos[] = {0, 1, 0, 1};
    GLfloat col[] = {1, 0, 0, 1};

    GLfloat M[] = {0, 0, 1, 1};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, col);

    gluLookAt(0, 1, 3, 0, 0, 0, 0, 1, 0);

    glRotatef(T, 0, 1, 0);

    // table-top
    glPushMatrix();
        glScalef(1, 0.05, 1);
        glutSolidCube(1);
    glPopMatrix();

    // leg-one
    glPushMatrix();
        glTranslatef(-0.5, -0.5, -0.5);
        glScalef(0.05, 1, 0.05);
        glutSolidCube(1);
    glPopMatrix();

    // leg-two
    glPushMatrix();
        glTranslatef(0.5, -0.5, -0.5);
        glScalef(0.05, 1, 0.05);
        glutSolidCube(1);
    glPopMatrix();

    // leg-three
    glPushMatrix();
        glTranslatef(0.5, -0.5, 0.5);
        glScalef(0.05, 1, 0.05);
        glutSolidCube(1);
    glPopMatrix();

    // leg-four
    glPushMatrix();
        glTranslatef(-0.5, -0.5, 0.5);
        glScalef(0.05, 1, 0.05);
        glutSolidCube(1);
    glPopMatrix();

    // tea pot
    glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, M);
      
        glPushMatrix();
            glTranslatef(0, 0.15, 0);
       //     glutSolidTeapot(0.15);
       // drawEllipsoid(1.0,1.0,1.0);
        glPopMatrix();
    glPopAttrib();

    glutSwapBuffers();
}

void myInit() {
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 2, 10);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Table & Teapot");
    myInit();

     // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glutDisplayFunc(draw);
    //glutIdleFunc(spin);
    glutMainLoop();

    return 0;
}
