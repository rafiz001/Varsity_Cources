#include <GL/gl.h>
#include <GL/glut.h> 
#include <cmath>
#include <math.h>
using namespace std;

void eightWaySymmetry(int x, int y){
glVertex2i(x, y);
glVertex2i(y, x);

glVertex2i(y, -x);
glVertex2i(x, -y);

glVertex2i(-x, -y);
glVertex2i(-y, -x);


glVertex2i(-x, y);
glVertex2i(-y, x);

}


void midPoint(int r){
int x = 0;
int y = r;
int p = 1 - r;

while(x < y){
  if(p>=0){
    
    x+=1;
    y-=1;
    p = p + 2 * x -2 * y +5;

  }
  else{
    x+=1;
    p = p + 2 * x + 3;

  }
  eightWaySymmetry(x, y);

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

  midPoint(120);
  
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
