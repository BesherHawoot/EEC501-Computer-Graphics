#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
void drawDot (GLint x, GLint y, GLfloat r, GLfloat g, GLfloat b)
{ glColor3f(r,g,b);
glBegin (GL_POINTS);
glVertex2i (x,y);
glEnd();
}
void myInit(void)
{
glClearColor(1.0,1.0,1.0,0.0); // set white background color
glColor3f (0.0f,0.0f,0.0f); //default color
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
int sign (int n)
{ if (n > 0) return 1;
else if (n < 0 ) return (-1);
return 0;
}
void Line (int x0, int y0, int x1, int y1, float r, float g, float b)
{ int x,y,dx,dy,d,j,s1,s2,flag=0;
x = x0;
y = y0;
dx = abs (x1 - x0);
dy = abs (y1 - y0);
s1 = sign (x1-x0);
s2 = sign (y1-y0);
if (dy > dx)
{ // swap (dy,dx);
int temp = dy;
dy = dx;
dx = temp;
flag = 1;
}
d = 2*dy - dx;
for (j = 1; j <= dx; j++)
{ drawDot (x,y,r,g,b);
while (d > 0)
{ if (flag == 1)
x += s1;
else
y += s2;
d -=2*dx;
}
if (flag == 1)
y += s2;
else
x += s1;
d += 2*dy;
}
}
//<<<<<<< draw circles
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
//<<<<<<< draw Ellipse
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
void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT); // clear the screen
// Draw a red line
Line (45,50,100,120,1,0,0);
// put black center axes on screen for ellipse and circle
glColor3f(0.0f,0.0f,0.0f);
glBegin (GL_LINES); //one long horizontal line (x axis)
glVertex2i (30,300);
glVertex2i (600,300);
glEnd();
glBegin(GL_LINES); // vertical line (ellipse y axis)
glVertex2i(200,200);
glVertex2i(200,400);
glEnd();
glBegin (GL_LINES); // vertical line (circle y axis)
glVertex2i(500,200);
glVertex2i(500,400);
glEnd();
// put blue circle on screen
Circle (500,300,70,0,0,1);
// draw a green ellipse on the screen
Ellipse (150,50,200,300,0,1,0);
glFlush();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv); // initialize the toolkit
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
glutInitWindowSize(640,480); // set window size
glutInitWindowPosition(100, 150); // set window position on screen
glutCreateWindow("Basic drawing"); // open the screen window
glutDisplayFunc(myDisplay); // register redraw function
myInit();
glutMainLoop(); // go into a perpetual loop
return 0;
}
