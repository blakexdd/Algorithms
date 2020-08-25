#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for (int k = 0; k < nums.size(); k++){
            vector<int> tempRes;
            int target = nums[k];
            
            for (int i = k + 1; k < nums.size(); i++){
                if (tempRes.size() == 3){
                    res.push_back(tempRes);
                    tempRes.clear();
                }
                int x = nums[i];
                int wantedY = -(x + target);
                
                if (binary_search(nums.begin(), nums.end(), wantedY)){
                    tempRes.push_back(target);
                    tempRes.push_back(x);
                    tempRes.push_back(wantedY);
                }
            }
        }
    
    return res;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res;

    res = threeSum(nums);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        
        cout << endl;
    }
}