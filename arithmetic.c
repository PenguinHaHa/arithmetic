//This file implement some sort arithmetic

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "sortLib.h"
#include "commonLib.h"

#define HEAP_SORT   0
#define QUICK_SORT  1
#define INSERT_SORT 2
#define MERGE_SORT  3 
#define BUBBLE_SORT 4

enum sort_method{
 heap = 1,
 quick,
 insertion,
 merge,
 bubble
};

int main(int argc, char *argv[])
{
  int *array = NULL;
  int i, input, len;
  struct timeval start, end;
  int timeuse;
  enum sort_method method;

  if(argc == 1){
    printf("Please choose sorting method\n");
    printf("1: heap_sort\n");
    printf("2: quick_sort\n");
    printf("3: insertion_sort\n");
    printf("4: merge_sort\n");
    printf("5: bubble_sort\n");
    goto ERROR_CODE;
  }else if(argc == 2){
    printf("use default array!\n");
    method = atoi(argv[1]);
    if(method == 0){
      printf("invalid method\n");
      goto ERROR_CODE;
    }
    len = 1000;
    array = (int*)malloc(sizeof(int)*(len));
    input = 1001;
    for(i = 0; i < len; i++) {
      array[i] = input--;
    }
  }else {
    method = atoi(argv[1]);
    if(method == 0){
      printf("invalid method\n");
      goto ERROR_CODE;
    }
    len = argc - 2;
    array = (int*)malloc(sizeof(int)*len);
    if(array == NULL){
      printf("malloc array error!\n");
      goto ERROR_CODE;
    }
    for(i = 0; i < len; i++){
      input = atoi(argv[i+2]);
      if(input == 0){
        printf("input invalid!\n");
        goto ERROR_CODE;
      }
      array[i] = input;
    }
  }

  switch(method){
    case heap:
      printf("heap sorting:\n");
      gettimeofday(&start, NULL); 
      heep_sort(array, len);
      gettimeofday(&end, NULL); 
      timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
      printf("time consume %d us\n", timeuse);
      break;
    case quick:
      printf("quick sorting:\n");
      gettimeofday(&start, NULL); 
      quick_sort(array, len);
      gettimeofday(&end, NULL); 
      timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
      printf("time consume %d us\n", timeuse);
      break;
    case insertion:
      printf("insertion sorting:\n");
      gettimeofday(&start, NULL); 
      insertion_sort(array, len);
      gettimeofday(&end, NULL); 
      timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
      printf("time consume %d us\n", timeuse);
      break;
    case merge:
      printf("merge sorting:\n");
      gettimeofday(&start, NULL); 
      merge_sort(array, len);
      gettimeofday(&end, NULL); 
      timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
      printf("time consume %d us\n", timeuse);
      break;
    case bubble:
      printf("bubble sorting:\n");
      gettimeofday(&start, NULL); 
      bubble_sort(array, len);
      gettimeofday(&end, NULL); 
      timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
      printf("time consume %d us\n", timeuse);
      break;
    default:
      printf("No such method, please choose the right sorting method\n");
      printf("1: heap_sort\n");
      printf("2: quick_sort\n");
      printf("3: insertion_sort\n");
      printf("4: merge_sort\n");
      printf("5: bubble_sort\n");
  }

  if(argc > 2){
    printArray(array, len);
  }

ERROR_CODE:
  if(array != NULL)
    free(array);

  return 0;
}
