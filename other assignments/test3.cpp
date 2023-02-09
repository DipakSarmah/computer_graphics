#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>

#define PI 3.1415927

const int slices = 35; // number of slices for the hemisphere
const int stacks = 35; // number of stacks for the hemisphere

//cylinder
void draw_cylinder(GLfloat radius,GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3ub(255,0,0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
     glColor3ub(0,0,255);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}

// function to draw the hemisphere
void drawHemisphere()
{
  // radius of the hemisphere
  float radius = 0.05;

  // draw the stacks
  for (int i = 0; i <= stacks; i++)
  {
    // angle of the current stack
    float theta = (M_PI) * (float)i / stacks;

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
  
  
     //////////flower
     
glColor3f(0.000, 0.502, 0.000);
glPushMatrix();
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

glTranslated(-2.8,-1.2,-7);
glScaled(.3,.3,0);
glutSolidSphere(.9,stacks, slices);
glPopMatrix();

glColor3f(0.000, 0.502, 0.000);
glPushMatrix();
glTranslated(-3.1,-1.2,-7);
glScaled(.3,.3,0);
glutSolidSphere(.9,stacks, slices);
glPopMatrix();

glColor3f(0.000, 0.502, 0.000);
glPushMatrix();
glTranslated(-2.5,-1.2,-7);
glScaled(.3,.3,0);
glutSolidSphere(.9,stacks, slices);
glPopMatrix();


glColor3f(0.000, 0.502, 0.000);
glPushMatrix();
glTranslated(-2.74,-.85,-7);
glScaled(.3,.3,0);
glutSolidSphere(.9,stacks, slices);
glPopMatrix();


glColor3f(0.557, 0.343, 0.0376);
glPushMatrix();
glTranslated(-2.8,-2.1,-7);
glScaled(.2,.3,0);
glutSolidCube(3);
glPopMatrix();

glColor3f(0.545, 0.271, 0.075);
glPushMatrix();
glTranslated(-2.8,-1.5,-7);
glScaled(.2,.6,-0);
glutSolidCube(.5);
glPopMatrix();

////////////window
glColor3f(0.6,0,0);   //  h bar
glPushMatrix();
glTranslated(-3,2.4,-7);
glScaled(1,.05,0);
glutSolidCube(2);
glPopMatrix();

glColor3f(0.6,0,0);   //  h bar2
glPushMatrix();
glTranslated(-3,1.6,-7);
glScaled(1,.03,0);
glutSolidCube(2);
glPopMatrix();

glColor3f(0.6,0,0);   //  h bar3
glPushMatrix();
glTranslated(-3,3.2,-7);
glScaled(1,.03,0);
glutSolidCube(2);
glPopMatrix();


glColor3f(0.6,0,0);   //v bar
glPushMatrix();
glTranslated(-3,2.4,-7);
glScaled(0.05,.8,0);
glutSolidCube(2);
glPopMatrix();


glColor3f(1.000, 0.647, 0.000); // sun
glPushMatrix();
glTranslated(-3.7,2.8,-7);
glScaled(0.3,0.3,0);
glutSolidSphere(.9,stacks, slices);
glPopMatrix();



glColor3f(0.529, 0.808, 0.980);
glPushMatrix();
glTranslated(-3,2.4,-7);
glScaled(1,.8,0);
glutSolidCube(2);
glPopMatrix();

//---------------------->>>>>>>>>door<<<<<<--------------------------//


glColor3f(0,0,0);
glPushMatrix();
glTranslated(2,.3,-7);
glScaled(0.08,.08,0);
glutSolidSphere(.9,stacks, slices);
glPopMatrix();


glColor3f(0.8725, 0.5372, 0.09411);
glPushMatrix();
glTranslated(3,.4,-7);
glScaled(.6,1,-.0);
glutSolidCube(4);
glPopMatrix();



glColor3f(0.412, 0.82, 0.412);
glPushMatrix();
glTranslated(3,-1.65,-7);
glScaled(.6,0.1,-.0);
glutSolidCube(4);
glPopMatrix();

//////////desk

glColor3f(0.545, 0.271, 0.075);
glPushMatrix();
glTranslated(0,-1,-7);
glScaled(1,0.1,1);
glutSolidCube(3);
glRotated(90,8,8,8);
glPopMatrix();

                /////////leg left

glColor3f(0,0,0);
glPushMatrix();
glTranslated(-1.5,-2.85,-7);
glScaled(.09,.04,0);
glutSolidCube(3);
glPopMatrix();


glColor3f(0.545, 0.271, 0.075);
glPushMatrix();
glTranslated(-1.5,-2,-7);
glScaled(.1,.6,0);
glutSolidCube(3);
glPopMatrix();




             /////////leg right

glColor3f(0,0,0);
glPushMatrix();
glTranslated(1.5,-2.85,-7);
glScaled(.09,.04,0);
glutSolidCube(3);
glPopMatrix();

glColor3f(0.545, 0.271, 0.075);
glPushMatrix();
glTranslated(1.5,-2,-7);
glScaled(.1,.6,0);
glutSolidCube(3);
glPopMatrix();


/////////////background top
glColor3f(0.961, 0.871, 0.702);
glPushMatrix();
glTranslated(0.2,5,-20);
glScaled(6,4,.3);
glutSolidCube(5);
glPopMatrix();


///////////////floooor


glColor3f(1, 0.722, 0.529);
glPushMatrix();
glTranslated(0,-6,-20);
glScaled(10,4,.3);
glutSolidCube(3);
glPopMatrix();




glColor3f(0.396,0.392,0.486);

  // save the current modelview matrix
  glPushMatrix();
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  // move the hemisphere to the center of the screen
  glTranslatef(-0.08, -0.095, -1.0);

  // rotate the hemisphere
  glRotatef(30.0, 1.0, 1.0, 0.0);

  // draw the hemisphere
  drawHemisphere();

  // restore the previous modelview matrix
  glPopMatrix();
  
  
  glPushMatrix();
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  // move the hemisphere to the center of the screen
  glTranslatef(0.1, -0.095, -1.0);

  // rotate the hemisphere
  glRotatef(30.0, 1.0, 1.0, 0.0);

  // draw the hemisphere
  drawHemisphere();

  // restore the previous modelview matrix
  glPopMatrix();
    glColor3f(0.396,0.392,0.586);
    glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glTranslatef(-0.1,-0.30,-3.0);
    glRotatef(90, 0.0, 1.0, 0.0);

    draw_cylinder(0.035, 0.26);
    
    glPopMatrix();
  

  // swap the buffers
  glutSwapBuffers();
}

int main(int argc, char* argv[])
{
   /** Initialize glut */


  // initialize GLUT
  glutInit(&argc, argv);

  // set the display mode
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  // set the window size
  glutInitWindowSize(500, 500);

  // create the window
  glutCreateWindow("Hemisphere");

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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