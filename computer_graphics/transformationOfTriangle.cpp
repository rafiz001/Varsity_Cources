#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;
class Triangle {
private:
  float points[3][2];
  float modifiedPoints[3][2];

public:
  void setTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    points[0][0] = x1;
    points[0][1] = y1;

    points[1][0] = x2;
    points[1][1] = y2;

    points[2][0] = x3;
    points[2][1] = y3;
  }
  void showBaseTriangle() {
    glBegin(GL_LINES);
    for (int i = 0; i < 3; i++) {
      glVertex2f(points[i][0], points[i][1]);
      glVertex2f(points[(i + 1) % 3][0], points[(i + 1) % 3][1]);
    }
    glEnd();
  }
  void showModifiedTriangle() {
    glBegin(GL_LINES);
    for (int i = 0; i < 3; i++) {
      glVertex2f(modifiedPoints[i][0], modifiedPoints[i][1]);
      glVertex2f(modifiedPoints[(i + 1) % 3][0],
                 modifiedPoints[(i + 1) % 3][1]);
    }
    glEnd();
  }
  void showBothTriangle() {
    showBaseTriangle();
    showModifiedTriangle();
  }
  void translation(float tx, float ty) {
    for (int i = 0; i < 3; i++) {
      modifiedPoints[i][0] = points[i][0] + tx;
      modifiedPoints[i][1] = points[i][1] + ty;
    }
  }
  void scaling(float sx, float sy) {
    for (int i = 0; i < 3; i++) {
      modifiedPoints[i][0] = points[i][0] * sx;
      modifiedPoints[i][1] = points[i][1] * sy;
    }
  }
  void rotaiton(float degree) {
    float rad = degree * 3.1416 / 180;
    for (int i = 0; i < 3; i++) {
      modifiedPoints[i][0] =
          (points[i][0] * cos(rad)) - (points[i][1] * sin(rad));
      modifiedPoints[i][1] =
          (points[i][1] * cos(rad)) + (points[i][0] * sin(rad));
    }
  }
  void reflection(char axis) {
    for (int i = 0; i < 3; i++) {
      modifiedPoints[i][0] = points[i][0] * ((axis == 'x') ? 1 : -1);
      modifiedPoints[i][1] = points[i][1] * ((axis == 'y') ? 1 : -1);
    }
  }
  void shearing(float sh, char axis) {
    for (int i = 0; i < 3; i++) {
      modifiedPoints[i][0] =
          points[i][0] + ((axis == 'x') ? sh * points[i][1] : 0);
      modifiedPoints[i][1] =
          points[i][1] + ((axis == 'y') ? sh * points[i][0] : 0);
    }
  }
};
Triangle t;
void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 0.0f);
  glVertex2f(0.0f, +100.0f);
  glVertex2f(0.0f, -100.0f);

  glVertex2f(-100.0f, +0.0f);
  glVertex2f(+100.0f, -0.0f);
  glEnd();

  t.showBothTriangle();

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutCreateWindow("Transformation on Triangle");
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);

  cout << "Enter the triangle coordinates in order: x1,y1,x2,y2,x3,y3:\n";
  float input[3][2];
  for (int i = 0; i < 3; i++) {
    cin >> input[i][0];
    cin >> input[i][1];
  }
  t.setTriangle(input[0][0], input[0][1], input[1][0], input[1][1],
                        input[2][0], input[2][1]);
  // 10.0, 10.0, 20.0, 10.0, 15.0, 30.0
  cout << "What you want to do:\n1.: Translation,\n2.: Scalling\n3.: "
          "Rotation\n4.: Reflection\n5.: Shearing\n";
  int choice;
  cin >> choice;
  switch (choice) {
  case 1: {
    cout << "Enter TX TY: ";
    float tx, ty;
    cin >> tx;
    cin >> ty;
    t.translation(tx, ty);
    break;
  }
  case 2: {
    cout << "Enter SX SY: ";
    float sx, sy;
    cin >> sx;
    cin >> sy;
    t.scaling(sx, sy);
    break;
  }
  case 3: {
    cout << "Enter angle in degree: ";
    float degree;
    cin >> degree;
    t.rotaiton(degree);
    break;
  }
  case 4: {
    cout << "Enter axis in small case: ";
    char axis;
    cin >> axis;
    t.reflection(axis);
    break;
  }
  case 5: {
    cout << "Enter sh and axis in small case: ";
    float sh;
    char axis;
    cin >> sh;
    cin >> axis;
    t.shearing(sh, axis);
    break;
  }
  }

  glutDisplayFunc(display);
  gluOrtho2D(-100, +100, -100, +100);
  glutMainLoop();
  return 0;
}