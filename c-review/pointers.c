#include <stdlib.h>
#include <stdio.h>

// A pointer is a variable that stores the memory address of another variable
// We can access the value of the variable by dereferencing the pointer
// We can also change the value of the variable by dereferencing the pointer
void simplePointer() {
  int x = 10;
  int * xPointer = &x;

  printf("x: %d\n", x);
  printf("xPointer memory address: %p\n", xPointer);
  printf("*xPointer pointer resolved: %d\n", *xPointer);
}

// We can have
// - pointers to pointers
// - pointers to pointers to pointers
// - and so on
void complexPointer() {
  int x = 42;
  int * xPointer1 = &x;
  int ** xPointer2 = &xPointer1;
  int *** xPointer3 = &xPointer2;

  printf("x: %d\n", x);
  printf("***xPointer3 pointer resolved: %d\n", ***xPointer3);
}

// We can use void pointers to store any type of pointer
// And then cast it to the correct type when we need to use it
void voidPointers() {
  int num = 10;
  float fnum = 3.14;
  void* vptr;

  vptr = &num;
  printf("num: %d\n", *(int*)vptr);

  vptr = &fnum;
  printf("fnum: %f\n", *(float*)vptr);
}

// We can use NULL pointers to indicate that the pointer is not pointing to anything
// We can also use NULL pointers to check if the pointer is pointing to anything
void nullPointers() {
  int * ptr = NULL;
  printf("initial ptr value: %p\n", (void*)ptr);

  if (ptr == NULL) {
    printf("ptr is NULL, cannot dereference\n");
  }

  // This will cause a segmentation fault
  // printf("dereferencing NULL pointer: %d\n", *ptr);

  ptr = (int*)malloc(sizeof(int));
  printf("ptr after malloc: %p\n", (void*)ptr);

  if (ptr != NULL) {
    *ptr = 10;
    printf("dereferencing pointer after malloc: %d\n", *ptr);
  }

  free(ptr);
  printf("ptr after free: %p\n", (void*)ptr);
  ptr = NULL;
  printf("ptr after setting to NULL: %p\n", (void*)ptr);
}

// We can use pointers to access elements in an array
// Array is a pointer starting at the first element
// We can increment the pointer to access the next element
void arrayPointer() {
  int arr[5] = {1, 2, 3, 4, 5};
  int * arrPointer = arr;

  printf("arr: %p\n", (void*)arr);
  printf("arrPointer: %p\n", (void*)arrPointer);
  printf("arr[0]: %d\n", arr[0]);
  printf("arrPointer[0]: %d\n", arrPointer[0]);
  printf("*(arrPointer + 1): %d\n", *(arrPointer + 1));

  for (int i = 0; i < 5; i++) {
    printf("arr[%d]: %d\n", i, arr[i]);
    printf("arrPointer[%d]: %d\n", i, arrPointer[i]);
  }
}

// We can use pointers to access elements in a matrix
// Matrix is a pointer starting at the first element
// We can increment the pointer to access the next element
void matrix() {
  int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
  };

  int * matrixPointer = matrix[0];
  printf("matrix[0][0]: %d\n", matrix[0][0]);
  printf("matrixPointer[0]: %d\n", matrixPointer[0]);
  printf("matrix[1][0]: %d\n", matrix[1][0]);
  printf("matrixPointer[3]: %d\n", matrixPointer[3]);
}

int main() {
  printf("----- simplePointer -----");
  simplePointer();

  printf("----- complexPointer -----\n");
  complexPointer();

  printf("----- voidPointers -----\n");
  voidPointers();

  printf("----- nullPointers -----\n");
  nullPointers();

  printf("----- arrayPointer -----\n");
  arrayPointer();

  printf("----- matrix -----\n");
  matrix();

  return 0;
}
