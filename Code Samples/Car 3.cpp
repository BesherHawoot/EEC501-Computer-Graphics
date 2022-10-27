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
gluOrtho2D(0.0,1000.0,0.0,1000.0);
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

void drawDot (GLint x, GLint y, GLfloat r, GLfloat g, GLfloat b)
{ glColor3f(r,g,b);
glBegin (GL_POINTS);
glVertex2i (x,y);
glEnd();
}

void circlePoints (int x, int y, int xc, int yc, float r, float g, float b)
{
drawDot (xc+x,yc+y,r,g,b);
drawDot (xc-x,yc+y,r,g,b);
drawDot (xc+x,yc-y,r,g,b);
drawDot (xc-x,yc-y,r,g,b);
drawDot (xc+y,yc+x,r,g,b);
drawDot (xc-y,yc+x,r,g,b);
drawDot (xc+y,yc-x,r,g,b);
drawDot (xc-y,yc-x,r,g,b);
}
void Circle (int xc, int yc, int rad, float r, float g, float b)
{ int x,y,d;
x = 0;
y = rad;
circlePoints (x,y,xc,yc,r,g,b);
d = 1 - rad;
while (x < y)
{ if (d < 0)
x++;
else
{ x++;
y--;
}
if (d < 0)
d += 2*x +1;
else
d += 2*(x-y) + 1;
circlePoints (x,y,xc,yc,r,g,b);
}
}



void circlePoints4 (int x, int y, int xc, int yc, float r, float g, float b)
{
//drawDot (xc+x,yc+y,r,g,b);
drawDot (xc-x,yc+y,r,g,b);
//drawDot (xc+x,yc-y,r,g,b);
//drawDot (xc-x,yc-y,r,g,b);
//drawDot (xc+y,yc+x,r,g,b);
drawDot (xc-y,yc+x,r,g,b);
//drawDot (xc+y,yc-x,r,g,b);
//drawDot (xc-y,yc-x,r,g,b);
}
void Circle4 (int xc, int yc, int rad, float r, float g, float b)
{ int x,y,d;
x = 0;
y = rad;
circlePoints4 (x,y,xc,yc,r,g,b);
d = 1 - rad;
while (x < y)
{ if (d < 0)
x++;
else
{ x++;
y--;
}
if (d < 0)
d += 2*x +1;
else
d += 2*(x-y) + 1;
circlePoints4 (x,y,xc,yc,r,g,b);
}
}


void circlePoints3 (int x, int y, int xc, int yc, float r, float g, float b)
{
drawDot (xc+x,yc+y,r,g,b);
//drawDot (xc-x,yc+y,r,g,b);
//drawDot (xc+x,yc-y,r,g,b);
//drawDot (xc-x,yc-y,r,g,b);
drawDot (xc+y,yc+x,r,g,b);
//drawDot (xc-y,yc+x,r,g,b);
//drawDot (xc+y,yc-x,r,g,b);
//drawDot (xc-y,yc-x,r,g,b);
}
void Circle3 (int xc, int yc, int rad, float r, float g, float b)
{ int x,y,d;
x = 0;
y = rad;
circlePoints3 (x,y,xc,yc,r,g,b);
d = 1 - rad;
while (x < y)
{ if (d < 0)
x++;
else
{ x++;
y--;
}
if (d < 0)
d += 2*x +1;
else
d += 2*(x-y) + 1;
circlePoints3 (x,y,xc,yc,r,g,b);
}
}


