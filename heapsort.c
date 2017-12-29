#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 11

int * Array_Random(int length) {
    srand((unsigned)time(NULL));
    int i;
    int * arr = NULL;
    arr = (int *)malloc(length*(sizeof(int)));
    for(i = 0; i < length; i++){
        *(arr + i) = rand()%100;
    }
    return arr;   
}

void exchange(int * a, int * b) {
    int tmp;
    tmp = * a;
    * a = * b;
    * b = tmp;
}

void showheap(int * arr){
    printf("                 1:%d\n",arr[1]);
    printf("         2:%d              3:%d \n",arr[2],arr[3]);
    printf("  4:%d        5:%d      6:%d     7:%d \n",arr[4],arr[5],arr[6],arr[7]);    
    printf("8:%d 9:%d 10:%d\n",arr[8],arr[9],arr[10]);
    printf("-----------------------------------\n");
}

void MAX_HEAPIFY(int * arr, int i, int length) {
    int l = 2*i;
    int r = 2*i + 1;
    int largest;
    if ((l <= length)&&( *(arr+l) > *(arr+i) )) {
        largest = l;
    } else largest = i;

    if ((r <= length)&&( *(arr+r) > *(arr+largest) )) {
        largest = r;
    }  
    if (largest != i) {
        exchange((arr + i),(arr + largest));
        //printf("exchange %d = %d with %d = %d",);
        //showheap(arr);
        MAX_HEAPIFY(arr, largest, length);
    }
}

void BUILD_MAX_HEAP(int * arr, int length) {
    int i;
    for (i = length/2; i > 0; i--) {
        MAX_HEAPIFY(arr, i, length);    
    }
}

void HEAPSORT(int * arr, int length) {
    BUILD_MAX_HEAP(arr,length);
    int j;
    for(j = length; j > 1; j--) {
        exchange((arr + 1), (arr + j));
        length = length - 1;
        MAX_HEAPIFY(arr, 1, length);     
    }
}

int main() {
    int *arr = Array_Random(len);
    //int arr[11] = {0,16,14,10,8,7,9,3,2,4,1};
    showheap(arr);
    HEAPSORT(arr,(len-1));
    showheap(arr);

    return 0;
}
