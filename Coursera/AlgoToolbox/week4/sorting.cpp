#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

vector<int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  vector<int> left;
  vector<int> mid;
  vector<int> right;

//  std::cout << "X: " << x << "\n";
//
//  for (int i = 0; i < a.size(); i++)
//      std::cout << a[i];
//
//  std::cout << std::endl;

  for (int i = l; i <= r; i++) {
      if (a[i] < x)
          left.push_back(a[i]);
      else if (a[i] > x)
          right.push_back(a[i]);
      else
          mid.push_back(a[i]);
  }

  for (int i = l; i <= r; i++)
  {
      if (!left.empty())
      {
          a[i] = left[left.size() - 1];
          left.pop_back();
      }else if(!mid.empty()){
          a[i] = mid[mid.size() - 1];
          mid.pop_back();
      }else if (!right.empty()){
          a[i] = right[right.size() - 1];
          right.pop_back();
      }
  }

  swap(a[l], a[j]);

  int lPos = -1;
  int rPos = -1;

  for (int i = l; i <= r; i++)
      if (x == a[i] && lPos == -1)
          lPos = i;
      else if(x == a[i] && lPos != -1)
          rPos = i;

  if (rPos == -1)
      rPos = lPos;

//  std::cout << " lPos: " << lPos << " rPos: " << rPos << "\n";
//
//    for (int i = 0; i < a.size(); i++)
//        std::cout << a[i];
//
//    std::cout << std::endl;
  
  vector<int> res = {lPos, rPos};
  return res;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

//  std::cout << "l: " << l << " r: " << r << "\n";

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> res = partition2(a, l, r);

//  std::cout << "k: " << k << "\n";

  randomized_quick_sort(a, l, res[0] - 1);
  randomized_quick_sort(a, res[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
