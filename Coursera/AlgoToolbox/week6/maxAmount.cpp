//
// Created by vladimir on 27.08.2020.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int w, n;
    cin >> w >> n;
    vector<int> weights(n);
    vector<vector<int>> res(n + 1, vector<int>(w + 1));

    for (int i = 0; i < n; i++){
        cin >> weights[i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= w; j++){
            res[i][j] = res[i - 1][j];

            if (weights[i - 1] <= j){
                int possibleMax = res[i - 1][j - weights[i - 1]] + weights[i - 1];

                if (possibleMax > res[i][j])
                    res[i][j] = possibleMax;
            }
        }

//    for (int i = 0; i < res.size(); i++){
//        for (int j = 0; j < res[i].size(); j++)
//            cout << res[i][j] << " ";
//        cout << endl;
//    }

    cout << res[n][w];

    return 0;
}
