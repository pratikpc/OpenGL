#include<Windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float matrix[1000][3];
void drawPoly(float a[][3], int n)
{
	glBegin(GL_POINTS);
	for (int i = 0;i < n;i++)
	{
		glVertex2f(a[i][0], a[i][1]);
	}
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(a[0][0], a[0][1]);
	glVertex2f(30, 30);

	glEnd();

	glFlush();
}

void mul(int n, float trans[3][3])
{
	int i, j, k;
	float result[1000][3];
	// Multiply original coordinate matrix a [][] with transformation matrix trans[][] to get the resultant new coordinates
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < 3;j++)
		{
			result[i][j] = 0;
			for (k = 0;k < 3;k++)
			{
				result[i][j] = result[i][j] + (matrix[i][k] * trans[k][j]);
			}
		}
	}

	printf("\n Final coordinates are");
	for (i = 0;i < n;i++)
	{
		printf("\n");

		for (j = 0;j < 3;j++)
		{
			printf("%f  ", result[i][j]);
		}
	}
	drawPoly(result, n);

}

void rotation(int n)
{
	int i, j, xf = 0, yf = 0;
	float f[3][3] = { {0.0,0.0,0.0} ,{0.0,0.0,0.0}, {0.0,0.0,1.0} };

	// Initialize rotation matrix
	/*for (i = 0;i < n;i++)
		xf += a[i][0];
	xf = xf / n;
	for (i = 0;i < n;i++)
		yf += a[i][1];
	yf = yf / n;*/
	xf = 20;
	yf = 20;
	printf("\n fixed point x = %d y = %d", xf, yf);

	f[0][0] = cos(75.0*3.141592 / 180.0);
	f[0][1] = sin(75.0*3.141592 / 180.0);
	f[1][0] = -sin(75.0*3.141592 / 180.0);
	f[1][1] = cos(75.0*3.141592 / 180.0);

	f[2][0] = xf * (1 - cos(75.0*3.141592 / 180.0)) + yf * sin(75.0*3.141592 / 180.0);
	f[2][1] = yf * (1 - cos(75.0*3.141592 / 180.0)) - xf * sin(75.0*3.141592 / 180.0);

	printf("\n Rotation Matrix is:");
	for (i = 0;i < 3;i++)
	{
		printf("\n");
		for (j = 0;j < 3;j++)
		{
			printf("%f ", f[i][j]);
		}

	}

	// call mul function
	mul(n, f);
	printf("\n");

}


void FullCircle(int r, int xc, int yc, int angle)
{
	int count = 1;

	// Approx 5/4 = 1
	float decision = 5 / 4 - r;
	int x = 0;
	int y = r;

	// First Point
	matrix[0][0] = 0;   // X
	matrix[0][1] = r;   // Y
	matrix[0][2] = 1;

	while (x <= y) {
		if (decision < 0)
		{
			decision = decision + 2 * x + 3;
			x = x + 1;
			y = y;
		}
		else {
			decision = decision + 2 * x - 2 * y + 5;
			x = x + 1;
			y = y - 1;
		}
		matrix[count][0] = x;
		matrix[count][1] = y;
		matrix[count][2] = 1;
		++count;
		matrix[count][0] = y;
		matrix[count][1] = x;
		matrix[count][2] = 1;
		++count;
		matrix[count][0] = -x;
		matrix[count][1] = y;
		matrix[count][2] = 1;
		++count;
		matrix[count][0] = -y;
		matrix[count][1] = x;
		matrix[count][2] = 1;
		++count;

		matrix[count][0] = -x;
		matrix[count][1] = -y;
		matrix[count][2] = 1;
		++count;
		matrix[count][0] = -y;
		matrix[count][1] = -x;
		matrix[count][2] = 1;
		++count;
		matrix[count][0] = x;
		matrix[count][1] = -y;
		matrix[count][2] = 1;
		++count;
		matrix[count][0] = y;
		matrix[count][1] = -x;
		matrix[count][2] = 1;
		++count;
	}
	drawPoly(matrix, count);
	rotation(count);
}

void disp()
{

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	// call input function
	FullCircle(60, 0, 0, 0);;
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Rotation...");
	gluOrtho2D(-300, 300, -300, 300);
	glutDisplayFunc(disp);
	glutMainLoop();

}