#include<GL/freeglut.h>
#include<iostream>
#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700

double time = 0;
double aPressCnt = 0, sPressCnt = 0, dPressCnt = 0;

#pragma region Cam Setting
float camX = 0, camY = 2, camZ = 20;
float camXdest = 0, camYdest = 0, camZdest = 0;
float camUpx = 0, camUpy = 1, camUpz = 0;
#pragma endregion

#pragma region Words Base Offset
float JbaseOffest = -15;
float SbaseOffest = -1 , SbaseYoffest = 10;
float MbaseOffest = 3.5;
#pragma endregion

#pragma region Manipulation values
float JoffestDegree[3] = { JbaseOffest,0,0 };
float JrotateAxis = 2, JrotateDegree = 0;
float Jsize = 1;

float SoffestDegree[3] = { SbaseOffest,0,0 };
float SrotateAxis = 2, SrotateDegree = 0;
float Ssize = 1;

float MoffestDegree[3] = { MbaseOffest,0,0 };
float MrotateAxis = 2, MrotateDegree = 0;
float Msize = 1;
#pragma endregion


void Reshape(int width, int hieght) {
	glViewport(0, 0, width, hieght);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = width / hieght;
	gluPerspective(40, ratio, 0, 50);
}

void Rotate(float degree, int axis) {
	if (axis == 0)
		glRotatef(degree, 1, 0, 0);
	else if (axis == 1)
		glRotatef(degree, 0, 1, 0);
	else if (axis == 2)
		glRotatef(degree, 0, 0, 1);
}


void DrawJ(float dx = 0, float dy = 0, float dz = 0, float rotateDegree=0, float rotateAxis = 0, float sizeCoefficient = 1) {
	glPushMatrix();
	
	//draw head of J
	float size = 0.5 * sizeCoefficient;
	glTranslatef(dx, dy+ size*4, dz);
	glTranslatef(-size*3, 0, 0);
	Rotate(rotateDegree, rotateAxis);

	int i = 0;
	for (; i < 6; i++) {
		glutSolidCube(size);
		glTranslatef(size, 0, 0);
	}

	//draw body of J
	glTranslatef(-7 * size/2, 0, 0);
	
	i = 0;
	for (; i < 6; i++) {
		glutSolidCube(size);
		glTranslatef(0, -size, 0);
	}

	glTranslatef(-size/2, 2*size/5, 0);
	glutSolidCube(size);
	glTranslatef(-size/2, -2 * size / 5, 0);
	glutSolidCube(size);
	glTranslatef(-size, 0, 0);
	glutSolidCube(size);

	glPopMatrix();
}

void DrawS(float dx = 0, float dy = 0, float dz = 0, float rotateDegree = 0, float rotateAxis = 0, float sizeCoefficient = 1) {
	glPushMatrix();
	float size = 0.5 * sizeCoefficient;
	glTranslatef(dx, dy + size * 4, dz);
	glTranslatef( size * 3, 0, 0);
	Rotate(rotateDegree, rotateAxis);

	for (int i = 0; i < 5; i++) {
		glutSolidCube(size);
		glTranslatef(-size, 0, 0);
	}

	glTranslatef(size / 2, -size/2, 0);
	glutSolidCube(size);
	glTranslatef(-size / 2, -size / 2, 0);
	glutSolidCube(size);
	glTranslatef(0, -size / 2, 0);
	glutSolidCube(size);
	glTranslatef(0, -size / 2, 0);
	glutSolidCube(size);
	glTranslatef(size / 2, -size / 2, 0);
	glutSolidCube(size);
	glTranslatef(size / 2, -size / 2, 0);
	glutSolidCube(size);

	for (int i = 0; i < 4; i++) {
		glutSolidCube(size);
		glTranslatef(size, 0, 0);
	}

	glTranslatef(-size / 2, -size / 2, 0);
	glutSolidCube(size);
	glTranslatef(size / 2, -size / 2, 0);
	glutSolidCube(size);
	glTranslatef(0, -size / 2, 0);
	glutSolidCube(size);
	glTranslatef(0, -size / 2, 0);
	glutSolidCube(size);
	glTranslatef(-size / 2, -size / 2, 0);
	glutSolidCube(size);
	glTranslatef(-size / 2, -size / 2, 0);
	glutSolidCube(size);

	for (int i = 0; i < 5; i++) {
		glutSolidCube(size);
		glTranslatef(-size, 0, 0);
	}

	glPopMatrix();
}

void DrawM(float dx = 0, float dy = 0, float dz = 0, float rotateDegree = 0, float rotateAxis = 0, float sizeCoefficient = 1) {
	glPushMatrix();
	float size = 0.5 * sizeCoefficient;
	glTranslatef(dx, dy - size * 2, dz);
	glTranslatef(-size * 4, 0, 0);
	Rotate(rotateDegree, rotateAxis);

	int cnt = 0;
	while (cnt < 4) {
		int degree;
		
		if (cnt % 2 == 0)
			degree = 1;
		else
			degree = -1;

		for (int i = 0; i < 8; i++) {
			glutSolidCube(size);
			glTranslatef(size / 4, size/1.5  * degree, 0);
		}
		glutSolidCube(size);
		cnt++;
	}

	glPopMatrix();
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	gluLookAt(camX, camY, camZ, camXdest, camYdest, camZdest, camUpx, camUpy, camUpz);
	DrawJ(JoffestDegree[0], JoffestDegree[1], JoffestDegree[2], JrotateDegree, JrotateAxis, Jsize);
	std::cout << "offest degrees " << camZ << ", " << camZdest << std::endl;
	//DrawS(SoffestDegree[0], SoffestDegree[1], SoffestDegree[2], SrotateDegree, SrotateAxis, Ssize);
	//DrawM(MoffestDegree[0], MoffestDegree[1], MoffestDegree[2], MrotateDegree, MrotateAxis, Msize);
	glutSwapBuffers();
}

void MergeLetters() {
	JoffestDegree[0] += 0.1f;
	SoffestDegree[1] -= 0.1f;
}

void CallBackKeyEvent(unsigned char key, int x, int y) {
	if (key == 'a') {
		MergeLetters();


		aPressCnt++;
	}
	glutPostRedisplay();
}




int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize( WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Main");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);	
	glutKeyboardFunc(CallBackKeyEvent);
	glutMainLoop();
}