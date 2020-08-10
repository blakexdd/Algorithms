#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

void printArray(int *arr, int size);
void swap(int *a, int *b);
void insertionSort(int *arr, int size);
void mergeSort(int *arr, int p, int q);
void bubbleSort(int *arr, int size);
void merge(int *arr, int p, int q, int r);

int main( void ){
    int arr[8] = {23, 3, 34, 24, 7, 4, 3, 92};
    int arr_2[10] = {5, 3, 7, 5, 34, 2, 3, 1, 0, 9};
    int arr_2_size = sizeof(arr_2) / sizeof(arr_2[0]);
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Initial array: ");
    printArray(arr, arr_size);
    printArray(arr_2, arr_2_size);

    //insertionSort(arr, arr_size);
    //mergeSort(arr, 0, 7);
    bubbleSort(arr, arr_size);
    bubbleSort(arr_2, arr_2_size);

    printf("After sorting: ");
    printArray(arr, arr_size);
    printArray(arr_2, arr_2_size);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int size){
    int i;

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void insertionSort(int *arr, int size){
    int j, i;

    for (i = 1; i < size; i++)
        for (j = i - 1; j >= 0; j--)
            if (arr[j + 1] < arr[j])
                swap(&arr[j + 1], &arr[j]);
}

void merge(int *arr, int p, int q, int r){
    int n1 = q - p + 2, n2 = r - q + 1;
    int *L;
    int *R;
    int i, j, k;

    L = (int*)malloc(n1 * sizeof(int));
    R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1 - 1; i++)
        L[i] = arr[p + i];
    
    for (j = 0; j < n2 - 1; j++)
        R[j] = arr[q + j + 1];

    L[n1 - 1] = INT_MAX;
    R[n2 - 1] = INT_MAX;

    i = 0;
    j = 0;

    for (k = p; k <= r; k++)
        if (L[i] <= R[j])
            arr[k] = L[i], i++;
        else
            arr[k] = R[j], j++;       
}

void mergeSort(int *arr, int p, int r){
    if (p < r){
        int q = (r + p) / 2;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void bubbleSort(int *arr, int size){
    int i, j;

    for (i = 0; i < size; i++)
        for (j = size - 1; j > i; j--)
            if (arr[j] < arr[j - 1])
                swap(&arr[j], &arr[j - 1]);
}