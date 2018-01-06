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

int PARTITION(int *arr, int p, int r) {
    int x = arr[r];
    int i = p - 1;
    int j = p;
    for (;j <= r - 1; j++) {
        if (arr[j] <= x) {
            i = i + 1;
            exchange((arr+i), (arr+j));
        }
    }
    exchange((arr+i+1), (arr+r));
    return (i + 1);
}

void TAIL_RECURSIVE_QUICKSORT(int * arr, int p, int r) {
	int q;
	for (;p < r; p = q + 1) {
		q = PARTITION(arr, p, r);
		TAIL_RECURSIVE_QUICKSORT(arr, p, q-1);
	}
}

void QUICKSORT(int* arr, int p, int r) {
    if (p < r) {
        int q;
        q = PARTITION(arr, p, r);
        QUICKSORT(arr, p, q-1);
        QUICKSORT(arr, q + 1, r);
    }
}

int main() {
    int *arr = Array_Random(len);
    //int arr[11] = {0,16,14,10,8,7,9,3,2,4,1};
    showheap(arr);
    TAIL_RECURSIVE_QUICKSORT(arr,1, len-1);
    //QUICKSORT(arr, 1, len-1);
    showheap(arr);
    free(arr);

    return 0;
}
