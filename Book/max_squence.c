#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

void findMaxCrossingSubarray(int *arr, int low, int mid, int high, int* result);
void findMaximumSubarray(int *arr, int low, int high, int* result);
void printArray(int *arr, int size);

void main( void ){
    int arr[] = {1, -2, 3};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int result[] = {0, 0, 0};

    printArray(arr, arr_size);

    findMaximumSubarray(arr, 0, arr_size, result);

    printArray(result, 3);
}

void printArray(int *arr, int size){
    int i;

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void findMaxCrossingSubarray(int *arr, int low, int mid, int high, int * result){
    int left_sum = -INT_MAX;
    int right_sum = -INT_MAX;
    int sum;
    int i, j;
    int max_left, max_right;

    for (i = mid, sum = 0; i >= low; i--){
        sum += arr[i];

        if (sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    for (j = mid + 1, sum = 0; j < high; j++){
        sum += arr[j];

        if (sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }

    result[0] = max_left;
    result[1] = max_right;
    result[2] = right_sum + left_sum;
}

void findMaximumSubarray(int *arr, int low, int high, int* result){
    int mid;
    int left_result[3] = {};
    int right_result[3] = {};
    int cross_result[3] = {};

    if (high == low){
        result[0] = low;
        result[1] = high;
        result[2] = arr[low];
    }else{
        mid = (low + high) / 2;
        findMaximumSubarray(arr, low, mid, left_result);
        findMaximumSubarray(arr, mid, high, right_result);
        findMaxCrossingSubarray(arr, low, mid, high, cross_result);

        if (left_result[2] > right_result[2] && left_result[2] > cross_result[2])
            result = left_result;
        else if (right_result[2] > left_result[2] && right_result[2] > cross_result[2])
            result = right_result;
        else
            result = cross_result;
    }
}