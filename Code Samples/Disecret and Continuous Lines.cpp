
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glut.h>
static void redraw(void);
int main(int argc, char **argv);
int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowPosition(100,100);
glutInitWindowSize(400,400);
glutCreateWindow("draw multi lines");
glutDisplayFunc(redraw);
glMatrixMode(GL_PROJECTION);
gluPerspective(45,1.0,10.0,200.0);
glMatrixMode(GL_MODELVIEW);
glutMainLoop();
return 0;
}
static void redraw(void)
{
float x1,x2,y1,y2;
int i;
//
#define drawOneLine(x1,y1,x2,y2) glBegin(GL_LINES);\
glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();
glClearColor(1.0,1.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0.0f,0.0f,-100.0f);
glColor3f (0.0, 0.0, 0.0);
glEnable (GL_LINE_STIPPLE);
glLineStipple (1, 0x0101);
drawOneLine (-30.0, -20.0, -10.0, -20.0);
glLineStipple (1, 0x00FF);
drawOneLine (-30.0, -15.0, -10.0, -15.0);
glLineStipple (1, 0x1C47);
drawOneLine (-30.0, -10.0, -10.0, -10.0);
glTranslatef(20.0f,0.0f,0.0f);
glLineWidth (5.0);
glLineStipple (1, 0x0101);
drawOneLine (-5.0, -20.0, 10.0, -20.0);
glLineStipple (1, 0x00FF);
drawOneLine (-5.0, -15.0, 10.0, -15.0);
glLineStipple (1, 0x1C47);
drawOneLine (-5.0, -10.0, 10.0, -10.0);
glLineWidth (1.0);
glutSwapBuffers();
}
