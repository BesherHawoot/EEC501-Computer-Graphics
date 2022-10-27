#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glut.h>
static void redraw(void);
int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowPosition(100,100);
glutInitWindowSize(400,400);
glutCreateWindow("Drawing Triangle and Square");
glutDisplayFunc(redraw);
glMatrixMode(GL_PROJECTION);
gluPerspective(45,1.0,10.0,200.0);
glMatrixMode(GL_MODELVIEW);
glutMainLoop();
return 0;
}
static void redraw(void)
{
glLoadIdentity();
glTranslatef(-20.0,0.0,-100.0);
glBegin(GL_TRIANGLES);
glVertex3f(0.0,10.0, 0.0);
glVertex3f(-10.0,-10.0, 0.0); 
glVertex3f( 10.0,-10.0, 0.0); 
glEnd();
glTranslatef(40.0,0.0,0.0);
glBegin(GL_QUADS); 
glVertex3f(-10.0, 10.0, 0.0); 
glVertex3f( 10.0, 10.0, 0.0); 
glVertex3f( 10.0,-10.0, 0.0); 
glVertex3f(-10.0,-10.0, 0.0); 
glEnd();
glutSwapBuffers();
}
