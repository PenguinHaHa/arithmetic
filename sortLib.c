//sort library
// "sortLib.c"
#include "sortLib.h"
#include "commonLib.h"

// for heap sort
#define PARENT(i)       (i>>1)
#define LEFT_CHILD(i)   (2*i)
#define RIGHT_CHILD(i)  (2*i+1)

void insertion_sort(int *array, int length)
{
  int i, j;
  int data;

  for(i = 1; i < length; i++){
    data = array[i];
    for(j = i-1; j >= 0; j--){
      if(array[j] > data){
        array[j+1] = array[j];
        if(j == 0) 
          array[j] = data;
      }else{
        array[j+1] = data;
        break;
      }
    }
  }
}

void merge(int *array, int head, int mid, int tail)
{

  int ret[tail-head+1];
  int *Larray = array + head;
  int *Rarray = array + mid + 1;
  int Llen = 0;
  int Rlen = 0;
  int i;

  for(i = 0; i < (tail - head + 1); i++){
    if(Llen == (mid - head + 1)){
      ret[i] = Rarray[Rlen];
      Rlen++;
      continue;
    }
    if(Rlen == (tail - mid)){
      ret[i] = Larray[Llen];
      Llen++;
      continue;
    }
    if(Larray[Llen] < Rarray[Rlen]){
      ret[i] = Larray[Llen];
      Llen++;
    }else{
      ret[i] = Rarray[Rlen];
      Rlen++;
    }
  }

  array += head;
  for(i = 0; i < (tail - head + 1); i++){
     *array = ret[i];
     array++;
  }
  
}

void _merge_sort(int *array, int head, int tail)
{
  int mid;

  if(head < tail){
    mid = (tail - head)/2;
    mid += head;
    _merge_sort(array, head, mid);
    _merge_sort(array, mid+1, tail);
    merge(array, head, mid, tail);
  }

}

void merge_sort(int *array, int length)
{
  _merge_sort(array, 0, length-1);
}

void bubble_sort(int *array, int length)
{
	int i, j;

  for(i = 0; i < length; i++){
    for(j = (length-1); j > i; j--){
      if(array[j] < array[j-1]){
          exchange(&array[j], &array[j-1]);
      }
    }
  }
}

int partition(int *array, int head, int tail)
{
  int i,j;
  int mid_value;
  mid_value = array[tail];

  for(i = head, j = head-1; i < tail-head; i++){
    if(array[i] < mid_value){
      j++;
      exchange(&array[i], &array[j]);
    }
  }

  exchange(&array[tail], &array[j+1]);

  return j+1;
}

void _quick_sort(int *array, int head, int tail)
{
  int mid;

  if(head < tail){
    mid = partition(array, head, tail);
    _quick_sort(array, head, mid-1);
    _quick_sort(array, mid+1, tail);
  }
}

void quick_sort(int *array, int length)
{
  _quick_sort(array, 0, length-1);
}


void max_heapify(int *array, int top, int length)
{
  int left, right;
  int largest;

  left = LEFT_CHILD(top);
  right = RIGHT_CHILD(top);

  if((left <= length) && (array[left-1] > array[top-1])){
    largest = left;
  } else {
    largest = top;
  }
  if((right <= length) && (array[right-1] > array[largest-1])){
    largest = right;
  }

  if(largest != top) {
    exchange(&array[top-1], &array[largest-1]);
    max_heapify(array, largest, length); 
  }

}

void build_max_heap(int *array, int length)
{
  int i; 
  for (i = (length>>1); i > 0; i--) {
    max_heapify(array, i, length);
  }
}

void heep_sort(int *array, int length)
{
  int i;

  build_max_heap(array, length);
  for (i = length; i > 1; i--) {
    exchange(&array[0], &array[length-1]);
    length--;
    max_heapify(array, 1, length);
  }
}
