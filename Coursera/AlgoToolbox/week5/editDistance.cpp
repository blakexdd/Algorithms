//
// Created by vladimir on 26.08.2020.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    vector<vector<int>> table(s1.size() + 1, vector<int>(s2.size() + 1));

    for (int i = 1; i <= s1.size(); i++){
        table[i][0] = table[i - 1][0] + 1;
    }

    for (int i = 1; i <= s2.size(); i++){
        table[0][i] = table[0][i - 1] + 1;
    }

    for (int i = 1; i < table.size(); i++){
        for (int j = 1; j < table[i].size(); j++){
            int minTrans;

            if (s1[i - 1] == s2[j - 1])
                minTrans = min(table[i - 1][j] + 1, min(table[i][j - 1] + 1, table[i - 1][j - 1]));
            else
                minTrans = min(table[i - 1][j] + 1, min(table[i][j - 1] + 1, table[i - 1][j - 1] + 1));

            table[i][j] = minTrans;
        }
    }

//    for (int i = 0; i < table.size(); i++){
//        for (int j = 0; j < table[i].size(); j++)
//            cout << table[i][j] << " ";
//        cout << endl;
//    }
    cout << table[table.size() - 1][table[0].size() - 1];

    return 0;
}

