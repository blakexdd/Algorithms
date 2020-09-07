#include <iostream>
#include <vector>
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
      while (elemIdx < data_.size()){
          int left_child = elemIdx * 2 + 1;
          int right_child = elemIdx * 2 + 2;
          if (left_child < data_.size() && right_child < data_.size()){
              if (data_[elemIdx] < data_[right_child] && data_[elemIdx] > data_[left_child]){
                  swap(data_[elemIdx], data_[left_child]);
                  swaps_.push_back(make_pair(elemIdx, left_child));
                  elemIdx = left_child;
              }else if (data_[elemIdx] > data_[right_child] && data_[elemIdx] < data_[left_child]){
                  swap(data_[elemIdx], data_[right_child]);
                  swaps_.push_back(make_pair(elemIdx, right_child));
                  elemIdx = left_child;
              }else{
                  if (data_[left_child] > data_[right_child]){
                      swap(data_[elemIdx], data_[right_child]);
                      swaps_.push_back(make_pair(elemIdx, right_child));
                      elemIdx = right_child;
                  }else{
                      swap(data_[elemIdx], data_[left_child]);
                      swaps_.push_back(make_pair(elemIdx, left_child));
                      elemIdx = left_child;
                  }
              }
          }else if (left_child < data_.size() && right_child >= data_.size()){
              if (data_[elemIdx] > data_[left_child]){
                  swap(data_[elemIdx], data_[left_child]);
                  swaps_.push_back(make_pair(elemIdx, left_child));
                  elemIdx = left_child;
              }
          }else if (left_child >= data_.size() && right_child < data_.size()){
              if (data_[elemIdx] > data_[right_child]){
                  swap(data_[elemIdx], data_[right_child]);
                  swaps_.push_back(make_pair(elemIdx, right_child));
                  elemIdx = right_child;
              }
          }else{
              break;
          }
      }
  }

  void GenerateSwaps() {
    swaps_.clear();
    for (int i = data_.size() - 1; i > 1;){
        int parent = (i - 1) / 2;
        int left_child = i - 1;
        int right_child = i;
        int swappedIdx = - 1;

        if (i == data_.size() - 1 && i % 2 != 0){
            if (data_[parent] > data_[right_child]){
                swap(data_[parent], data_[right_child]);
                swaps_.push_back(make_pair(parent, right_child));
                i--;
                continue;
            }
        }
        else if (data_[parent] < data_[left_child] && data_[parent] > data_[right_child]){
            swap(data_[parent], data_[right_child]);
            swaps_.push_back(make_pair(parent, right_child));
            swappedIdx = right_child;
        }else if (data_[parent] > data_[left_child] && data_[parent] < data_[right_child]){
            swap(data_[parent], data_[left_child]);
            swaps_.push_back(make_pair(parent, left_child));
            swappedIdx = left_child;
        }else if (data_[parent] > data_[left_child] && data_[parent] > data_[right_child]){
            if (data_[left_child] > data_[right_child]){
                swap(data_[parent], data_[right_child]);
                swaps_.push_back(make_pair(parent, right_child));
                swappedIdx = right_child;
            }else{
                swap(data_[parent], data_[left_child]);
                swaps_.push_back(make_pair(parent, left_child));
                swappedIdx = left_child;
            }
        }

        siftDown(swappedIdx);
        i -= 2;
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
