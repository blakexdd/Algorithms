//
// Created by vladimir on 21.08.2020.
//
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int merge(vector<int> &arr, int p, int q, int r){
    int n1 = q - p + 2, n2 = r - q + 1;
    vector<int> L(n1);
    vector<int> R(n2);
    int invNum = 0;

    for (int i = 0; i < n1 - 1; i++)
        L[i] = arr[p + i];

    for (int i = 0; i < n2 - 1; i++)
        R[i] = arr[q + i + 1];

    L[n1 - 1] = INT_MAX;
    R[n2 - 1] = INT_MAX;

    for (int k = p, i = 0, j = 0; k <= r; k++){
        if (L[i] <= R[j])
            arr[k] = L[i], i++;
        else{
            if (L[i] != INT_MAX && R[j] != INT_MAX)
                invNum = invNum + L.size() - i - 1;
            arr[k] = R[j], j++;
        }
    }

    return invNum;
}

void mergeSort(vector<int> &arr, int p, int r, int &prevRes){
    if (p < r){
        int q = (r + p) / 2;

        mergeSort(arr, p, q, prevRes);
        mergeSort(arr, q + 1, r, prevRes);
        prevRes += merge(arr, p, q, r);
    }
}

int main(){
    int n;
    cin >> n;
    int res = 0;
    int &answer = res;

    vector<int> nums(n);

    for (int i = 0; i < nums.size(); i++)
        cin >> nums[i];

    mergeSort(nums, 0, nums.size() - 1,answer);

    cout << answer;
}
