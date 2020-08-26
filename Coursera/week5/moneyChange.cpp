//
// Created by vladimir on 26.08.2020.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> res(n + 1);

    res[0] = 0;
    res[1] = 1;
    res[2] = 1;
    res[3] = 1;

    for (int i = 4; i <= n; i++){
        res[i] = min(res[i - 1], min(res[i - 3], res[i - 4])) + 1;
    }

    if (n < 3)
        cout << res[n] + n - 1;
    else
        cout << res[n];

    return 0;
}

