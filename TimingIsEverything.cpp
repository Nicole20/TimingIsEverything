// TimingIsEverything.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<glut.h>
#include<freeglut.h>
#include<ctime>
#include"blocks.h"

using namespace std;

void initialize();
void draw();
void drawScore();
void Timer(int value);
void action(int key, int x, int y);

void check();

blocks block1(0), block2(1), block3(2);

int colors[4] = { 0, 1, 2, 3 };
int sec = 1000;
int points = 0;
char *score = { "Score = " };
char *numbers = { "0123456789" };

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 300);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Timing is Everything 2");

	initialize();

	glutDisplayFunc(draw);
	glutSpecialFunc(action);
	glutTimerFunc(sec, Timer, 0);

	glutMainLoop();

	return 0;
}

void initialize()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, 7, 0, 3);
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	switch (colors[block1.spot])
	{
	case 0:
		glColor3f(1, 0, 0);
		break;
	case 1:
		glColor3f(0, 1, 0);
		break;
	case 2:
		glColor3f(0, 0, 1);
		break;
	case 3:
		glColor3f(1, 1, 0);
		break;
	default:
		break;
	}

	glBegin(GL_QUADS);
	glVertex2f(1, 1);
	glVertex2f(1, 2);
	glVertex2f(2, 2);
	glVertex2f(2, 1);
	glEnd();

	switch (colors[block2.spot])
	{
	case 0:
		glColor3f(1, 0, 0);
		break;
	case 1:
		glColor3f(0, 1, 0);
		break;
	case 2:
		glColor3f(0, 0, 1);
		break;
	case 3:
		glColor3f(1, 1, 0);
		break;
	default:
		break;
	}

	glBegin(GL_QUADS);
	glVertex2f(3, 1);
	glVertex2f(3, 2);
	glVertex2f(4, 2);
	glVertex2f(4, 1);
	glEnd();

	switch (colors[block3.spot])
	{
	case 0:
		glColor3f(1, 0, 0);
		break;
	case 1:
		glColor3f(0, 1, 0);
		break;
	case 2:
		glColor3f(0, 0, 1);
		break;
	case 3:
		glColor3f(1, 1, 0);
		break;
	default:
		break;
	}

	glBegin(GL_QUADS);
	glVertex2f(5, 1);
	glVertex2f(5, 2);
	glVertex2f(6, 2);
	glVertex2f(6, 1);
	glEnd();

	drawScore();

	glutPostRedisplay();
	glFlush();
}

void drawScore()
{
	glColor3f(0, 0, 0);
	glRasterPos2f(1, 2.5);

	for (int i = 0; i < 8; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[i]);
	}

	if (points < 10)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[points]);
	}
	else
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[points / 10]);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[points % 10]);
	}
}

void Timer(int value)
{
	if (block1.stop == false)
	{
		if (block1.spot == 3)
		{
			block1.spot = 0;
		}
		else
		{
			block1.spot++;
		}
	}

	if (block2.stop == false)
	{
		if (block2.spot == 3)
		{
			block2.spot = 0;
		}
		else
		{
			block2.spot++;
		}
	}

	if (block3.stop == false)
	{
		if (block3.spot == 3)
		{
			block3.spot = 0;
		}
		else
		{
			block3.spot++;
		}
	}

	glutTimerFunc(sec, Timer, 0);
}

void action(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		if (block1.stop == false)
		{
			block1.stop = true;
		}
		else if (block2.stop == false)
		{
			block2.stop = true;
		}
		else if (block3.stop == false)
		{
			block3.stop = true;
		}
	}

	check();

	glutPostRedisplay();
}

void check()
{
	if (block1.stop == true && block2.stop == true && block3.stop == true)
	{
		if (block1.spot == block2.spot && block2.spot == block3.spot)
		{
			points++;
			sec = sec - 10;
		}
		else
		{
			points = 0;
			sec = 1000;
		}

		block1.stop = block2.stop = block3.stop = false;
		srand(time(NULL));

		block1.spot = rand() % 4;
		if (block1.spot == 3)
		{
			block2.spot = 0;
		}
		else
		{
			block2.spot = block1.spot + 1;
		}

		if (block2.spot == 3)
		{
			block3.spot = 0;
		}
		else
		{
			block3.spot = block2.spot + 1;
		}
	}
}
