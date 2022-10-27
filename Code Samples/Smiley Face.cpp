#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void init(void){
glClearColor(1.0,1.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,200.0,0.0,200.0);
}
void setPixel(GLint x,GLint y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
void Circle(GLint xCenter=100,GLint yCenter=100,GLint r=50){

int x=0,y=r;
int d=3-(2*r);
glPointSize(2);
glColor3f(1,0,0.5);
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

void Circle1(GLint xCenter=100,GLint yCenter=50,GLint r=10){
int x=0,y=r;
int d=3-(2*r);
glPointSize(2);
glColor3f(1,0,0.5);
while(x<=y){
setPixel(xCenter+y,yCenter-x);
setPixel(xCenter-x,yCenter-y);
setPixel(xCenter-y,yCenter-x);
setPixel(xCenter+x,yCenter-y);
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

void Circle2(void) {
     Circle(100,100,60);
     Circle(80,120,10);
      Circle(120,120,10);
       Circle1(100,80,10);
     }



int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("Bresenham Circle");
init();
glutDisplayFunc(Circle2);
glutMainLoop();
return 0;
}
