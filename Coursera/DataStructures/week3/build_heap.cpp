#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void siftDown(int elemIdx){
      int leftChildIdx = elemIdx * 2 + 1;
      int rightChildIdx = elemIdx * 2 + 2;
      int leftChild, rightChild;

      if (elemIdx >= data_.size())
          return;

      if (leftChildIdx >= data_.size())
          leftChild = INT32_MAX;
      else
          leftChild = data_[leftChildIdx];

      if (rightChildIdx >= data_.size())
          rightChild = INT32_MAX;
      else
          rightChild = data_[rightChildIdx];

      if (leftChild >= data_[elemIdx] && leftChild >= data_[elemIdx]){
          return;
      }else if (leftChild < data_[elemIdx] && rightChild >= data_[elemIdx]){
          swap(data_[elemIdx], data_[leftChildIdx]);
          swaps_.push_back(make_pair(elemIdx, leftChildIdx));
          siftDown(leftChildIdx);
      }else if (leftChild >= data_[elemIdx] && rightChild < data_[elemIdx]){
          swap(data_[elemIdx], data_[rightChildIdx]);
          swaps_.push_back(make_pair(elemIdx, rightChildIdx));
          siftDown(rightChildIdx);
      }else if (leftChild < data_[elemIdx] && leftChild < data_[elemIdx]){
          if (leftChild < rightChild){
              swap(data_[elemIdx], data_[leftChildIdx]);
              swaps_.push_back(make_pair(elemIdx, leftChildIdx));
              siftDown(leftChildIdx);
          }else{
              swap(data_[elemIdx], data_[rightChildIdx]);
              swaps_.push_back(make_pair(elemIdx, rightChildIdx));
              siftDown(rightChildIdx);
          }
      }
  }

  void GenerateSwapsNaive(){
      swaps_.clear();
      for (int i = 0; i < data_.size(); ++i)
          for (int j = i + 1; j < data_.size(); ++j) {
              if (data_[i] > data_[j]) {
                  swap(data_[i], data_[j]);
                  swaps_.push_back(make_pair(i, j));
              }
          }
  }

  void GenerateSwaps() {
    swaps_.clear();
    for (int i = data_.size() - 1; i >= 0; i--){
        int swappedIdx = -1;
        int leftChildIdx = i * 2 + 1;
        int rightChildIdx = i * 2 + 2;
        int leftChild, rightChild;

        if (leftChildIdx >= data_.size())
            leftChild = INT32_MAX;
        else
            leftChild = data_[leftChildIdx];

        if (rightChildIdx >= data_.size())
            rightChild = INT32_MAX;
        else
            rightChild = data_[rightChildIdx];

        if (leftChild >= data_[i] && leftChild >= data_[i]){
            continue;
        }else if (leftChild < data_[i] && rightChild >= data_[i]){
            swap(data_[i], data_[leftChildIdx]);
            swaps_.push_back(make_pair(i, leftChildIdx));
            swappedIdx = leftChildIdx;
        }else if (leftChild >= data_[i] && rightChild < data_[i]){
            swap(data_[i], data_[rightChildIdx]);
            swaps_.push_back(make_pair(i, rightChildIdx));
            swappedIdx = rightChildIdx;
        }else if (leftChild < data_[i] && leftChild < data_[i]){
            if (leftChild < rightChild){
                swap(data_[i], data_[leftChildIdx]);
                swaps_.push_back(make_pair(i, leftChildIdx));
                swappedIdx = leftChildIdx;
            }else{
                swap(data_[i], data_[rightChildIdx]);
                swaps_.push_back(make_pair(i, rightChildIdx));
                swappedIdx = rightChildIdx;
            }
        }

        if (swappedIdx != -1)
            siftDown(swappedIdx);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
