#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <functional>
#include <queue>

using std::vector;
using std::pair;
using std::priority_queue;

auto cmp = [](vector<int> l, vector<int> r) { return l[0] < r[0]; };

void dfs(vector<vector<int> > adj1, priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> &postOrder,
         vector<bool> &visited, int x, int &c, int &cov){
    if (!visited[x]){
        visited[x] = true;
        cov++;

        for (int i = 0; i < adj1[x].size(); i++){
            if (!visited[adj1[x][i]]){
                c++;
                dfs(adj1, postOrder, visited, adj1[x][i], c, cov);
            }
        }

        vector<int> res = {++c, x};

        postOrder.push(res);
    }else{
        return;
    }
}

void dfs2(vector<vector<int> > adj, vector<bool> &used,
          int x, priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> &postOrder){
    if (!used[x]){
        used[x] = true;

        for (int i = 0; i < adj[x].size(); i++){
            if (!used[adj[x][i]]){
                dfs2(adj, used, adj[x][i], postOrder);
            }
        }
    }
    else
        return;
}

int number_of_strongly_connected_components(vector<vector<int> > adj, vector<vector<int> > adj1) {
  int result = 0;
  //write your code here
  vector<int> postOrder(adj1.size());
  vector<bool> visited(adj1.size());
  priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pOrder(cmp);
  int c = 1;
  int &cc = c;
  int covered = 0;
  int &cov = covered;

  for (int i = 0; i < adj1.size(); i++){
      if (adj1[i].size() == 0 && adj[i].size() == 0){
          result++;
          continue;
      }

      dfs(adj1, pOrder, visited, i, c, cov);
  }

  vector<bool> used(adj.size());

  while (!pOrder.empty()){
      while(used[pOrder.top()[1]] && !pOrder.empty()){
          pOrder.pop();
      }

      if (!pOrder.empty()){
          dfs2(adj, used, pOrder.top()[1], pOrder);
          pOrder.pop();
          result++;
      }
  }

  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > adj1(n, vector<int>());

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj1[y - 1].push_back(x - 1);
  }
  std::cout << number_of_strongly_connected_components(adj, adj1);
}
