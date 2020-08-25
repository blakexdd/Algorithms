//
// Created by vladimir on 23.08.2020.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ranges;
    vector<int> points;

    for (int i = 0; i < n; i++)
    {
        vector<int> left(2);
        cin >> left[0];
        left[1] = 0;
        vector<int> right(2);
        cin >> right[0];
        right[1] = 2;
        ranges.push_back(left);
        ranges.push_back(right);
    }

    for (int i = 0; i < m; i++){
        vector<int> point(3);
        int p;
        cin >> p;
        point[0] = p;
        point[1] = 1;
        point[2] = i;

        points.push_back(p);
        ranges.push_back(point);
    }

    sort(ranges.begin(), ranges.end(), [](vector<int> &a, vector<int> &b){
        if (a[0] == b[0] && a[1] < b[1])
            return true;
        else if (a[0] == b[0] && a[1] > b[1])
            return false;
        else
            return a[0] < b[0];
    });

    vector<int> coveredIdx(m);
    fill(coveredIdx.begin(), coveredIdx.end(), -1);

    vector<int> res(m);
    int intervalsNumber = 0;

    for (int i = 0; i < ranges.size(); i++) {
        if (ranges[i][1] == 0)
            intervalsNumber++;
        else if (ranges[i][1] == 2)
            intervalsNumber--;
        else if (ranges[i][1] == 1) {
            res[ranges[i][2]] = intervalsNumber;
        }
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}