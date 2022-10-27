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
int xCenter=-15,yCenter=155,r=10;
int x=0,y=r;
int d=3-(2*r);
//glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,0,0);
glPointSize(2.0);
while(x<=y){
setPixel(xCenter+x,yCenter+y);
setPixel(xCenter+y,yCenter+x);
setPixel(xCenter-x,yCenter+y);
//setPixel(xCenter+y,yCenter-x);
//setPixel(xCenter-x,yCenter-y);
//setPixel(xCenter-y,yCenter-x);
//setPixel(xCenter+x,yCenter-y);
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


void Circle3(){
int xCenter=15,yCenter=155,r=10;
int x=0,y=r;
int d=3-(2*r);
glColor3f(0,0,0);
glPointSize(2.0);
while(x<=y){
setPixel(xCenter+x,yCenter+y);
setPixel(xCenter+y,yCenter+x);
setPixel(xCenter-x,yCenter+y);
//setPixel(xCenter+y,yCenter-x);
//setPixel(xCenter-x,yCenter-y);
//setPixel(xCenter-y,yCenter-x);
//setPixel(xCenter+x,yCenter-y);
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
void Circle4(){
int xCenter=15,yCenter=155,r=5;
int x=0,y=r;
int d=3-(2*r);
glColor3f(0,0,0);
glPointSize(2.0);
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
void Circle5(){
int xCenter=-15,yCenter=155,r=5;
int x=0,y=r;
int d=3-(2*r);
glColor3f(0,0,0);
glPointSize(2.0);
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
void Circle6(){
int xCenter=00,yCenter=130,r=35;
int x=0,y=r;
int d=3-(2*r);
glColor3f(0,0,0);
glPointSize(2.0);
while(x<=y){




setPixel(xCenter-x,yCenter-y);

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
glBegin(GL_TRIANGLES);
glVertex2f(05.0,120.0);
glVertex2f(-5.0,120.0); 
glVertex2f( 0.0,150.0); 
glEnd();
glBegin(GL_LINES);
glVertex2f(0.0,30.0);
glVertex2f(0.0,80.0);  
glVertex2f( -75.0,60.0);
glVertex2f( 75,60.0);
glVertex2f( 0.0,30.0);
glVertex2f( -60.0,0.0);
glVertex2f( 0.0,30.0);
glVertex2f( 60.0,0.0);
glEnd();

}
static void redraw(void)
{
glLoadIdentity();
glBegin(GL_QUADS); 
glVertex3f(-10.0, 10.0, 0.0); 
glVertex3f( 10.0, 10.0, 0.0); 
glVertex3f( 10.0,-10.0, 0.0); 
glVertex3f(-10.0,-10.0, 0.0); 
glEnd();
glutSwapBuffers();
}
void Circle1(){
int xCenter=00,yCenter=130,r=50;
int x=0,y=r;
int d=3-(2*r);
glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,0,0);
glPointSize(2.0);

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
Circle2();
Circle3();
Circle4();
Circle5();
Circle6();

glFlush();
}

int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100,100);
glutInitWindowSize(500,500);
glutCreateWindow("Bresenham Circle");
init();
glutDisplayFunc(Circle1);
//glutDisplayFunc(redraw);
glutMainLoop();
return 0;
}
