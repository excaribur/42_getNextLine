#include <stdio.h>

// This is the file-scope variable (with internal linkage), visible only in
// this compilation unit.
static int shared = 3;

// This one has external linkage (not limited to this compilation unit).
extern int over_shared;

// Also internal linkage.
int over_shared_too = 2;

static void ChangeShared() {
  // Reference to the file-scope variable in a function.
  shared = 5;
}

static void LocalShadow() {
  // Local variable that will hide the global of the same name.
  int shared;

  // This will affect only the local variable and will have no effect on the
  // file-scope variable of the same name.
  shared = 1000;
}

static void ParamShadow(int shared) {
  // This will affect only the parameter and will have no effect on the file-
  // scope variable of the same name.
  shared = -shared;
}

int main() {
  // Reference to the file-scope variable.

  printf("shared:%d\n", shared);

  ChangeShared();

  printf("ChangeShared() shared:%d\n", shared);

  LocalShadow();

  printf("LocalShadow() shared:%d\n", shared);

  ParamShadow(1);

  printf("ParamShadow(1) shared:%d\n", shared);

  return 0;
}
