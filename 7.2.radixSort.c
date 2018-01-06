#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 11
#define k 1000

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

int tensPlace(int num) {
    int h = ((num-num%10)%100)/10;
    return h;
}
int hundredsPlace(int num) {
    int h = num/100;
    return h;
}

void showheap(int * arr){
    printf("                 1:%d\n",arr[1]);
    printf("         2:%d              3:%d \n",arr[2],arr[3]);
    printf("  4:%d        5:%d      6:%d     7:%d \n",arr[4],arr[5],arr[6],arr[7]);    
    printf("8:%d 9:%d 10:%d\n",arr[8],arr[9],arr[10]);
    printf("-----------------------------------\n");
}

int * COUNTING_SORT_P(int * arr_A, int len_, int k_, int place) {
    int * arr_B = Array_Empty(len_);
    int * arr_C = Array_Empty(k_+1);
    int * arr_A_P = Array_Empty(len_);
    int i,j;
    if (place == 1) {
        for (j = 1; j <= (len_-1); j++) {
            arr_A_P[j] = arr_A[j]%10;
        }
    } else if (place == 2) {       
        for (j = 1; j <= (len-1); j++) {
          arr_A_P[j] = tensPlace(arr_A[j]);
        }
    } else {
        for (j = 1; j <= (len-1); j++) {
          arr_A_P[j] = hundredsPlace(arr_A[j]);
        }
    }
    
    for (j = 1; j <= (len_-1); j++) {
        arr_C[arr_A_P[j]] += 1;
    }

    for (i = 1; i <= k_; i++) {
        arr_C[i] += arr_C[i-1];
    }

    for (j = (len_-1); j >= 1; j--) {
        arr_B[arr_C[arr_A_P[j]]] = arr_A[j];
        arr_C[arr_A_P[j]] = arr_C[arr_A_P[j]] - 1;
    }
    free(arr_C);
    free(arr_A_P);
    return arr_B;
}

int * RADIX_SORT(int * arr ) {
    int * arr_B1 = Array_Empty(len);
    int * arr_B2 = Array_Empty(len);
    int * arr_B3 = Array_Empty(len);
       
    arr_B1 = COUNTING_SORT_P(arr_A, len, k, 1);
    showheap(arr_B1);
    arr_B2 = COUNTING_SORT_P(arr_B1, len, k, 2);
    showheap(arr_B2);
    arr_B3 = COUNTING_SORT_P(arr_B1, len, k, 3);
    showheap(arr_B3);

    free(arr_B1);
    free(arr_B2);
    free(arr_B3);
}

int main() {
    int * arr_A = Array_Random(len);
    showheap(arr_A);

    
    free(arr_A);
    

    return 0;
}
