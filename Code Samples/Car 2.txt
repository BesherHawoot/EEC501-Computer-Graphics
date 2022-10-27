#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void init(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-200.0,200.0,-200.0,200.0);
}
void setPixel(GLint x,GLint y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
void Circle2(){
int xCenter=70,yCenter=-50,r=25;
int x=0,y=r;
int d=3-(2*r);
glColor3f(0,0,0);
glPointSize(3.0);
while(x<=y){
setPixel(xCenter+x,yCenter+y);
setPixel(xCenter+y,yCenter+x);
setPixel(xCenter-x,yCenter+y);
setPixel(xCenter+y,yCenter-x);
setPixel(xCenter-x,yCenter-y);
setPixel(xCenter-y,yCenter-x);
setPixel(xCenter+x,yCenter-y);
setPixel(xCenter-y,yCenter+x);
if (d<0)
d += (4*x)+6;
else
{
d += (4*(x-y))+10;
y -= 1;
}
x++;
}
glFlush();
}
void drawDot (GLint x, GLint y, GLfloat r, GLfloat g, GLfloat b)
{ glColor3f(r,g,b);
glBegin (GL_POINTS);
glVertex2i (x,y);
glEnd();
}
void symmetricPixels (int x, int y, int xc, int yc, float r, float g, float b)
{ drawDot (xc + x, yc + y, r,g,b);
drawDot (xc - x, yc + y,r,g,b);
//drawDot (xc + x, yc - y,r,g,b);
//drawDot (xc - x, yc - y,r,g,b);
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


void Circle1(){
int xCenter=-70,yCenter=-50,r=25;
int x=0,y=r;
int d=3-(2*r);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,0,0);
glPointSize(3.0);
while(x<=y){
setPixel(xCenter+x,yCenter+y);
setPixel(xCenter+y,yCenter+x);
setPixel(xCenter-x,yCenter+y);
setPixel(xCenter+y,yCenter-x);
setPixel(xCenter-x,yCenter-y);
setPixel(xCenter-y,yCenter-x);
setPixel(xCenter+x,yCenter-y);
setPixel(xCenter-y,yCenter+x);
if (d<0)
d += (4*x)+6;
else
{
d += (4*(x-y))+10;
y -= 1;
}
x++;
}
glBegin(GL_LINES);
glVertex2f(45,-50);
glVertex2f(-45,-50);
glVertex2f(-120,0);
glVertex2f(120,0);

glEnd();
glBegin(GL_LINE_STRIP); // ??? C??E?E
glVertex2f(-95.0,-50.0);
glVertex2f(-120.0,-50.0); // C????E C?????E C???C??E // C????E C?????E C??????E
glVertex2f(-120.0,0.0);
//glVertex2f(-90.0,50.0); // C????E C?????E C???C??E // C????E C?????E C??????E
//glVertex2f(90.0,50.0);
glVertex2f(120.0,0.0); // C????E C?????E C???C??E // C????E C?????E C??????E
glVertex2f(160.0,0.0);
glVertex2f(160.0,-50.0); // C????E C?????E C???C??E // C????E C?????E C??????E
glVertex2f(95.0,-50.0);

glEnd();

Circle2();
Ellipse(120,60,0,0,0,0,0);
glFlush();
}
int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("Bresenham Circle");
init();
glutDisplayFunc(Circle1);
glutMainLoop();
return 0;
}
