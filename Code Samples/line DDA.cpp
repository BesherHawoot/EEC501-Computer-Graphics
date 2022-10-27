#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
inline GLint round (const GLfloat a) {return GLint (a+0.5);}
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
void lineDDA(GLint x0, GLint y0, GLint xEnd, GLint yEnd)
{
GLint dx = xEnd - x0;
GLint dy = yEnd - y0;
GLint steps, k;
GLfloat xIncrement, yIncrement, x=x0, y=y0;
if(fabs(dx) > fabs(dy))
steps =(int) fabs(dx);
else
steps = (int)fabs(dy);
xIncrement = GLfloat (dx) / GLfloat (steps);
yIncrement = GLfloat (dy) / GLfloat (steps);
setPixel(round (x), round(y));
for(k=0; k<steps; k++)
{
x += xIncrement;
y += yIncrement;
setPixel(round(x) , round(y));
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
lineDDA(x0,y0,xEnd,yEnd);
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
glutCreateWindow("Digital Differential Analyzer Algorithm");
//initialze OpenGL
init();
//call graphics to be displayed on the window
glutDisplayFunc(drawMyLine);
//display everything and wait
glutMainLoop();
return 0;
}
