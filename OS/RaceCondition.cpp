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
  printf("value after p1 executed internal and shared value of a = %d,%d\n", p1.process(), a);
  printf("value after p2 executed internal and shared value of a = %d,%d\n", p2.process(), a);
  return 0;
}
