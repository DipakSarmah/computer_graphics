#include <GL/glut.h>
#include <math.h>

#define PI 3.1415927
#define RADIUS 0.5  //cylinder ka radius
#define HEIGHT 1.0  //cylinder ka height
#define SIDES 20
GLfloat ang = 0;

const int slices = 25; // number of slices for the sphere
const int stacks = 25; // number of stacks for the sphere

float a=0.2;
float b=0.2;
float c=0.2;
GLfloat T = 0;

//---------------spin is a function to spin the sphere above the top

void spin() {
    ang = ang + 0.5;

    if (ang > 360) {
        ang = 0;
    }
    glutPostRedisplay();
}

void init()
{
  // set the background color
  glClearColor(1, 0.73, 0.0,0.0);
  // enable smooth shading
  glShadeModel(GL_SMOOTH);

  // enable depth testing
  glEnable(GL_DEPTH_TEST);
}

//------------------------function for cylinder------------------//
void drawCylinder()
{
  glLineWidth(2.0);
  glColor3f(0.43, 0.19, 0.01);

  glBegin(GL_LINES);
  for (int i = 0; i < SIDES; i++)
  {
    float angle = 2 * M_PI * i / SIDES;
    float x = RADIUS * cos(angle);
    float y = RADIUS * sin(angle);

    // Draw the cylinder
    glVertex3f(x, y, 0);
    glVertex3f(x, y, HEIGHT);

    // Draw the connections between each point
    if (i < SIDES - 1)
    {
        glVertex3f(x, y, 0);
        glVertex3f(RADIUS * cos(2 * M_PI * (i + 1) / SIDES), RADIUS * sin(2 * M_PI * (i + 1) / SIDES), 0);

        glVertex3f(x, y, HEIGHT);
        glVertex3f(RADIUS * cos(2 * M_PI * (i + 1) / SIDES), RADIUS * sin(2 * M_PI * (i + 1) / SIDES), HEIGHT);
    }
  }
  glEnd();
}

//-------------------------function for tree--------------------//
void Tree()
{
      glColor3f(0.0784314,0.317647,0.15686);
    glPushMatrix();
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glTranslated(-2.8,-1.2,-7);
    glScaled(.3,.3,0);
    glutSolidSphere(.9,stacks, slices);
    glPopMatrix();

    glColor3f(0.0784314,0.317647,0.15686);
    glPushMatrix();
    glTranslated(-3.1,-1.2,-7);
    glScaled(.3,.3,0);
    glutSolidSphere(.9,stacks, slices);
    glPopMatrix();

    glColor3f(0.0784314,0.317647,0.15686);
    glPushMatrix();
    glTranslated(-2.5,-1.2,-7);
    glScaled(.3,.3,0);
    glutSolidSphere(.9,stacks, slices);
    glPopMatrix();


    glColor3f(0.0784314,0.317647,0.15686);
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

}
//--------------------------function for windows---------------//
void Window(){
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
}

// -----------------function to draw the sphere -----------------------//
void drawSphere()
{
    glColor3f(0.0, 0.0, 0.0);
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

//------------------------------function for table-----------------//
void Table()
{
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
        glColor3f(0.81, 0.01, 0.01);
        glScalef(1, 0.05, 1);
        glutSolidCube(1);
    glPopMatrix();

    // leg-one
    glPushMatrix();
        glTranslatef(-0.47, 0.0, -0.5);
        glScalef(0.05, 1, 0.05);
        glRotated(90,1.0,0.0,0.0);
        drawCylinder();
    glPopMatrix();

    // leg-two
    glPushMatrix();
            
        glTranslatef(0.47, 0.0, -0.5);
        glScalef(0.05, 1, 0.05);
        glRotated(90,1.0,0.0,0.0);
        drawCylinder();
        
    glPopMatrix();

    // leg-three
    glPushMatrix();
        
        glTranslatef(0.47, -0.021, 0.5);
        glScalef(0.05, 1, 0.05);
        glRotated(90,1.0,0.0,0.0);
        drawCylinder();
    glPopMatrix();

    // leg-four
    glPushMatrix();
            
        glTranslatef(-0.47, -0.021, 0.5);
        glScalef(0.05, 1, 0.05);
        glRotated(90,1.0,0.0,0.0);
        drawCylinder();
    glPopMatrix(); 
}

// function to redraw the window
void display()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //----------------------table--------------//
  //table with wireframe
  Table();


  //-------------------sphere---------------//
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  //to put the sphere on the top of table 
  glPushMatrix();
  glColor3f(1.0, 1.0, 1.0);
  // move the sphere to the center of the screen
  glTranslatef(0.00, 0.25, 0.4);
  // rotate the sphere
  glRotatef(100.0, 1.0, 0.0, -0.055);
  // draw the sphere
  glRotated(ang,0.0,0.0,1.0);
  drawSphere();
  // restore the previous modelview matrix
  glPopMatrix(); 
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  //-----------------tree----------------------// 
  glPushMatrix();
  glTranslatef(2.0,1.0,2.0);
  Tree();
  glPopMatrix();

  //------------window-----------------------//
   glTranslatef(0.0,-2.0,0.0);
   Window();
    //----------------floor-----------------//
    glColor3f(0.66,0.56,0.29);
    glPushMatrix();
    glTranslated(0,-10,-10);
    glScaled(10,4,.3);
    glutSolidCube(3);
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
  glutCreateWindow("Table with sphere");

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // set the function to call when the window needs to be redrawn
   
  glutDisplayFunc(display);
  glutIdleFunc(spin);

  // set the function to call when the window is resized
  glutReshapeFunc(resize);

  // initialize OpenGL
  init();

  // start the main loop
  glutMainLoop();

  return 0;
}
