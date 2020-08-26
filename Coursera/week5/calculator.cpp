//
// Created by vladimir on 26.08.2020.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    int n;

    cin >> n;
    vector<int> res(n + 1);
    res.push_back(n);
    res[1] = 0;

    for (int i = 2; i <= n; i++){
        int div2 = INT_MAX, div3 = INT_MAX;

        if (i % 2 == 0)
            div2 = res[i / 2];

        if (i % 3 == 0)
            div3 = res[i / 3];

        res[i] = min(res[i - 1], min(div2, div3)) + 1;
    }


    cout << res[n] << "\n";

    vector<int> newRes;
    newRes.push_back(n);
    int currentSteps = res[n];
    for (int i = n; i >= 2;){
        int num;

        if (i % 3 == 0 && res[i / 3] == currentSteps - 1)
            num = i / 3;
        else if (i % 2 == 0 && res[i / 2] == currentSteps - 1)
            num = i / 2;
        else
            num = i - 1;

        i = num;
        currentSteps--;
        newRes.push_back(num);
    }

    sort(newRes.begin(), newRes.end());

    for (int i = 0; i < newRes.size(); i++)
        cout << newRes[i] << " ";

    return 0;
}