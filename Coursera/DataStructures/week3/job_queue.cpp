#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;

class JobQueue {
 private:
  int num_workers_;
  int available_workers;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    auto cmp = [](vector<long long> left, vector<long long> right) {
        if (left[1] == right[1]){
            return left[0] > right[0];
        }else
            return left[1] > right[1];

    };
    priority_queue <vector<long long>, vector<vector<long long>>, decltype(cmp)> workers_queue(cmp);

    available_workers = num_workers_;

    for (int i = 0; i < jobs_.size(); i++){
        int duration = jobs_[i];

        if (available_workers > 0){
            int worker = num_workers_ - available_workers;

            vector<long long> process = {num_workers_ - available_workers, duration};
            workers_queue.push(process);
            std::cout << worker << " " << 0 << "\n";
            available_workers--;
        }else{
            vector<long long> worker = workers_queue.top();
            workers_queue.pop();
            vector<long long> process = {worker[0], duration + worker[1]};
            workers_queue.push(process);
            std::cout << worker[0] << " " << worker[1] << "\n";
        }
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
