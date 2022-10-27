#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void init(void){
glClearColor(1.0,1.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,200.0,0.0,150.0);
}
void setPixel(GLint x,GLint y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
void Circle(){
int xCenter=100,yCenter=100,r=50;
int x=0,y=r;
int d=3-(2*r);
glClear(GL_COLOR_BUFFER_BIT);
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
int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("Bresenham Circle");
init();
glutDisplayFunc(Circle);
glutMainLoop();
return 0;
}
