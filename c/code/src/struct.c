#include <stdio.h>
#include <stdlib.h>

// (1) This is ok 
typedef struct _ABC ABC;
struct _ABC {
  ABC *next;
  int data;
};

// (2) This is also ok
typedef struct _XYZ {
  struct _XYZ *next;
  int data;
} XYZ;


// (3) This is definitely ok
struct PQR {
  struct PQR *next;
  int data;
};

/** However to avoid a brain fart ... stick to (1) */

int main(void) {
  

  return 1;
}
