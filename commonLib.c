//
#include <stdio.h>
#include "commonLib.h"

void printArray(int *ptr, int len)
{
  int i;
  for(i = 0; i < len; i++, ptr++){
    printf("%d ", *ptr);
  }
  printf("\n");
}

void exchange(int *a, int *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
