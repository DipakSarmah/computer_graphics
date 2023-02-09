
#include <GL/glut.h>
#include <math.h>

const int slices = 25; // number of slices for the sphere
const int stacks = 25; // number of stacks for the sphere

GLfloat T = 0;

// function to draw the sphere -> works fine
void drawSphere()
{
  // radius of the sphere
  float radius = 0.2;

  // draw the stacks
  for (int i = 0; i <= stacks; i++)
  {
    // angle of the current stack
    float theta = (M_PI / 2) * (float)i / stacks;

    // draw the slices
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j <= slices; j++)
    {
      // angle of the current slice
      float phi = (2 * M_PI) * (float)j / slices;

      // coordinates of the current slice
      float x = radius * cos(phi) * sin(theta);
      float y = radius * sin(phi) * sin(theta);
      float z = radius * cos(theta);

      // set the normal for the current slice
      glNormal3f(x, y, z);

      // draw the slice
      glVertex3f(x, y, z);

      // coordinates of the next slice
      x = radius * cos(phi) * sin(theta + M_PI / stacks);
      y = radius * sin(phi) * sin(theta + M_PI / stacks);
      z = radius * cos(theta + M_PI / stacks);

      // set the normal for the next slice
      glNormal3f(x, y, z);

      // draw the next slice
      glVertex3f(x, y, z);
    }
    glEnd();
  }
}

const int slices1 = 30; // number of slices1 for the sphere
const int stacks1 = 100; // number of stacks1 for the sphere

// function to draw the sphere -> works fine
void drawPlate()
{
  // radius1 of the plate
  float radius1 = 1.45;

  // draw the stacks1
  for (int i = 0; i <= stacks1 / 10; i++)
  {
    // angle of the current stack
    float theta1 = (M_PI / 2) * (float)i / stacks1;

    // draw the slices1
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j <= slices1; j++)
    {
      // angle of the current slice
      float phi1 = (2 * M_PI) * (float)j / slices1;

      // coordinates of the current slice
      float x1 = radius1 * cos(phi1) * sin(theta1);
      float y1 = radius1 * sin(phi1) * sin(theta1);
      float z1 = radius1 * cos(theta1);

      // set the normal for the current slice
      glNormal3f(x1, y1, z1);

      // draw the slice
      glVertex3f(x1, y1, z1);

      // coordinates of the next slice
      x1 = radius1 * cos(phi1) * sin(theta1 + M_PI / stacks1);
      y1 = radius1 * sin(phi1) * sin(theta1 + M_PI / stacks1);
      z1 = radius1 * cos(theta1 + M_PI / stacks1);

      // set the normal for the next slice
      glNormal3f(x1, y1, z1);

      // draw the next slice
      glVertex3f(x1, y1, z1);
    }
    glEnd();
  }
}

// void drawTable() {
//     GLfloat pos[] = {0, 1, 0, 1};
//     GLfloat col[] = {1, 0, 0, 1};

//     GLfloat M[] = {0, 0, 1, 1};

//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//     glLoadIdentity();

//     glLightfv(GL_LIGHT0, GL_POSITION, pos);
//     glLightfv(GL_LIGHT0, GL_DIFFUSE, col);

//     gluLookAt(0, 1, 3, 0, 0, 0, 0, 1, 0);

//     glRotatef(T, 0, 1, 0);

//     // table-top
//     glPushMatrix();
//         glScalef(1, 0.05, 1);
//         glutSolidCube(1);
//     glPopMatrix();

//     // leg-one
//     glPushMatrix();
//         glTranslatef(-0.5, -0.5, -0.5);
//         glScalef(0.05, 1, 0.05);
//         glutSolidCube(1);
//     glPopMatrix();

//     // leg-two
//     glPushMatrix();
//         glTranslatef(0.5, -0.5, -0.5);
//         glScalef(0.05, 1, 0.05);
//         glutSolidCube(1);
//     glPopMatrix();

//     // leg-three
//     glPushMatrix();
//         glTranslatef(0.5, -0.5, 0.5);
//         glScalef(0.05, 1, 0.05);
//         glutSolidCube(1);
//     glPopMatrix();

//     // leg-four
//     glPushMatrix();
//         glTranslatef(-0.5, -0.5, 0.5);
//         glScalef(0.05, 1, 0.05);
//         glutSolidCube(1);
//     glPopMatrix();  
 
//     glutSwapBuffers();
// }

// function to initialize OpenGL
void init()
{
  // set the background color
  glClearColor(0.0, 0.0, 0.0, 0.0);

  // enable smooth shading
  glShadeModel(GL_SMOOTH);

  // enable depth testing
  glEnable(GL_DEPTH_TEST);
}

// function to resize the window
void resize(int w, int h)
{
  // set the viewport
  glViewport(0, 0, w, h);

  // set the projection matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0);

  // set the modelview matrix
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// function to redraw the window
void display()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  // draw table
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
        glColor3f(1.0, 0.0, 0.0);
        glScalef(1, 0.05, 1);
        glutSolidCube(1);
    glPopMatrix();

    // leg-one
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-0.5, -0.5, -0.5);
        glScalef(0.05, 1, 0.05);
        glutSolidCube(1);
    glPopMatrix();

    // leg-two
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);    
        glTranslatef(0.5, -0.5, -0.5);
        glScalef(0.05, 1, 0.05);
        glutSolidCube(1);
    glPopMatrix();

    // leg-three
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(0.5, -0.5, 0.5);
        glScalef(0.05, 1, 0.05);
        glutSolidCube(1);
    glPopMatrix();

    // leg-four
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);    
        glTranslatef(-0.5, -0.5, 0.5);
        glScalef(0.05, 1, 0.05);
        glutSolidCube(1);
    glPopMatrix();


    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  // save the current modelview matrix
  glPushMatrix();
  
  glColor3f(1.0, 1.0, 1.0);
  // move the sphere to the center of the screen
  glTranslatef(-0.32, 0.25, 0.358);

  // rotate the sphere
  glRotatef(100.0, 1.0, 0.0, -0.055);

  // draw the sphere
  drawSphere();

  // restore the previous modelview matrix
  glPopMatrix();

  
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glPushMatrix();
  
  glColor3f(1.0, 1.0, 1.0);
  // move the plate to the center of the screen
  glTranslatef(0.1, 1.475, -0.25);

  // rotate the plate
  glRotatef(85.0, 1.0, 0.0, 0.05);

  // draw the sphere
  drawPlate();

  // restore the previous modelview matrix
  glPopMatrix();

  // swap the buffers
  glutSwapBuffers();
}

int main(int argc, char* argv[])
{
  // initialize GLUT
  glutInit(&argc, argv);

  // set the display mode
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  // set the window size
  glutInitWindowSize(1500, 1000);

  // create the window
  glutCreateWindow("Hemisphere");

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // set the function to call when the window needs to be redrawn
  glutDisplayFunc(display);

  // set the function to call when the window is resized
  glutReshapeFunc(resize);

  // initialize OpenGL
  init();

  // start the main loop
  glutMainLoop();

  return 0;
}