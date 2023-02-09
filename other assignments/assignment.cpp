#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<unistd.h>
#include<queue>

using namespace std;


queue<float> transform, scale, rotate;
int no_of_transformation , *arr;
float x;

void myInit(void)// used to set some drawing related states like background color, line color, window size, etc.
{
	// helps to choose the background color (here its black ) first 3 are for the RGB and fourth is for blending for transparent object
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	glColor3f(1.0,1.0,1.0);// to color the line with RGB
	
	//glPointSize(1.0);
	
  	glMatrixMode(GL_PROJECTION);//to choose the matrix mode; there are different matrix mode (here the current matrix related to projection)
  	
	glLoadIdentity();//loads current matrix with the identity matrix;
	
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);// most trivial set of projection and the 
	//(0.0, window_width, 0.0, window_height) sets the orthographic projection from 2D to 3D
}


void display(float x)
{

    // glClear(GL_COLOR_BUFFER_BIT);
	

    glBegin(GL_POLYGON);
        glVertex2f((-1)*x,(-1)*x);
        glVertex2f((-1)*x,x);
        glVertex2f(x,x);
        glVertex2f(x,(-1)*x);
    glEnd();

    glFlush();

}

void func(void)
{
    glColor3f(0.0,0.0,1.0);
    display(x);//normal square

	float a, b, angle, sx, sy;

    sleep(1);

	for(int i=0;i<no_of_transformation;i++)
	{
		if(arr[i]==1)
		{
			a=transform.front();
			transform.pop();
			b=transform.front();
			transform.pop();
			glTranslatef(a,b,0.0f);
		}
		else if(arr[i]==2)
		{
			angle=rotate.front();
			rotate.pop();
			glRotatef(angle,0.0f,0.0f,1.0f);
		}
		else if(arr[i]==3)
		{
			sx=scale.front();
			scale.pop();
			sy=scale.front();
			scale.pop();
			glScalef(sx,sy,0.0f);
		}
		else
		{
			continue;
		}
		
	}
	sleep(1);

	glColor3f(0.0,1.0,0.0);
	sleep(2);
	display(x);

}


int main(int argc, char **argv)
{
	printf("Enter square size(recommanded 150): ");
	scanf("%f",&x);

	int var;
	float a, b, angle, sx, sy;


	printf("how many times you to perform transformation:- ");
	scanf("%d",&no_of_transformation);
	printf("\nenter the sequence of transformation from menu (max 3 transformation): ");
	printf("\n1. to transalate \n2. to rotate \n3. to scale\n0. for no transformation\n\n");

	arr=(int *)malloc(no_of_transformation*sizeof(int));

	for(int i=0;i<no_of_transformation;i++)
	{
		printf("enter choice: ");
		scanf("%d",&var);
		if(var==1 || var==2 || var==3)
		{
			arr[i]=var;
			if(var==1)
			{
				printf("for transaltion enter the coordinates x and y respectively: ");
				scanf("%f %f",&a,&b);
				transform.push(a);
				transform.push(b);
			}
			else if(var==2)
			{
				printf("the angle for rotation in degree:  ");
				scanf("%f",&angle);
				rotate.push(angle);
			}
			else
			{
				printf("the scaling factor along x and y: ");
				scanf("%f %f",&sx,&sy);
				scale.push(sx);
				scale.push(sy);
			}
		}
		else if(var==0)
		{
			continue;
		}
		else
		{
			printf("wrong choice!");
			return 0;
		}
	}
	
	
	
	glutInit(&argc,argv);// used to intialize the glut library , parse and also use the command line options:  glutInit(int *argc, char **argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// to intial display mode it takes argument as "unsigned int" also note that it first if "type of buffering" - here means a single buffer display
	// and after OR(|) we have the constants 
	
	glutInitWindowSize(900,900);            // the size of window in which we will display
	glutInitWindowPosition(100, 150);       // the window position on the screen
	glutCreateWindow("polygon");            // name of the window 
	
	//calling the myintit function to intialize the rest things in 'gl'
	
	myInit();
	glutDisplayFunc(func);
    
	
	glutMainLoop();
    /* tells prog to enter glut event processing loop
	This just means the program sits and waits for things to happen, such as window refreshes, window resizes, mouse clicks, key presses, etc.
	the function never exits thus it should always be placed at the end of the program*/
}
