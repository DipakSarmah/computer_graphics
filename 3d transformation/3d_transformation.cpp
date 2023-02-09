#include <GL/glut.h> 
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
 

//NOTE:- the mentioned code is for the translation of the 3d cube the matrix "trans" can actually be used in other objects too


GLfloat tx=0.0f,ty=0.0f,tz=0.0f;
 

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}


void Translate_cube()
{

	//cube coordinates
	GLfloat V[8][4] ={	
		-1.0f,1.0f,1.0f,1.0f,
		1.0f,1.0f,1.0f,1.0f,
		-1.0f,-1.0f,1.0f,1.0f,
		1.0f,-1.0f,1.0f,1.0f,
		-1.0f,1.0f,-1.0f,1.0f,
		1.0f,1.0f,-1.0f,1.0f,
		-1.0f,-1.0f,-1.0f,1.0f,
		1.0f,-1.0f,-1.0f,1.0f
	};
	

	
	//transaltion matrix but here we take the translating factors along the below side
	GLfloat trans[4][4]={
		
		1.0f,0.0f,0.0f, 0.0f,
		0.0f,1.0f,0.0f, 0.0f,
		0.0f,0.0f,1.0f, 0.0f,
		tx,ty,tz, 1.0f
	};
	
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			V[i][j]= (V[i][0]*trans[0][j]) + (V[i][1] * trans[1][j]) + (V[i][2]*trans[2][j]) + (V[i][3] * trans[3][j]);
		}
	}
	
    glBegin(GL_QUADS);          

    //Defining vertices in counter-clockwise (CCW) order with normal pointing out

    // Front face  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f( V[0][0],  V[0][1], V[0][2]);
    glVertex3f( V[2][0],  V[2][1], V[2][2]);
    glVertex3f( V[3][0],  V[3][1], V[3][2]);
    glVertex3f( V[1][0],  V[1][1], V[1][2]);

    // Top face (y = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     
    glVertex3f( V[0][0],  V[0][1], V[0][2]);
    glVertex3f( V[1][0],  V[1][1], V[1][2]);
    glVertex3f( V[5][0],  V[5][1], V[5][2]);
    glVertex3f( V[4][0],  V[4][1], V[4][2]);

    // Bottom face (y = -1.0f)
    glColor3f(0.0f, 1.0f, 0.0f);     
    glVertex3f( V[2][0],  V[2][1], V[2][2]);
    glVertex3f( V[3][0],  V[3][1], V[3][2]);
    glVertex3f( V[7][0],  V[7][1], V[7][2]);
    glVertex3f( V[6][0],  V[6][1], V[6][2]);

    // Back face (z = -1.0f)
    glColor3f(0.0f, 0.5f, 1.0f);    
    glVertex3f( V[4][0],  V[4][1], V[4][2]);
    glVertex3f( V[6][0],  V[6][1], V[6][2]);
    glVertex3f( V[7][0],  V[7][1], V[7][2]);
    glVertex3f( V[5][0],  V[5][1], V[5][2]);

    // Left face (x = -1.0f)
    glColor3f(0.0f, 1.0f, 1.0f);     
    glVertex3f( V[4][0],  V[4][1], V[4][2]);
    glVertex3f( V[6][0],  V[6][1], V[6][2]);
    glVertex3f( V[2][0],  V[2][1], V[2][2]);
    glVertex3f( V[0][0],  V[0][1], V[0][2]);

    // Right face (x = 1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);    
    glVertex3f( V[1][0],  V[1][1], V[1][2]);
    glVertex3f( V[3][0],  V[3][1], V[3][2]);
    glVertex3f( V[7][0],  V[7][1], V[7][2]);
    glVertex3f( V[5][0],  V[5][1], V[5][2]);
    glEnd();  

	
}


 
void display() {


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
    glLoadIdentity();             
        
	glTranslatef(-2.0f, 0.0f, -9.0f);  // this translation is just for the bringing cube to in the window
 	
 
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
      
    // Front face  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     
    glVertex3f( 1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    
    // Top face (y = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);

    // Bottom face (y = -1.0f)
    glColor3f(0.0f, 1.0f, 0.0f);     
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);


    // Back face (z = -1.0f)
    glColor3f(0.0f, 0.5f, 1.0f);     
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    // Left face (x = -1.0f)
    glColor3f(0.0f, 1.0f, 1.0f);     
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    // Right face (x = 1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);  
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();   
 
    // the function trnslating the cube ... comment it to verify
 	Translate_cube();
 
    glutSwapBuffers(); 
}
 

void reshape(GLsizei width, GLsizei height) 
{    
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);
  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();             
    gluPerspective(30.0f, aspect, 0.1f, 50.0f);
}
 

int main(int argc, char** argv) 
{
    printf("Enter the value in for tx, ty, tz \n(avoid giving too large value for eg give inrange 0-4 for best results) :");
    scanf("%f %f %f", &tx, &ty, &tz);
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("3d cube");          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}