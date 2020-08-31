//
// Created by vladimir on 26.08.2020.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<int> arr1(n);

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    cin >> m;
    vector<int> arr2(m);

    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    vector<vector<int>> res(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
        res[i][0] = 0;

    for (int i = 0; i <= m ; i++)
        res[0][i] = 0;

    for (int i = 1; i < res.size(); i++){
        for (int j = 1; j < res[i].size(); j++){
            int tempRes;

            if (arr1[i - 1] == arr2[j - 1])
                tempRes = res[i - 1][j - 1] + 1;
            else
                tempRes = max(res[i - 1][j], res[i][j - 1]);

            res[i][j] = tempRes;
        }
    }

//    for (int i = 0; i < res.size(); i++){
//        for (int j = 0; j < res[i].size(); j++)
//            cout << res[i][j] << " ";
//        cout << endl;
//    }

    cout << res[n][m];

    return 0;
}

