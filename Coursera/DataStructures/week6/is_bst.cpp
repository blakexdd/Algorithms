#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  long long key;
  long long left;
  long long right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, long long left_, long long right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree, long long idx, long long min, long long max) {
  // Implement correct algorithm here

  if (tree.size() == 0 && idx == 0)
      return true;

  if (idx == -1)
      return true;

  if (tree[idx].key < min || tree[idx].key > max)
      return false;

  return
     IsBinarySearchTree(tree, tree[idx].left, min, tree[idx].key - 1) &&
      IsBinarySearchTree(tree, tree[idx].right, tree[idx].key, max);
}

int main() {
  long long nodes;
  cin >> nodes;
  vector<Node> tree;
  for (long long i = 0; i < nodes; ++i) {
    long long key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree, 0, INT32_MIN, INT32_MAX)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
