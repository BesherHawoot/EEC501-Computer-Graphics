
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
static void redraw(void)
{
glClearColor(0.0,0.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0.0,0.0,-100.0);
glColor3f(0.0, 0.0, 0.0);
//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) ;
glRotatef(30,0,1,0);
//glBegin(GL_TRIANGLE_FAN); 

glBegin(GL_LINES);

glVertex3f( 0.0f, 30.0f, 0.0f);
glVertex3f(-20.0f, -20.0f, 20.0f);
glVertex3f( 0.0f, 30.0f, 0.0f);
glVertex3f( 20.0f, -20.0f, 20.0f);
glVertex3f( 0.0f, 30.0f, 0.0f);
glVertex3f( 20.0f, -20.0f, -20.0f);
glVertex3f( 0.0f, 30.0f, 0.0f);
glVertex3f( -20.0f, -20.0f, -20.0f);
glVertex3f( 0.0f, 30.0f, 0.0f);
glVertex3f(-20.0f, -20.0f, 20.0f);

glVertex3f( 20.0f, -20.0f, 20.0f);
glVertex3f(-20.0f, -20.0f, 20.0f);

glVertex3f(-20.0f, -20.0f, 20.0f);
glVertex3f( -20.0f, -20.0f, -20.0f);

glVertex3f( -20.0f, -20.0f, -20.0f);
glVertex3f( 20.0f, -20.0f, -20.0f);

glVertex3f( 20.0f, -20.0f, -20.0f);
glVertex3f( 20.0f, -20.0f, 20.0f);

glEnd();
glutSwapBuffers();
}
int main(int argc, char**argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowPosition(100,100);
glutInitWindowSize(400,400);
glutCreateWindow("Application11");
glutDisplayFunc(redraw);
glMatrixMode(GL_PROJECTION);
gluPerspective(45,1.0,10.0,200.0);
glMatrixMode(GL_MODELVIEW);
glutMainLoop();
return 0;
}


