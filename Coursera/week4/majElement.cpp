#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int majorityElement(vector<long int> nums);

int main(){
    int n;

    cin >> n;
    vector<long int> nums(n);

    for (long int i = 0; i < n; i++)
        cin >> nums[i];

    cout << majorityElement(nums);
    return 0;
}

int majorityElement(vector<long int> nums){
    sort(nums.begin(), nums.end());

    long int threshold = nums.size() / 2;
    int maxSeq = 0;
    long int tempSeq = 1;

    for (int i = 1; i <= nums.size(); i++){
        if (nums[i] != nums[i - 1]){
            if (tempSeq > threshold)
            {
                maxSeq = 1;
                break;
            }
            else
            {
                tempSeq = 1;
            }
        }else{
            tempSeq++;
        }
    }

    return maxSeq;
}