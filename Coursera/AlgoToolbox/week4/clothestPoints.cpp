//
// Created by vladimir on 26.08.2020.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findCrossDistance(vector<vector<int>> points, int l, int m, int r){

}

int findDistance(vector<vector<int>> points, int l, int r){
    if (l <= r){

    }
}

int main(){
    int n;

    cin >> n;
    vector<vector<int>> points(n);

    for (int i = 0; i < n; i++){
        vector<int> point(2);
        cin >> point[0] >> point[1];
        points[i] = point;
    }

    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
       return a[0] < b[0];
    });

    for (int i = 0; i < points.size(); i++){
        for (int j = 0; j < points[i].size(); j++)
            cout << points[i][j] << " ";
        cout << endl;
    }

    return 0;
}