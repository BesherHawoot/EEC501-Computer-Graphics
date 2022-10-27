#include<GL/glut.h>
#include <stdlib.h>
#include<conio.h>
void init(void)
{
//set display-window background color to white
glClearColor(1.0,1.0,1.0,0.0);
//set projection paramaters
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,300.0,0.0,300.0);
}
void setPixel(GLint xCoordinate, GLint yCoordinate)
{
glBegin(GL_POINTS);
glVertex2i(xCoordinate,yCoordinate);
glEnd();
glFlush(); //executes all OpenGL functions as quickly as possible
}
void lineBres(int x1, int y1, int xn, int yn)
{
int dx = xn - x1, dy = yn - y1;
int p0 = 2 * dy - dx;
int ds = 2 * dy, dt = 2 * (dy - dx);
setPixel(x1, y1);
while (x1 < xn)
{
x1++;
if (p0 < 0)
p0 = p0 + ds;
else
{
y1++;
p0 = p0 + dt;
}
setPixel(x1, y1);
}
}
void drawMyLine(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glPointSize(4.0);
GLint x0 = 100;
GLint y0 = 100;
GLint xEnd = 200;
GLint yEnd = 200;
lineBres(x0,y0,xEnd,yEnd);
}
int main(int argc, char**argv)
{
//initialize GLUT
glutInit(&argc,argv);
//initialize display mode
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//set display-window width & height
glutInitWindowSize(500,500);
//set display-window upper-left position
glutInitWindowPosition(0,0);
//create display-window with a title
glutCreateWindow("Bresenham Algorithm for line ");
//initialze OpenGL
init();
//call graphics to be displayed on the window
glutDisplayFunc(drawMyLine);
//display everything and wait
glutMainLoop();
return 0;
}
