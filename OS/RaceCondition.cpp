#include <stdio.h>
class processes {
private:
  int internal;
  int &shared;

public:
  processes(int &a): shared(a) { internal = shared; }
  int process() {
    internal += 1;
    shared = internal;
    return internal;
  }
};
int main() {
  int a = 10;
  processes p1(a);
  processes p2(a);
  int p1internal=p1.process();
  printf("value after p1 executed internal and shared value of a = %d,%d\n", p1internal, a);
  int p2internal=p2.process();
  printf("value after p2 executed internal and shared value of a = %d,%d\n", p2internal, a);
  return 0;
}
