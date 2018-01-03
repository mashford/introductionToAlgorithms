#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 11
#define k 7

int * Array_Random(int length) {
    srand((unsigned)time(NULL));
    int i;
    int * arr = NULL;
    arr = (int *)malloc(length*(sizeof(int)));
    for(i = 0; i < length; i++){
        *(arr + i) = rand()%k;
    }
    return arr;   
}

int * Array_Empty(int length) {
	int i;
	int * arr = NULL;
	arr = (int *)malloc(length*(sizeof(int)));
	for(i = 0; i < length; i++){
        *(arr + i) = 0;
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


int main() {
    int * arr_A = Array_Random(len);
    int * arr_B = Array_Empty(len);
    int * arr_C = Array_Empty(k+1);
    int i,j;
    //int arr[11] = {0,16,14,10,8,7,9,3,2,4,1};
    showheap(arr_A);
    
    for (j = 1; j <= len; j++) {
        *(arr_C + *(arr_A + j)) += 1;
    }

    for (i = 1; i <= k; i++) {
    	arr_C[i] += arr_C[i-1];
    }
    j = len;
    for (j = len; j >= 1; j--) {
    	arr_B[arr_C[arr_A[j]]] = arr_A[j];
    	arr_C[arr_A[j]] = arr_C[arr_A[j]] - 1;
    }

    showheap(arr_B);
    free(arr_A);
    free(arr_B);
    free(arr_A);
    return 0;
}