void symmetricPixels (int x, int y, int xc, int yc, float r, float g, float b)
{ drawDot (xc + x, yc + y, r,g,b);
drawDot (xc - x, yc + y,r,g,b);
drawDot (xc + x, yc - y,r,g,b);
drawDot (xc - x, yc - y,r,g,b);
}
void Ellipse (int a, int b, int xc, int yc, float r, float g, float bl)
{ int aSq,bSq,twoASq,twoBSq,d,dx,dy,x,y;
aSq = a*a;
bSq = b*b;
twoASq = 2*aSq;
twoBSq = 2*bSq;
d = bSq - b*aSq + aSq/4;
dx = 0;
dy = twoASq*b;
x = 0;
y = b;
symmetricPixels(x,y,xc,yc,r,g,bl);
while (dx < dy)
{ x++;
dx += twoBSq;
if (d >= 0)
{ y--;
dy -= twoASq;
}
if (d < 0)
d += bSq + dx;
else
d += bSq + dx - dy;
symmetricPixels (x,y,xc,yc,r,g,bl);
}
d = (int)(bSq*(x+0.5)*(x+0.5) + aSq*(y-1)*(y-1) -
aSq*bSq);
while (y > 0)
{ y--;
dy -= twoASq;
if (d <= 0)
{ x++;
dx += twoBSq;
}
if (d > 0)
d += aSq - dy;
else
d += aSq -dy +dx;
symmetricPixels(x,y,xc,yc,r,g,bl);
}
}

void symmetricPixels1(int x, int y, int xc, int yc, float r, float g, float b)
{ //drawDot (xc + x, yc + y, r,g,b);
//drawDot (xc - x, yc + y,r,g,b);
drawDot (xc + x, yc - y,r,g,b);
drawDot (xc - x, yc - y,r,g,b);
}
void Ellipse1 (int a, int b, int xc, int yc, float r, float g, float bl)
{ int aSq,bSq,twoASq,twoBSq,d,dx,dy,x,y;
aSq = a*a;
bSq = b*b;
twoASq = 2*aSq;
twoBSq = 2*bSq;
d = bSq - b*aSq + aSq/4;
dx = 0;
dy = twoASq*b;
x = 0;
y = b;
symmetricPixels1(x,y,xc,yc,r,g,bl);
while (dx < dy)
{ x++;
dx += twoBSq;
if (d >= 0)
{ y--;
dy -= twoASq;
}
if (d < 0)
d += bSq + dx;
else
d += bSq + dx - dy;
symmetricPixels1(x,y,xc,yc,r,g,bl);
}
d = (int)(bSq*(x+0.5)*(x+0.5) + aSq*(y-1)*(y-1) -
aSq*bSq);
while (y > 0)
{ y--;
dy -= twoASq;
if (d <= 0)
{ x++;
dx += twoBSq;
}
if (d > 0)
d += aSq - dy;
else
d += aSq -dy +dx;
symmetricPixels1(x,y,xc,yc,r,g,bl);
}
}

void drawMyLine(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,0.0);
glPointSize(4.0);
GLint x0 = 00;
GLint y0 = 00;
GLint xEnd = 00;
GLint yEnd = 00;
glBegin(GL_POLYGON);
glVertex2f(0,100);
glVertex2f(0,130);
glVertex2f(500,130);
glVertex2f(1000,130);

glVertex2f(1000,100);
glVertex2f(500,100);
glEnd();

glColor3f(0.0,0.0,1.0);
glBegin(GL_LINES);
glVertex2f(380,200);
glVertex2f(220,200);
glVertex2f(215,315);
glVertex2f(250,380);
glVertex2f(225,305);
glVertex2f(260,370);
glEnd();
Circle(450,200,70,0,0,1);
Circle(450,200,30,0,0,1);
Circle(150,200,70,0,0,1);
Circle(150,200,30,0,0,1);
Circle3(400,190,150,0,0,1);
Circle4(200,190,150,0,0,1);
glPointSize(4.0);
Ellipse1(100,50,300,340,0,0,1);

Circle(260,390,20,0,0,1);









Ellipse(15,35,535,200,0,0,1);
Ellipse(15,35,075,200,0,0,1);


lineDDA(x0,y0,xEnd,yEnd);
}
int main(int argc, char**argv)
{
//initialize GLUT
glutInit(&argc,argv);
//initialize display mode
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//set display-window width & height
glutInitWindowSize(600,600);
//set display-window upper-left position
glutInitWindowPosition(0,0);
//create display-window with a title
glutCreateWindow("Digital Differential Analyzer Algorithm: Programmed by Salha");
//initialze OpenGL
init();
//call graphics to be displayed on the window
glutDisplayFunc(drawMyLine);
//display everything and wait
glutMainLoop();
return 0;
}
