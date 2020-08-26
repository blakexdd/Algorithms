//
// Created by vladimir on 26.08.2020.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n;
    vector<int> arr1(n);

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    cin >> m;
    vector<int> arr2(m);

    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    cin >> k;
    vector<int> arr3(k);

    for (int i = 0; i < k; i++)
        cin >> arr3[i];

    vector<vector<vector<int>>> res(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1)));

    for (int i = 0; i <= n; i++)
        res[i][0][0];

    for (int i = 0; i <= m; i++)
        res[0][i][0];

    for (int i = 0; i <= k; i++)
        res[0][0][i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int h = 1; h <= k; h++){
                int tempRes;

                if (arr1[i - 1] == arr2[j - 1] && arr1[i - 1] == arr3[h - 1]
                    && arr2[j - 1] == arr3[h - 1])
                    tempRes = res[i - 1][j - 1][h - 1] + 1;
                else
                    tempRes = max(res[i - 1][j][h], max(res[i][j - 1][h], res[i][j][h - 1]));

                res[i][j][h] = tempRes;
            }

    cout << res[n][m][k];
}