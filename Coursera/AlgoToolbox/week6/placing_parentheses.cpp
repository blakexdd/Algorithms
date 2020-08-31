#include <iostream>
#include <cassert>
#include <string>
#include <climits>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void minAndMax(int i, int j, vector<vector<long long>> m, vector<vector<long long>> M){
    long long  min = INT64_MAX;
    long long max = INT64_MIN;

    for (int k = i; k < j; k++){
        long long a = eval(M[i][k], )
    }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  int numsCount = exp.size() / 2 + 1;
  vector<vector<long long>> m(numsCount, vector<long long>(numsCount));
  vector<vector<long long>> M(numsCount, vector<long long>(numsCount));

  for (int i = 0, j = 0; i < numsCount; i++){
      m[i][i] = int(exp[j]) - 48;
      M[i][i] = int(exp[j]) - 48;
      j += 2;
  }

  for (int s = 0; s < numsCount; s++)
      for (int i = 0; i < numsCount - s; i++){
          int j = i + s;
          minAndMax(i, j);
      }

//  std::cout << "\n";
//
//  for (int i = 0; i < M.size(); i++){
//        for (int j = 0; j < M[i].size(); j++)
//            std::cout << M[i][j] << " ";
//        std::cout << std::endl;
//    }

  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
