#include <GL/gl.h>
#include <GL/glut.h> 
#include <cmath>
#include <math.h>
using namespace std;
void fourWaySymmetry(int x, int y){
glVertex2i(x, y);
glVertex2i(x, -y);
glVertex2i(-x, -y);
glVertex2i(-x, y);

}

void DCD(int r){
    for(int x=0;x<=r;x++){
        int y = sqrt(r*r - x*x);
        fourWaySymmetry(x,y);
    }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
  glVertex2f(-200.0f, +0.0f);
  glVertex2f(+200.0f, 0.0f);
  glVertex2f(0.0f, 200.0f);
  glVertex2f(0.0f, -200.0f);
  glEnd();
  glPointSize(2);
  glBegin(GL_POINTS);

    DCD(100);
  
  glEnd();

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutCreateWindow("Circles");
  glutInitWindowSize(400, 400);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
  glColor3f(0.0f, 0.0f, 0.0f);  
  glutDisplayFunc(display);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-200, +200, -200, +200);
  glutMainLoop();
  return 0;
}
