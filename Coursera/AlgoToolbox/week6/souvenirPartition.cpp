//
// Created by vladimir on 27.08.2020.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    int sum = 0;

    cin >> n;
    vector<int> weights(n);

    for (int i = 0; i < n; i++){
        cin >> weights[i];
        sum += weights[i];
    }

    if (sum % 3 != 0)
        cout << 0;
    else{
        int target = sum / 3;
        vector<vector<int>> res(n + 1, vector<int>(target + 1));
        vector<int> usedNums(n);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= target; j++){
                res[i][j] = res[i - 1][j];

                if (weights[i - 1] <= j){
                    int possibleMax = res[i - 1][j - weights[i - 1]] + weights[i - 1];

                    if (possibleMax > res[i][j])
                        res[i][j] = possibleMax;
                }
            }

//        for (int i = 0; i < res.size(); i++){
//            for (int j = 0; j < res[i].size(); j++)
//                cout << res[i][j] << " ";
//            cout << endl;
//        }

        int first = res[n][target];

        for (int i = n, j = target; ;){
            if (i < 1 || j < 1)
                break;
            if (res[i][j] != res[i - 1][j]){
//                cout << " i: " << i << " weights: " << weights[i] << " ";
                usedNums[i - 1] = 1;
                j -= weights[i - 1];
                i--;
            }else{
                i--;
            }
        }

        vector<int> newWeights;

        for (int i = 0; i < usedNums.size(); i++){
            if (usedNums[i] == 0){
                newWeights.push_back(weights[i]);
            }
        }

        n = newWeights.size();
        vector<vector<int>> res1(n + 1, vector<int>(target * 2 + 1));
//
//
//        cout << "target: " << target << " first: " << first << endl;
//        for (int i = 0; i < usedNums.size(); i++)
//            cout << usedNums[i] << " ";
//        cout << endl;

//        cout << endl;
//        for (int i = 0; i < newWeights.size(); i++)
//            cout << newWeights[i] << " ";
//        cout << endl;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= target * 2; j++){
                res1[i][j] = res1[i - 1][j];

                if (newWeights[i - 1] <= j){
                    int possibleMax = res1[i - 1][j - newWeights[i - 1]] + newWeights[i - 1];

                    if (possibleMax > res1[i][j])
                        res1[i][j] = possibleMax;
                }
            }

//        cout << endl;
//
//        for (int i = 0; i < res1.size(); i++){
//            for (int j = 0; j < res1[i].size(); j++)
//                cout << res1[i][j] << " ";
//            cout << endl;
//        }

        int second = res1[n][target * 2];

        if (first == second / 2&& first == target && second / 2== target)
            cout << 1;
        else
            cout << 0;
    }

    return 0;
}
