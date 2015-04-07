#pragma once
#include<glut.h>
#include<freeglut.h>

using namespace std;

class blocks
{
public:
	blocks();

	blocks(int pos);

	int spot;
	bool stop;

	~blocks();
};
