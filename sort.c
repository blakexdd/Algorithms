#include <stdio.h>
#include <limits.h>
#include <math.h>

void printArray(int *arr, int size);
void swap(int *a, int *b);
void insertionSort(int *arr, int size);
void mergeSort(int *arr, int p, int q);
void merge(int *arr, int p, int q, int r);

int main( void ){
    int arr[10] = {19, 2, 34, 45, 34, 93, 84, 47, 25, 4};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Initial array: ");
    printArray(arr, arr_size);

    //insertionSort(arr, arr_size);
    mergeSort(arr, 0, 9);

    printf("After insertion sort: ");
    printArray(arr, arr_size);
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
    int L[n1], R[n2];
    int i, j, k;

    for (i = 0; i < n1; i++)
        L[i] = arr[p + i - 1];
    
    for (j = 0; j < n2; j++)
        R[j] = arr[q + j];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    printArray(R, n2);
    printArray(L, n1);

    for (k = p; k < r; k++)
        if (L[i] <= R[j])
            arr[k] = L[i], i++;
        else
            arr[k] = R[j], j++;       
}

void mergeSort(int *arr, int p, int r){
    if (p < r){
        int q = (r + p) / 2;
        printf("P: %d Q: %d R: %d\n", p, q, r);
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

